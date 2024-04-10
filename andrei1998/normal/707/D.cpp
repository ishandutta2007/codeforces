#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 1005;
const int QMAX = 100005;

struct DataStructure {
    bool *existent[NMAX];
    int sums_existent[NMAX];
    bool *inexistent[NMAX];
    int sums_inexistent[NMAX];
    int sum;

    void create(int n, int m) {
        sum = 0;
        for (int i = 1; i <= n; ++ i) {
            existent[i] = new bool[m + 1];
            inexistent[i] = new bool[m + 1];
            sums_existent[i] = 0;
            sums_inexistent[i] = m;

            for (int j = 1; j <= m; ++ j) {
                existent[i][j] = false;
                inexistent[i][j] = true;
            }
        }
    }

    bool reverse(int lin) {
        sum += (sums_inexistent[lin] - sums_existent[lin]);
        swap(existent[lin], inexistent[lin]);
        swap(sums_existent[lin], sums_inexistent[lin]);
        return true;
    }

    bool set_value(int lin, int col, int val) {
        if (existent[lin][col] != val) {
            existent[lin][col] = val;
            inexistent[lin][col] = (val ^ 1);
            sums_existent[lin] += (val - (val ^ 1));
            sum += (val - (val ^ 1));
            sums_inexistent[lin] += ((val ^ 1) - val);
            return true;
        }
        else
            return false;
    }
};

struct Update {
    int type;
    int i, j;
};

int nodes;
Update maker_update[QMAX];

vector <int> tree[QMAX];

DataStructure emp;

int which_node[QMAX];
vector <int> moments_here[QMAX];

int anss[QMAX];

void dfs(int node) {
    int i = maker_update[node].i;
    int j = maker_update[node].j;

    bool to_do = false;
    if (maker_update[node].type == 1)
        to_do = emp.set_value(i, j, 1);
    else if (maker_update[node].type == 2)
        to_do = emp.set_value(i, j, 0);
    else if (maker_update[node].type == 3)
        to_do = emp.reverse(i);

    for (auto it: moments_here[node])
        anss[it] = emp.sum;

    for (auto it: tree[node])
        dfs(it);

    if (to_do) {
        if (maker_update[node].type == 1)
            emp.set_value(i, j, 0);
        else if (maker_update[node].type == 2)
            emp.set_value(i, j, 1);
        else if (maker_update[node].type == 3)
        emp.reverse(i);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    emp.create(n, m);

    int type, a, b;
    int node;
    for (int i = 1; i <= q; ++ i) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            node = which_node[i - 1];

            tree[node].push_back(++ nodes);
            maker_update[nodes].type = 1;
            maker_update[nodes].i = a;
            maker_update[nodes].j = b;
            node = nodes;
        }
        else if (type == 2) {
            cin >> a >> b;
            node = which_node[i - 1];

            tree[node].push_back(++ nodes);
            maker_update[nodes].type = 2;
            maker_update[nodes].i = a;
            maker_update[nodes].j = b;
            node = nodes;
        }
        else if (type == 3) {
            cin >> a;
            node = which_node[i - 1];

            tree[node].push_back(++ nodes);
            maker_update[nodes].type = 3;
            maker_update[nodes].i = a;
            node = nodes;
        }
        else if (type == 4) {
            cin >> a;
            node = which_node[a];
        }

        which_node[i] = node;
        moments_here[node].push_back(i);
    }

    dfs(0);

    for (int i = 1; i <= q; ++ i)
        cout << anss[i] << '\n';

    return 0;
}