// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
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
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--) {
       solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

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

int check(const vector<ll> &arr, ll p) {
    int res = 0;
    int n = sz(arr);
    for (int i = 0; i < n; ++i) {
        ll cur = arr[i] % p;
        cur = min(cur, p - cur);
        if (cur == arr[i]) {
            cur = p - cur;
        }
        if (cur > n) {
            return n;
        }
        res += cur;
        if (res > n) {
            return n;
        }
    }
    return res;
}

vector<ll> getBigPrimes(ll k) {
    vector<ll> res;
    for (int p : primes) {
        if (k % p == 0) {
            if (p > 1e4) {
                res.push_back(p);
            }
            while (k % p == 0) {
                k /= p;
            }
        }
    }
    if (k > 1) {
        res.push_back(k);
    }
    return res;
}

void solve() {
    sieve(1e6 + 10);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // a[i] = rnd() % ll(1e12) + 1;
    }

    int res = n;
    for (int p : primes) {
        if (p > 1e4) {
            break;
        }
        res = min(res, check(a, p));
    }

    for (int op = 0; op < 30; ++op) {
        int pos = rnd() % n;

        for (int x = -1; x <= 1; ++x) {
            if (a[pos] + x == 0) {
                continue;
            }
            for (ll p : getBigPrimes(a[pos] + x)) {
                res = min(res, check(a, p));
            }
        }
    }

    cout << res << endl;
}