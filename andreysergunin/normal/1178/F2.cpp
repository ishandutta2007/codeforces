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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int P = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

const int MAXN = 1010;
int f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }  

    vector<int> b = {a[0]};
    for (int i = 1; i < m; ++i) {
        if (a[i] != a[i - 1]) {
            b.push_back(a[i]);
        }
    }

    a = b;
    m = sz(a);

    if (m >= 2 * n) {
        cout << 0 << endl;
        return 0;
    }

    b = vector<int>(m);
    for (int i = 0; i < n; ++i) {
        int lf = m, rg = 0;
        for (int j = 0; j < m; ++j) {
            if (a[j] == i) {
                lf = min(lf, j);
                rg = max(rg, j);
            }
        }

        for (int j = lf; j <= rg; ++j) {
            b[j] = i;
        }
    }
    if (a != b) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> lf(n, m), rg(n, 0);
    for (int i = 0; i < m; ++i) {
        lf[a[i]] = min(lf[a[i]], i);
        rg[a[i]] = i;
    }

    // for (int i = 0; i < m; ++i) {
    //     cout << a[i] << " "; 
    // }
    // cout << endl;

    for (int i = 0; i <= m; ++i) {
        f[i][i] = 1;
    }

    for (int len = 1; len <= m; ++len) {
        for (int i = 0; i + len <= m; ++i) {
            int j = i + len;

            bool ok = true;
            for (int k = i; k < j; ++k) {
                if (lf[a[k]] < i || rg[a[k]] >= j) {
                    ok = false;
                }
            }

            if (!ok) {
                continue;
            }


            int pos = i;
            vector<int> ps = {i};

            for (int k = i + 1; k < j; ++k) {
                if (a[pos] > a[k]) {
                    pos = k;
                    ps = {k};
                } else if (a[pos] == a[k]) {
                    ps.push_back(k);
                }
            }

            int u = 0, v = 0;

            for (int k = i; k <= ps[0]; ++k) {
                int c = f[i][k];
                mul(c, f[k][ps[0]]);
                add(u, c);
            }

            for (int k = ps.back() + 1; k <= j; ++k) {
                int c = f[ps.back() + 1][k];
                mul(c, f[k][j]);
                add(v, c);
            }

            f[i][j] = u;
            mul(f[i][j], v);

            for (int k = 0; k < sz(ps) - 1; ++k) {
                mul(f[i][j], f[ps[k] + 1][ps[k + 1]]);
            }
            // cout << i << " " << j << " " << ps[0] << " " << ps[1] << " " << f[i][j] << endl;
        }
    }

    cout << f[0][m] << endl;





    return 0;
}