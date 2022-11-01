//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
#define int ll

const int maxn = 5e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

int n, c[maxn], a[maxn], in[maxn], ban[maxn];
queue<int> q;

int dfs(int v) {
    ban[v] = 1;
    int ret = c[v];
    if(ban[a[v]] == 0) ret = min(ret, dfs(a[v]));
    return ret;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        in[a[i]]++;
    }
    for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        ban[v] = 1;
        if(--in[a[v]] == 0) q.push(a[v]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) if(ban[i] == 0) ans += dfs(i);
    cout << ans;
}