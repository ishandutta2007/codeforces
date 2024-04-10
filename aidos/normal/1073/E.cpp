#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
ll A, B, k;
vector<int> a;
int used[20][1<<10][2];
pair<ll, ll> dp[20][1<<10][2];
int T;
pair<ll, ll> get(int pos, int mask, int sp) {
    if(pos == a.size()) {
        return make_pair(1, 0);
    }
    if(used[pos][mask][sp] == T) return dp[pos][mask][sp];
    used[pos][mask][sp] = T;
    pair<ll, ll> res=make_pair(0, 0);
    for(int d = 0; d < 10; d++) {
        if(mask & (1<<d)) {
            if(sp) {
                if(d <= a[pos]) {
                    pair<ll, ll> cur = get(pos + 1, mask, (d == a[pos]));
                    res.first = (res.first + cur.first) % mod;
                    res.second = (res.second + d * cur.first + cur.second) % mod;
                }
            } else {
                pair<ll, ll> cur = get(pos + 1, mask, 0);
                res.first = (res.first + cur.first) % mod;
                res.second = (res.second + d * cur.first + cur.second) % mod;
            }
        }
    }
    res.first = (res.first * 10) % mod;
    dp[pos][mask][sp] = res;
    return res;
}
ll calc(ll x) {
    a.clear();
    while(x > 0) {
        a.emplace_back(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    vector<ll> D(1<<10, 0);
    T++;
    for(int mask = 0; mask < (1<<10); mask++) {
        ll &cur = D[mask];
        for(int d=1; d <= 9; d++) {
            if(!(mask & (1<<d))) continue;
            for(int i = 1; i < a.size(); i++) {
                pair<ll, ll> z = get(i+1, mask, 0);
                cur = (cur + z.first * d % mod + z.second) % mod;
            }
            if(d <= a[0]) {
                pair<ll, ll> z = get(1, mask, d == a[0]);
                cur = (cur + z.first * d % mod + z.second) % mod;
            }
        }
    }
    for(int mask = 0; mask < (1<<10); mask++) {
        for(int nmask = 0; nmask < mask; nmask++) {
            if((mask & nmask) == nmask)
                D[mask] = (D[mask] - D[nmask] + mod) % mod;
        }
    }
    ll ans = 0;
    for(int mask = 0; mask < (1<<10); mask++) {
        if(__builtin_popcount(mask) <= k) {
            ans = (ans + D[mask]) % mod;
        }
    }
    return ans;
}
void solve(){
    cin >> A >> B >> k;
    ll ans = calc(B);
    if(A > 1) ans -= calc(A-1);
    ans = (ans + mod) % mod;
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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