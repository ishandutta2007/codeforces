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

const int P = 1e9 + 7;

void add(ll &a, ll b) {
    a += b;
    if (a >= P)
        a -= P;
}

void sub(ll &a, ll b) {
    a -= b;
    if (a < 0)
        a += P;
}

vector<ll> fact;
vector<ll> revFact;

ll binPow(ll a, ll b) {
    if (b == 0)
        return 1;

    ll x = binPow(a, b / 2);
    x *= x;
    x %= P;
    if (b & 1) {
        x *= a;
        x %= P;
    }
    return x;
}

void precalc(int n) {
    fact.resize(n + 1);
    revFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % P;

    for (int i = 0; i < n; ++i) {
        revFact[i] = binPow(fact[i], P - 2);
    }
}
    
ll choose(int n, int k) {
    ll ans = fact[n];
    ans *= revFact[k];
    ans %= P;
    ans *= revFact[n - k];
    ans %= P;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    precalc(n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }

    if (n & 1) {
        for (int i = 0; i < n - 1; ++i) {
            if (i & 1) {
                sub(a[i], a[i + 1]);
            } else {
                add(a[i], a[i + 1]);
            }
        }
        a.pop_back();
        --n;
    }

    int k = (n - 1) / 4;

    vector<ll> c(4 * k + 1);
    for (int i = 0; i <= 2 * k; ++i)
        c[2 * i] = choose(2 * k, i);

    int l = n - 4 * k;
    vector<ll> b(l);
    for (int j = 0; j < l; ++j) {
        for (int i = 0; i <= 4 * k; ++i) {
            b[j] += a[j + i] * c[i];
            b[j] %= P;
        }
    }

    int type = 0;

    for (; sz(b) > 1; ) {
        for (int i = 0; i < sz(b) - 1; ++i) {
            if (type) {
                sub(b[i], b[i + 1]);
            } else {
                add(b[i], b[i + 1]);
            }
            type ^= 1;
        }
        b.pop_back();
    }
    cout << b[0] << endl;
 


}