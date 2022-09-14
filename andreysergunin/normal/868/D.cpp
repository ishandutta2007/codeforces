// MIPT Shock Content
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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef complex<ld> Complex;

mt19937 rr(random_device{}());

const int MAXK = 1 << 15;
const int MAXN = 105;

int n, m;
bitset<MAXK> b[2 * MAXN];
string s[MAXN];
int lf[2 * MAXN][15], rg[2 * MAXN][15];
int w[2 * MAXN];

pair<int, int> q[MAXN];
int ans[2 * MAXN];

void merge(int u, int v, int to, int k) {
    w[to] = min(k, w[u] + w[v]);
    b[to].reset();
    memset(lf[to], -1, sizeof lf[to]);
    memset(rg[to], - 1, sizeof rg[to]);

    for (int i = 0; i < k; ++i) {
        if (i > w[u] + w[v]) {
            continue;
        }
        if (i <= w[u]) {
            lf[to][i] = lf[u][i];
        } else {
            lf[to][i] = (lf[u][w[u]] << (i - w[u])) + lf[v][i - w[u]];
        }
        if (i <= w[v]) {
            rg[to][i] = rg[v][i];
        } else {
            rg[to][i] = (rg[u][i - w[v]] << w[v]) + rg[v][w[v]];
        }
    }

    // cout << to << endl;
    // for (int j = 1; j < 5; ++j) {
    //     cout << lf[to][j] << " ";
    // }
    // cout << endl;
    // for (int j = 1; j < 5; ++j) {
    //     cout << rg[to][j] << " ";
    // }
    // cout << endl;

    b[to] = b[u] | b[v];

    for (int i = 1; i < k; ++i) {
        int j = k - i;
        if (rg[u][i] == -1 || lf[v][j] == -1) {
            continue;
        }
        int mask = (rg[u][i] << j) + lf[v][j];
        // cout << "?" << to - m << " " << mask << endl;
        b[to][mask] = 1;
    }

    if (b[to].count() == (1 << k)) {
        ans[to] = k;
    }
}   

void solve(int k) {
    // cout << "--------> " << k << endl;
    for (int i = 0; i < n; ++i) {
        b[i].reset();
        memset(lf[i], -1, sizeof lf[i]);
        memset(rg[i], - 1, sizeof rg[i]);
        lf[i][0] = 0;
        rg[i][0] = 0;
        w[i] = min(k, sz(s[i]));
        for (int j = 0; j < sz(s[i]); ++j) {
            int x = 0;
            for (int l = 0; l < k && j + l < sz(s[i]); ++l) {
                x *= 2;
                x += s[i][j + l] - '0';
                if (j == 0 && l + 1 < k) {
                    lf[i][l + 1] = x;
                }
            }
            if (sz(s[i]) - j >= k) {
                b[i][x] = 1;
            }

            if (sz(s[i]) - j < k) {
                rg[i][sz(s[i]) - j] = x;
            }
        }
        // cout << i << endl;
        // for (int j = 1; j < 5; ++j) {
        //     cout << lf[i][j] << " ";
        // }
        // cout << endl;
        // for (int j = 1; j < 5; ++j) {
        //     cout << rg[i][j] << " ";
        // }
        // cout << endl;

        if (b[i].count() == (1 << k)) {
            ans[i] = k;
        }
    }

    for (int i = 0; i < m; ++i) {
        merge(q[i].first, q[i].second, n + i, k);
    }
}

int main() {

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        --q[i].first;
        --q[i].second;
    }

    for (int i = 1; i <= 15; ++i) {
        solve(i);
    }

    for (int i = n; i < n + m; ++i) {
        cout << ans[i] << "\n";
    }
}