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

const int MAXN = 555;
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

    for (int i = 0; i <= n; ++i) {
        f[i][i] = 1;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len;
            int pos = i;
            for (int k = i; k < j; ++k) {
                if (a[pos] > a[k]) {
                    pos = k;
                }
            }   

            int u = 0, v = 0;

            for (int k = i; k <= pos; ++k) {
                int c = f[i][k];
                mul(c, f[k][pos]);
                add(u, c);
            }

            for (int k = pos + 1; k <= j; ++k) {
                int c = f[pos + 1][k];
                mul(c, f[k][j]);
                add(v, c);
            }

            f[i][j] = u;
            mul(f[i][j], v);
        }
    }

    cout << f[0][n] << endl;





    return 0;
}