#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
ll n;
vector<ll> a;
void solve() {
    cin >> n;
    int j = 0;
    for(int i = a.size()-1; i >= 0; i--) {
        while(a[i] + a[j] < n) j++;
        if(a[i] + a[j] == n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for(ll i = 1; i <= 10100; i++) {
        a.push_back(i * i * i);
    }
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}