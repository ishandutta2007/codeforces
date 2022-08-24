#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int n, k;

vector<int> e[maxn];

ll answer;

ll sz[maxn];

ll mas[maxn][5];

ll val[maxn];

void dfs(int v, int par){
    sz[v] = 1;
    mas[v][0] = 1;
    for (int i = 0; i < e[v].size(); i++)
    if (e[v][i] != par){
        int to = e[v][i];
        dfs(to, v);
        ll w = mas[to][0];
        val[to] += w;
        mas[to][0] = mas[to][k - 1];
        for (int j = k - 1; j > 1; j--)
            mas[to][j] = mas[to][j - 1];
        mas[to][1] = w;
        answer += sz[v] * val[to] + sz[to] * val[v];
        for (int j = 1; j < k; j++)
            for (int g = 1; g < k; g++)
                if (j + g <= k)
                    answer -= mas[v][j] * mas[to][g];
        sz[v] += sz[to];
        for (int j = 0; j < k; j++)
            mas[v][j] += mas[to][j];
        val[v] += val[to];
    }
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(0, -1);
    cout << answer;
}