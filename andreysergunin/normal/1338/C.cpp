#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 


void solve() {
    ll n;
    cin >> n;
    if (n <= 3) {
        cout << n << endl;
        return;
    }

    int k = 0;
    while (n >= (1ll << (2 * k))) {
        ++k;
    }
    --k;


    ll x = n;
    x -= (1ll << (2 * k));
    x /= 3;

    ll y = 0;
    for (int l = k - 1; l >= 0; --l) {
        ll t = (x >> (2 * l)) & 3;
        if (t == 1) {
            t = 2;
        } else if (t == 2) {
            t = 3;
        } else if (t == 3) {
            t = 1;
        }
        y += (t << (2 * l));
    }

    ll z = x ^ y;

    x += 1ll << (2 * k);
    y += 2ll << (2 * k);
    z += 3ll << (2 * k);
    
    if (n % 3 == 1) {
        cout << x << "\n";
    } else if (n % 3 == 2) {
        cout << y << "\n";
    } else {
        cout << z << "\n";
    }
}