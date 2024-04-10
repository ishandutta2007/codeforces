#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 300300;
const int MAXP = 30000;
const int MAXSP = 150;

bitset<MAXN> b[MAXSP];

int good[MAXN];
int id[MAXN];
bool used[MAXN];
vector<int> pos[MAXP];

vector<int> primes;
vector<int> minPrime;
void sieve(int n) {
    minPrime.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        minPrime[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == i) {
            id[i] = sz(primes);
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > i || (ll)i * p > n) {
                break;
            }
            minPrime[p * i] = p;
        }
    }
}

vector<int> getPrimes(int n, bool sqFree = true) {
    vector<int> res;
    while (n > 1) {
        int p = minPrime[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        if (cnt > 1 && sqFree) {
            return {};
        }
        res.push_back(p);
    }
    assert(sz(res) <= 6);
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sieve(MAXN);

    for (int i = 0; i < n; ++i) {
        int cp = a[i];
        while (a[i] > 1) {
            int p = minPrime[a[i]];
            while (a[i] % p == 0) {
                a[i] /= p;
            }
            if ((ll)p * p <= MAXN) {
                b[id[p]][i] = 1;
            } else {
                pos[id[p]].push_back(i);
            }
        }
        a[i] = cp;
    }

    bitset<MAXN> full;
    for (int i = 0; i < n; ++i) {
        full[i] = 1;
    }

    for (int i = sz(primes) - 1; (ll)primes[i] * primes[i] > MAXN; --i) {
        bitset<MAXN> bb;
        for (int el : pos[id[primes[i]]]) {
            bb[el] = 1;
        }

        for (int j = 1; primes[i] * j <= MAXN; ++j) {
            used[j * primes[i]] = 1;

            bitset<MAXN> cur = bb;
            for (int el : getPrimes(j)) {
                cur |= b[id[el]];
            }

            if (cur == full) {
                good[j * primes[i]] = 1;
            }
        }
    }


    for (int i = 1; i < MAXN; ++i) {
        if (used[i]) {
            continue;
        }
        bitset<MAXN> cur;
        for (int el : getPrimes(i)) {
            cur |= b[id[el]];
        }
        if (cur == full) {
            good[i] = 1;
        }
    }

    // for (int i = 1; i <= 20; ++i) {
    //     cout << i << " " << good[i] << endl;
    // }

    int res = n + 1;

    for (int i = 0; i < n; ++i) {
        vector<int> p = getPrimes(a[i], 0);
        int k = sz(p);
        vector<int> f(1 << k);
        vector<int> g(1 << k, k + 1);

        for (int mask = 0; mask < (1 << k); ++mask) {
            int x = 1;
            for (int j = 0; j < k; ++j) {
                if (mask & (1 << j)) {
                    x *= p[j];
                }
            }
            f[mask] = !good[x];
        }

        g[0] = 0;
        for (int mask = 1; mask < (1 << k); ++mask) {
            for (int mask1 = mask; mask1 > 0; mask1 = (mask1 - 1) & mask) {
                if (f[mask1]) {
                    g[mask] = min(g[mask], g[mask ^ mask1] + 1);
                }
            }
        }
        // cout << a[i] << endl;
        // for (int i = 0; i < (1 << k); ++i) {
        //     cout << f[i] << " ";
        // }
        // cout << endl;


        if (g[(1 << k) - 1] <= k) {
            res = min(res, g[(1 << k) - 1] + 1);
        }
    }

    cout << (res == n + 1 ? - 1 : res) << endl;
}