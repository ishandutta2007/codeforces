#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int MAXD = 6;
const int MAXN = 1e6;
const int P = 1e9 + 7;

inline ll sqr(ll x) {
    return x * x;
}

void mod(ll &x) {
    if (x >= P)
        x -= P;
    if (x < 0)
        x += P;
}

int main() {
    
    //ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(MAXN);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }

    vector<int> pow10 = {1, 10, 100, 1000, 10000, 100000};
    vector<int> add(1 << MAXD);
    for (int mask = 0; mask < (1 << MAXD); ++mask) {
        for (int i = 0; i < MAXD; ++i) {
            if (mask & (1 << i)) {
                add[mask] += pow10[i];
            }
        }
    }

    vector<ll> s(MAXN);
    vector<ll> sq(MAXN);
    vector<ll> cnt(MAXN);
    vector<ll> f(MAXN);
    vector<ll> g(MAXN);

    vector<ll> pow2(MAXN);
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pow2[i] = pow2[i - 1] * 2;
        if (pow2[i] >= P)
            pow2[i] -= P; 
    }

    for (int k = MAXN - 1; k >= 0; --k) {
        int cor = 0;
        for (int i = 0; i < MAXD; ++i) {
            if (k / pow10[i] % 10 < 9)
                cor += (1 << i);
        }
        for (int mask = 1; mask < (1 << MAXD); ++mask) {
            if ((mask & cor) != mask) 
                continue;
            s[k] += (__builtin_popcount(mask) & 1 ? 1 : -1) * s[k + add[mask]];
            mod(s[k]);
            sq[k] += (__builtin_popcount(mask) & 1 ? 1 : -1) * sq[k + add[mask]];
            mod(sq[k]);
            cnt[k] += (__builtin_popcount(mask) & 1 ? 1 : -1) * cnt[k + add[mask]];
        }
        s[k] += k * a[k];
        s[k] %= P;
        sq[k] += sqr(k) * a[k];
        sq[k] %= P;
        cnt[k] += a[k];
        g[k] = (sqr(s[k]) + sq[k]);
        g[k] %= P;
        if (cnt[k] > 1) {
            g[k] *= pow2[cnt[k] - 2];
        } else if (cnt[k] == 1) {
            g[k] *= (P + 1) / 2;
            g[k] %= P;
        }
        g[k] %= P;

        for (int mask = 0; mask < (1 << MAXD); ++mask) {
            if ((mask & cor) != mask) 
                continue;
            f[k] += (__builtin_popcount(mask) & 1 ? -1 : 1) * g[k + add[mask]];
            f[k] %= P;
            if (f[k] < 0)
                f[k] += P;
        }
    }


    ll ans = 0;
    for (ll i = 0; i < MAXN; ++i) {
        ans ^= f[i] * i;
    }
    cout << ans << endl;
}