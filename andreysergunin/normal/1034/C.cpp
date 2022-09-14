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

const int MAXN = 1111111;
const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int n;
ll sum = 0;
vector<int> g[MAXN];
int cnt[MAXN];
int a[MAXN];

ll dfs(int v) {
    ll s = a[v];
    for (int u : g[v]) {
        s += dfs(u);
    }
    ll k = sum / gcd(sum, s);
    if (k <= n) {
        ++cnt[k];
    }
    return s;
}

vector<int> primes;
int minPrime[MAXN];

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        minPrime[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == i) {
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

vector<int> d[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // a[i] = 1;
    }

    for (int u = 1; u < n; ++u) {
        int v = u;
        cin >> v;
        --v;
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    dfs(0);

    for (int i = n; i >= 1; --i) {
        for (int j = 2; i * j <= n; ++j) {
            cnt[i * j] += cnt[i];
        }
    }

    sieve(n + 1);

    d[1].push_back({1});
    for (int k = 2; k <= n; ++k) {
        int m = k;
        int deg = 0;
        int p = minPrime[k];
        while (m % p == 0) {
            m /= p;
            ++deg;
        }

        int x = 1; 
        for (int dg = 0; dg <= deg; ++dg) {
            for (int div : d[m]) {
                d[k].push_back(x * div);
            }
            x *= p;
        }
    }


    for (int i = 1; i <= n; ++i) {
        d[i].pop_back();
    }

    vector<int> dp(n + 1);
    int res = 0;
    for (int i = n; i >= 1; --i) {
        if (sum % i == 0 && cnt[i] == i) {
            add(dp[i], 1);
            for (int j : d[i]) {
                add(dp[j], dp[i]);
            }
        } else {
            dp[i] = 0;
            continue;
        }
    }

    cout << dp[1] << endl;
}