#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

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

    int n;
    cin >> n;

    vector<int> a(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> primes;

    for (ll i = 2; i * i <= sum; ++i) {
        if (sum % i == 0) {
            while (sum % i == 0) {
                sum /= i;
            }
            primes.push_back(i);
        }
    }    

    if (sum > 1) {
        primes.push_back(sum);
    }
    if (sz(primes) == 0) {
        cout << -1 << endl;
        return 0;
    }

    ll res = ll(1e18) + 1;

    for (ll p : primes) {
        sum = 0;
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            sum %= p;
            cur += min(sum, p - sum);
        }
        res = min(res, cur);
    }

    cout << res << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}