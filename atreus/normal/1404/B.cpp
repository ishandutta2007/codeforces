#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;

vector<int> t[maxn];
int h[maxn];

void dfs(int v, int par = -1){
    for (auto u : t[v])
        if (u != par)
            h[u] = h[v]+1, dfs(u,v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();
    int tc;
    cin >> tc;
    while (tc --){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++)
            t[i].clear();
        for (int i = 1; i <= n-1; i++){
            int v, u;
            cin >> v >> u;
            t[v].push_back(u);
            t[u].push_back(v);
        }
        h[a] = 0;
        dfs(a);
        if (h[b] <= da){
            cout << "Alice\n";
            continue;
        }
        int Q1 = -1;
        for (int i = 1; i <= n; i++)
            if (Q1 == -1 or h[Q1] < h[i])
                Q1 = i;
        h[Q1] = 0;
        dfs(Q1);
        int D = *max_element(h+1, h+n+1);
        da = min(da, D);
        db = min(db, D);
        if (2*da >= db)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}