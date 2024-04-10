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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

const int MAXN = 15000111;

int cnt[MAXN];
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    sieve(MAXN - 1);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, a[i]);
    }

    for (int i = 0; i < n; ++i) {
        a[i] /= g;
    }

    for (int i = 0; i < n; ++i) {
        int x = a[i];

        while (x > 1) {
            int p = minPrime[x];
            while (x % p == 0) {
                x /= p;
            }
            ++cnt[p];
        }
    }

    int res = n;

    for (int i = 0; i < MAXN; ++i) {
        res = min(res, n - cnt[i]);
    }

    cout << (res == n ? -1 : res) << endl;


}