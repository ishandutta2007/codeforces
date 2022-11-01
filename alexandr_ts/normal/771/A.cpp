#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAXN = 150000;

map<pair<int, int>, int> was;
vector<int> g[MAXN + 1], used(MAXN + 1, 0);
ll sum;
int sz;

void dfs(int v) {
    used[v] = 1;
    sz++;
    sum += (int)g[v].size();
    for(auto u: g[v])
        if(!used[u])
            dfs(u);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)
            swap(a, b);
        if(was[{ a, b }])
            continue;
        was[{ a, b }] = 1;
        g[a].push_back(b);
        g[b].push_back(a);

    }
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            sum = 0;
            sz = 0;
            dfs(i);
            sum /= 2;
            if((ll)sz * (sz - 1) / 2 != sum) {
                ok = false;
            }
        }
    }
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}