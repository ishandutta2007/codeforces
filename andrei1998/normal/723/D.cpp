#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

const int NMAX = 55;

vector <vector <pair <int, int> > > comps;

class MyComp {
public:
    bool operator()(const vector <pair <int, int> > &a, const vector <pair <int, int> > &b) {
        if (a.size() != b.size())
            return a.size() > b.size();
        else
            return a < b;
    }
};

int n, m;
char mat[NMAX][NMAX];
char mat2[NMAX][NMAX];

void dfs(int lin, int col, bool add, vector <pair <int, int> > &v) {
    if (lin < 0 || col < 0 || lin > n + 1 || col > m + 1 || mat[lin][col] == '*')
        return ;

    mat[lin][col] = '*';
    if (add)
        v.push_back({lin, col});

    int nl, nc;
    for (int k = 0; k < 4; ++ k) {
        nl = lin + dx[k];
        nc = col + dy[k];
        dfs(nl, nc, add, v);
    }
}

int main()
{
    int k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++ i) {
        cin.get();
        cin.get(mat[i] + 1, NMAX);

        for (int j = 1; j <= m; ++ j)
            mat2[i][j] = mat[i][j];
    }

    vector <pair <int, int> > aux;
    dfs(0, 0, false, aux);

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (mat[i][j] == '.') {
                comps.push_back(aux);
                dfs(i, j, true, comps.back());
            }

    sort(comps.begin(), comps.end(), MyComp());

    int ans = 0;
    for (int i = k; i < comps.size(); ++ i)
        for (auto it: comps[i])
            ++ ans, mat2[it.first][it.second] = '*';

    cout << ans << '\n';
    for (int i = 1; i <= n; ++ i)
        cout << (mat2[i] + 1) << '\n';
    return 0;
}