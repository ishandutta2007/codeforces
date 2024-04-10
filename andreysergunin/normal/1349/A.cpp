#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 200200;

vector<int> primes;
vector<int> minPrime;

void sieve(int n) {
    minPrime.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        minPrime[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == i) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > minPrime[i] || (ll)i * p > n) {
                break;
            }
            minPrime[p * i] = p;
        }
    }
}

vector<int> u[MAXN];

void solve() {
    int n;
    cin >> n;
    sieve(MAXN - 1);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k > 1) {
            int p = minPrime[k];
            int a = 0;
            while (k % p == 0) {
                k /= p;
                ++a;
            }
            u[p].push_back(a);
        }
    }

    ll res = 1;
    for (int i = 1; i < MAXN; ++i) {
        if (sz(u[i]) <= n - 2) {
            continue;
        } else if (sz(u[i]) == n - 1) {
            u[i].push_back(0);
        }
        int pos = min_element(all(u[i])) - u[i].begin();
        u[i][pos] = 100;
        pos = min_element(all(u[i])) - u[i].begin();
        for (int j = 0; j < u[i][pos]; ++j) {
            res *= i;
        }
    }
    cout << res << endl;
}