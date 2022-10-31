/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    ll s;
        cin >> s;
        ll A[7] = {6, 10, 14, 15, 22, 26, 21};
        if (s < 31) cout << "NO" << endl;
        else {
            for (int i = 0; i < 7; i++) {
                for (int j = i + 1; j < 7; j++) {
                    for (int k = j + 1; k < 7; k++) {
                        ll x = s - A[i] - A[j] - A[k];
                        if (x > 0 && x != A[i] && x != A[j] && x != A[k]) return cout << "YES" << endl << x << sep << A[i] << sep << A[j] << sep << A[k] << endl, 0;
                    }
                }
            }

            cout << "NO" << endl;
        }
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}