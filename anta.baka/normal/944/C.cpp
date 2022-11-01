#pragma gcc optimize("OFast")
#pragma gcc target("sse,sse2,sse3,sse4,tune=native")
//#pragma gcc optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;
const ll llINF = 1e18;

int n, cnt[maxn];
vector<int> g[maxn];

void dfs(int v, int p, int d) {
    cnt[d]++;
    for(int to : g[v]) dfs(to, v, d + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    dfs(0, -1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) ans += (cnt[i] & 1);
    cout << ans;
}