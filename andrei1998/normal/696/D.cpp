#include <bits/stdc++.h>

#define lint long long int
using namespace std;

const int NMAX = 205;

int n;
int w[2 * NMAX];
string strings[2 * NMAX];

struct Node {
    int lit;
    int father;

    int fail;
    int pondre;
    int alf[26];
} nodes[2 * NMAX];

int sz;
int new_node(int father = -1, int lit = -1) {
    nodes[sz].father = father;
    nodes[sz].lit = lit;
    memset(nodes[sz].alf, -1, sizeof(nodes[sz].alf));
    return sz ++;
}

void init() {
    new_node(); //root
}

void add(int index) {
    int node = 0;
    for (auto it: strings[index]) {
        if (nodes[node].alf[it - 'a'] == -1)
            nodes[node].alf[it - 'a'] = new_node(node, it - 'a');
        node = nodes[node].alf[it - 'a'];
    }

    nodes[node].pondre += w[index];
}

void build_fails() {
    queue <int> _queue;
    _queue.push(0);

    int node;
    while (!_queue.empty()) {
        node = _queue.front();
        _queue.pop();

        if (nodes[node].father > 0) {
            //nodes[node].fail edge
            int k = nodes[nodes[node].father].fail;
            while (k && nodes[k].alf[nodes[node].lit] == -1)
                k = nodes[k].fail;

            if (nodes[k].alf[nodes[node].lit] != -1)
                k = nodes[k].alf[nodes[node].lit];
            nodes[node].fail = k;

            nodes[node].pondre += nodes[nodes[node].fail].pondre;
        }

        //Tranzitions
        for (int i = 0; i < 26; ++ i)
            if (nodes[node].alf[i] != -1)
                _queue.push(nodes[node].alf[i]);
            else {
                int k = nodes[node].fail;
                while (k && nodes[k].alf[i] == -1)
                    k = nodes[k].fail;

                if (nodes[k].alf[i] != -1)
                    k = nodes[k].alf[i];
                nodes[node].alf[i] = k;
            }
    }
}

//RAMANE DE VAZUT
const lint INF = 40005 * 100000000000000LL;

class Matrix {
public:
    lint mat[NMAX][NMAX];

    static Matrix neutral;
    static Matrix M;

    Matrix() {}

    Matrix operator*(const Matrix &arg) {
        Matrix ans;
        for (int i = 0; i < sz; ++ i)
            for (int j = 0; j < sz; ++ j)
                ans.mat[i][j] = -INF;

        for (int i = 0; i < sz; ++ i)
            for (int k = 0; k < sz; ++ k)
                for (int j = 0; j < sz; ++ j)
                    ans.mat[i][j] = max(ans.mat[i][j], mat[i][k] + arg.mat[k][j] - nodes[k].pondre);

        return ans;
    }

    Matrix operator^(lint exp) {
        Matrix ans = Matrix :: neutral;
        Matrix aux = Matrix :: M;

        while (exp) {
            if (exp & 1)
                ans = ans * aux;
            exp >>= 1;
            aux = aux * aux;
        }

        return ans;
    }
};

Matrix Matrix :: neutral, Matrix :: M;

int main()
{
    ios_base :: sync_with_stdio(false);
    init();

    lint k;

    //Building AHO
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        cin >> w[i];

    for (int i = 1; i <= n; ++ i) {
        cin >> strings[i];
        add(i);
    }

    build_fails();

    for (int i = 0; i < sz; ++ i)
        for (int j = 0; j < sz; ++ j)
            Matrix :: M.mat[i][j] = -INF;

    for (int i = 0; i < sz; ++ i)
        for (int sig = 0; sig < 26; ++ sig)
            Matrix :: M.mat[i][nodes[i].alf[sig]] = nodes[i].pondre + nodes[nodes[i].alf[sig]].pondre;

    for (int i = 0; i < sz; ++ i)
        for (int j = 0; j < sz; ++ j)
            Matrix :: neutral.mat[i][j] = -INF;
    for (int i = 0; i < sz; ++ i)
        Matrix :: neutral.mat[i][i] = nodes[i].pondre;

    Matrix fin = Matrix :: M ^ k;

    lint ans = 0;
    for (int i = 0; i < sz; ++ i)
        if (fin.mat[0][i] > ans)
            ans = fin.mat[0][i];
    cout << ans << '\n';
    return 0;
}