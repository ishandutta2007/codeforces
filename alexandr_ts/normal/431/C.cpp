#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

ll k, d;

map <pr, ll> m;

ll f(ll n, ll d) {
    if (d == n || n == 0) return 1;
    if (d > n) return 0;
    if (m.count(mp(n, d)))
        return m[mp(n, d)];
    ll ans = 0;
    frab(i, 1, k + 1) if (n - i >= 0) {
        if (i >= d) {
            ll x = f(n - i, 0);
            m[mp(n - i, 0)] = x;
            ans = (ans + x) % MOD;
        }
        else {
            ll x = f(n - i, d);
            m[mp(n - i, d)] = x;
            ans = (ans + x) % MOD;
        }
    }
    return ans;

}

int main() {
    ll n;
    cin >> n >> k >> d;
    cout << f(n, d);
}