#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
    cout << setprecision(8) << fixed;
    cerr << setprecision(8) << fixed;

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

class BIT {
public:
    BIT(int n) {
        arr.resize(n);
    }
    
    void add(int pos, int val) {
        for (int i = pos; i < sz(arr); i |= i + 1) {
            arr[i] += val;
        }
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            res += arr[i];
        }
        return res;
    }

private:
    vector<int> arr;
};

namespace count_primes_for_all { // counting \pi(n / l) for all l 

const ll MAXN = 1e11;
const ll K = 5000000; // (n / log n) ^ (2 / 3)
const ll MAXP = 500000; // number of primes <= K
const ll MAXQ = 15000000; // number of queries

int cntPrimes = 0;
int primes[MAXP];
int minPrime[K + 1];
int cnt[K + 1];

void sieve() {
    memset(minPrime, -1, sizeof(minPrime));
    for (int i = 2; i <= K; ++i) {
        if (minPrime[i] == -1) {
            minPrime[i] = cntPrimes;
            primes[cntPrimes++] = i;
        }
        for (int j = 0; j < cntPrimes; ++j) {
            int p = primes[j];
            if (j > minPrime[i] || (ll)i * p > K) {
                break;
            }
            minPrime[p * i] = j;
        }
        cnt[i] = cnt[i - 1] + (minPrime[i] == cntPrimes - 1);
    }
}

struct Query {
    int id, pos;
};

int cntQueries = 0;
int sizes[(MAXN - 1) / K + 2];
vector<ll> dp[(MAXN - 1) / K + 2];

vector<Query> queries[MAXP];
vector<int> byPrime[MAXP];
int ans[MAXQ];

void clear() {
    cntQueries = 0;
    for (int i = 0; i < cntPrimes; ++i) {
        byPrime[i].clear();
        queries[i].clear();
    }
}

ll countPrimes(ll n) {
    clear();

    int layers = (n - 1) / K + 1;
    sizes[layers + 1] = 0;
    for (int i = 1; i <= layers; ++i) {
        int j = 0;
        while (ll(primes[j]) * primes[j] <= n / i) {
            ++j;
        }
        sizes[i] = j + 1;
        dp[i].resize(sizes[i]);
    }

    for (int l = layers; l >= 1; --l) {
        for (int k = 1; k < sizes[l]; ++k) { 
            ll nextL = ll(l) * primes[k - 1];
            if (n / nextL <= K) {
                queries[k - 1].push_back({cntQueries++, int(n / nextL)});
            }
        } 
    }

    for (int i = 2; i <= K; ++i) {
        byPrime[minPrime[i]].push_back(i);
    }
    
    BIT bit(K + 1);
    bit.add(1, 1);

    for (int i = cntPrimes - 1; i >= 0; --i) {
        for (int pos : byPrime[i]) {
            bit.add(pos, 1);
        }
        for (auto q : queries[i]) {
            ans[q.id] = bit.sum(q.pos);
        }
    }

    cntQueries = 0;
    for (int l = layers; l >= 1; --l) {
        dp[l][0] = n / l;
        for (int k = 1; k < sizes[l]; ++k) { 
            dp[l][k] = dp[l][k - 1];
            ll nextL = ll(l) * primes[k - 1];
            if (n / nextL <= K) {
                dp[l][k] -= ans[cntQueries++];
            } else {
                ll val = dp[nextL][min(k, sizes[nextL]) - 1] - max(0, k - sizes[nextL]);
                dp[l][k] -= val;
            }
        } 
    }

    return sizes[1] - 2 + dp[1].back();
}

ll countPrimes(ll n, ll l) {
    if (n / l <= K) {
        return cnt[n / l];
    }
    return sizes[l] - 2 + dp[l].back();
}

} // count_primes_for_all

namespace fast_sieve {

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

} // fast_sieve

void solve() {
    ll n;
    cin >> n;
    fast_sieve::sieve(sqrtl(n));

    ll res = 0;
    for (ll p : fast_sieve::primes) {
        if (p * p * p > n) {
            break;
        }
        ++res;
    }

    count_primes_for_all::sieve();
    count_primes_for_all::countPrimes(n);

    for (int i = 0; i < sz(fast_sieve::primes); ++i) {
        res += count_primes_for_all::countPrimes(n, fast_sieve::primes[i]) - i - 1;
    }

    cout << res << endl;
}