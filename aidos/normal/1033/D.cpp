#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353 ;
const int inf = (1<<30) - 1;
int n;
vector<ll> a, p;
bool is_prime(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    if(x > 1) return 1;
    return 0;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll y = sqrt(x) + 0.5;
        if(y * y == x) {
            if(is_prime(y)) {
                p.emplace_back(y);
                p.emplace_back(y);
                continue;
            }
        }
        y = pow(x, 1/3.0) + 0.5;
        if(y * y * y == x) {
            if(is_prime(y)) {
                p.emplace_back(y);
                p.emplace_back(y);
                p.emplace_back(y);
                continue;
            }
        }
        y = pow(x, 1/4.0);
        if(y * y * y * y == x) {
            if(is_prime(y)) {
                p.emplace_back(y);
                p.emplace_back(y);
                p.emplace_back(y);
                p.emplace_back(y);
                continue;
            }
        }
        a.emplace_back(x);
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(a[i] == a[j]) {
                continue;
            }
            ll x = __gcd(a[i], a[j]);
            if(x > 1) {
                p.emplace_back(x);
                p.emplace_back(a[i]/x);
                p.emplace_back(x);
                p.emplace_back(a[j]/x);
                a[i] = 1;
                a[j] = 1;
            }
        }
    }
    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(a[j] % p[i] == 0) {
                p.emplace_back(p[i]);
                a[j] /= p[i];
                if(a[j] > 1) {
                    p.emplace_back(a[j]);
                    a[j] = 1;
                }
            }
        }
    }
    ll ans = 1;
    sort(p.begin(), p.end());
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == 1) continue;
        if(i > 0 && a[i]==a[i-1]) continue;
        ll cnt = 0;
        while(cnt + i < a.size() && a[i] == a[i+cnt]) ++cnt;
        ans = (ans * (cnt+1)) % mod;
        ans = (ans * (cnt+1)) % mod;
    }
    for(int i = 0; i < p.size(); i++) {
        if(i > 0 && p[i] == p[i-1]) continue;
        ll cnt = 0;
        while(cnt + i < p.size() && p[i] == p[i+cnt]) ++cnt;
        ans = (ans * (cnt+1)) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
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