#pragma GCC optimize("Ofast", "unroll-loops")

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

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 2020;

int a[2][MAXN][MAXN];
int b[MAXN];

vector<int> g[2 * MAXN];
vector<int> w[2 * MAXN];
int col[2 * MAXN];

void nie() {
    cout << -1 << endl;
    exit(0);
}

void dfs(int v, int c) {
    col[v] = c;
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        if (col[u] != -1) {
            if ((col[u] ^ col[v]) != w[v][i]) {
                nie();
            }
        } else {
            dfs(u, c ^ w[v][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  

    int n;
    cin >> n;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                a[k][i][j] = s[j] - '0';
            }
        }    
    }
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        b[i] = s[i] - '0';
    }

    memset(col, -1, sizeof(int) * 2 * n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i] + b[j] == 0) {
                if (a[0][i][j] != a[1][i][j]) {
                    cout << - 1 << endl;
                    return 0;
                }
            } else if (b[i] + b[j] == 2) {
                g[i].push_back(j + n);
                g[j + n].push_back(i);
                int x = a[0][i][j] ^ a[1][i][j];
                w[i].push_back(x);
                w[j + n].push_back(x);
            } else if (b[i] == 1) {
                col[j + n] = a[0][i][j] ^ a[1][i][j];
            } else {
                col[i] = a[0][i][j] ^ a[1][i][j];
            }
        }
    }

    // for (int i = 0; i < 2 * n; ++i) {   
    //     cout << col[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < 2 * n; ++i) {
        if (col[i] >= 0) {
            dfs(i, col[i]);
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }

    int res = 0;
    for (int i = 0; i < 2 * n; ++i) {
        res += col[i];
    }

    cout << res << endl;

    for (int i = 0; i < n; ++i) {
        if (col[i] == 1) {
            cout << "row " << i << endl;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (col[i + n] == 1) {
            cout << "col " << i << endl;
        }
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}