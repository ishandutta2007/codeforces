#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int n, m;

bool vis[maxn];

vector<int> e[maxn];

map<pair<int, int>, int> q;

int mas[maxn], cnt;

bool dfs(int v){
    vis[v] = 1;
    for (int i = 0; i < cnt; i++)
        if (q.find(make_pair(v, mas[i])) == q.end())
            return 1;
    mas[cnt] = v;
    cnt++;
    for (int i = 0; i < e[v].size(); i++)
        if (!vis[e[v][i]])
            if (dfs(e[v][i]))
                return 1;
    return 0;
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
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
        q[make_pair(v, u)] = 1;
        q[make_pair(u, v)] = 1;
    }
    for (int i = 0; i < n; i++)
    if (!vis[i]){
        cnt = 0;
        if (dfs(i)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}