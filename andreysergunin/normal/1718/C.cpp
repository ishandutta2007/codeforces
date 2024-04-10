#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
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


void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    primes.clear();
    sieve(n);

    vector<int> divs;
    for (int p : primes) {
        if (n % p == 0) {
            divs.push_back(p);
        }
    }

    vector<vector<ll>> res(sz(divs));
    multiset<ll> setik;

    for (int j = 0; j < sz(divs); ++j) {
        int d = n / divs[j];
        res[j].resize(d);
        for (int i = 0; i < n; ++i) {
            res[j][i % d] += a[i];
        }
        for (int i = 0; i < d; ++i) {
            res[j][i] *= d;
            setik.insert(res[j][i]);
        } 
    }

    cout << *(--setik.end()) << "\n";

    for (int i = 0; i < q; ++i) {
        int pos;
        ll x;
        cin >> pos >> x;
        --pos;

        for (int j = 0; j < sz(divs); ++j) {
            int d = n / divs[j];
            setik.erase(setik.find(res[j][pos % d]));
            res[j][pos % d] -= a[pos] * d;
        }

        a[pos] = x;
        for (int j = 0; j < sz(divs); ++j) {
            int d = n / divs[j];
            res[j][pos % d] += a[pos] * d;
            setik.insert(res[j][pos % d]);
        }
        cout << *(--setik.end()) << "\n";
    }
}