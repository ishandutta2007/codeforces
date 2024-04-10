#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int cn[1<<21];
int cn2[1<<21];
int d[1<<21];
int a[1<<20];
void add(int x, int pos) {
    if(cn[x] == pos) return;
    if(cn[x] < pos) swap(cn[x], pos);
    cn2[x] = max(cn2[x], pos);
}
int dp[1<<21];
void add2(int x, int pos) {
    dp[x] = max(dp[x], pos);
}
int get(int x, int pos) {
    int cur = 0;
    for(int i = 20; i >= 0; i--) {
        if(x&(1<<i)) {

        } else {
            if(dp[cur|(1<<i)] > pos) {
                cur |= 1<<i;
            }
        }
    }
    return cur;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i], i);
    }
    for(int i = 0; i < 21; i++) {
        for(int mask = 0; mask < (1<<21); mask++) {
            if(mask & (1<<i)) {
                if(cn[mask]) add(mask^(1<<i), cn[mask]);
                if(cn2[mask]) add(mask^(1<<i), cn2[mask]);
            }
        }
    }
    for(int mask = 0; mask < (1<<21); mask++) {
        if(!cn2[mask]) continue;
        add2(mask, cn2[mask]);
    }
    int ans = 0;
    for(int i = 1; i <= n-2; i++) {
        ans = max(ans, get(a[i], i) | a[i]);
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