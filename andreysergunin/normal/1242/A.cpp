#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> p;

    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            p.push_back(i);
        }
    }

    if (n > 1) {
        p.push_back(n);
    }

    if (p[0] == p.back()) {
        cout << p[0] << endl;
        return 0;
    }

    cout << 1 << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}