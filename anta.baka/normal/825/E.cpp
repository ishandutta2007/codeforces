#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> g[100000];
int dout[100000];
set<int> setik;
int ans[100000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u; --v;
        g[v].push_back(u);
        dout[u]++;
    }
    for(int i = 0; i < n; i++)
        if(dout[i] == 0)
            setik.insert(i);
    for(int i = n; i >= 1; i--) {
        int v = *setik.rbegin();
        setik.erase(v);
        ans[v] = i;
        for(int to : g[v]) {
            dout[to]--;
            if(dout[to] == 0)
                setik.insert(to);
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}