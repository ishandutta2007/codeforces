#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e7 + 100;
typedef long long ll;
ll n, m, k;
bool u[maxn];
bool prime(ll k) {
    if(k == 2) return 1;
    if(k % 2 == 0) return 0;
    if(k == 1) return 0;
    for(ll i = 3; i * i <= k; i += 2) {
        if(k % i == 0) return 0;
    }
    return 1;
}
ll f(ll N) {
    if(k > N) return 0;
    if(k*k > N) {
        return 1;
    }
    if(k == 2) {
        return N / 2;
    }
    if(k == 3) {
        return N / 3 - N / 6;
    }

    int d = N / k;
    if(d < maxn) {
        memset(u, 0, sizeof u);
        for(int i = 2; i < k; i++) {
            if(!u[i]) {
                for(int j = i; j <= d; j+=i) {
                    u[j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= d; i++) {
            ans += !u[i];
        }
        return ans;
    }
    for(int i = 2; i < k; i++) {
        u[i] = 0;
    }
    vector<int> pr;
    for(int i = 2; i < k; i++) {
        for(int j = 2 * i; j < k; j += i) {
            u[j] = 1;
        }
        if(!u[i]) {
            pr.push_back(i);
        }
    }
    int sz = pr.size();
    ll ans = 0;
    for(int i = 0; i < (1<<sz); i++) {
        int cur = d;
        for(int j = 0; j < sz; j++) {
            if(i & (1<<j)) cur /= pr[j];
        }
        if(__builtin_popcount(i) % 2 == 0) ans += cur;
        else ans -= cur;
    }
    return ans;
}
void solve() {
    cin >> n >> m >> k;
    if(!prime(k)) {
        cout << 0 << "\n";
        return;
    }
    //cout << f(m) << "\n";
    //cout << f(n-1) << "\n";
    cout << f(m) - f(n-1) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}