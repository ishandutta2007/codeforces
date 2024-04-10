#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
int a[maxn];
vector<int> g[2];
void rec(int l, int r, int id, int sum) {
    if(l == r) {
        g[id].push_back(sum);
        return;
    }
    rec(l+1, r, id, sum);
    rec(l+1, r, id, (sum + a[l]) % k);
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    rec(0, n/2, 0, 0);
    rec(n/2, n, 1, 0);
    sort(g[0].begin(), g[0].end());
    sort(g[1].begin(), g[1].end());
    int ans = 0;
    for(const int &x: g[0]) {
        auto it = upper_bound(g[1].begin(), g[1].end(), k-1-x);
        if(it != g[1].begin()) it--;
        ans = max(ans, (x+*it) % k);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}