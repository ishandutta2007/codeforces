#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINES
const int maxn = 500000, mod = 1000000007;
int p[maxn], h[maxn], sz[maxn], used2[maxn];

int f(int x){
    if(p[x] == x)
        return x;
    int p1 = f(p[x]);
    p[x] = p1;
    return p[x];
}

void unite(int x, int y){
    int a = f(x), b = f(y);
    if (a == b) {
        return;
    }
    if (h[a] < h[b])
        p[a] = b, sz[b] += sz[a], used2[b] = used2[b]|used2[a];
    else if (h[a] > h[b])
        p[b] = a, sz[a] += sz[b], used2[a] = used2[b]|used2[a];
    else
        p[b] = a, h[a]++, sz[a] += sz[b], used2[a] = used2[b]|used2[a];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            a[i].pb(x);
        }
    }
    for (int i = 0; i < m; ++i)
        p[i] = i, h[i] = sz[i] = 1;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i].size() == 1) {
            if (used2[f(a[i][0])] == 0) {
                ans.pb(i);
            }
            used2[f(a[i][0])] = 1;
        } else {
            if (f(a[i][0]) != f(a[i][1])) {
                if (used2[f(a[i][0])] == 0 || used2[f(a[i][1])] == 0) {
                    ans.pb(i);
                }
                unite(a[i][0], a[i][1]);
            }
        }
    }
    int ans2 = 1;
    for (int i = 0; i < ans.size(); ++i) {
        ans2 *= 2;
        ans2 %= mod;
    }
    cout << ans2 << ' ' << ans.size() << '\n';
    for (auto s: ans)
        cout << s+1 << ' ';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}