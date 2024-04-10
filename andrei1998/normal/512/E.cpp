#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

const int NMAX = 1000 + 5;

int n;
int mat[NMAX][NMAX];

vector <pair <int, int> > sol;

void DEI(int l, int r, int insert_type) {
    if (r - l + 1 < 3)
        return ;

    int k;
    for (k = l + 1; k <= r - 1; ++ k)
        if (mat[l][k] && mat[k][r])
            break;

    if (insert_type == 0)
        sol.push_back(make_pair(l, r));

    mat[l][r] = mat[r][l] = false;
    mat[1][k] = mat[k][1] = true;

    DEI(l, k, insert_type);
    DEI(k, r, insert_type);

    if (insert_type == 1)
        sol.push_back(make_pair(1, k));
}

void solve(int type) {
    memset(mat, 0, sizeof mat);

    vector <int> graph1;
    for (int i = 1; i < n - 2; ++ i) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = mat[b][a] = true;
    }

    for (int i = 1; i <= n; ++ i)
        mat[i][i % n + 1] = mat[i % n + 1][i] = true;
    for (int i = 1; i <= n; ++ i)
        if (mat[1][i])
            graph1.push_back(i);

    for (int i = 1; i < graph1.size(); ++ i)
        DEI(graph1[i - 1], graph1[i], type);
}

int main()
{
    cin >> n;

    solve(0);
    solve(1);

    cout << sol.size() << '\n';
    for (auto it: sol)
        cout << it.first << ' ' << it.second << '\n';
    return 0;
}