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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 1010;
const int P = 998244353;

void add(int &a ,int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

vector<int> g[2 * MAXN];
vector<int> w[2 * MAXN];
int used[2 * MAXN];
bool flag;

void dfs(int v, int tp = 0) {
    used[v] = tp;
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        if (used[u] != -1) {
            if ((used[u] ^ used[v] ^ w[v][i]) != 0) {
                flag = false;
                return;
            }
        } else {
            dfs(u, tp ^ w[v][i]);
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int n = sz(s);

    if (s[n - 1] == '1') {
        cout << 0 << endl;
        return 0;
    }
    s[n - 1] = '0';


    int res = 0;
    for (int m = 1; m < n; ++m) {   
        for (int i = 0; i < n + m; ++i) {
            g[i].clear();
            w[i].clear();
        }

        for (int i = 0; i < n - 1 - i; ++i) {   
            int u = i;
            int v = n - 1 - i;
            g[u].push_back(v);
            w[u].push_back(0);
            g[v].push_back(u);
            w[v].push_back(0);
        }

        for (int i = 0; i < m - 1 - i; ++i) {
            int u = i + n;
            int v = m - 1 - i + n;
            g[u].push_back(v);
            w[u].push_back(0);
            g[v].push_back(u);
            w[v].push_back(0);
        }

        for (int i = n - m; i < n; ++i) {
            if (s[i] == '?') {
                continue;
            }
            int u = i;
            int v = i + m;
            g[u].push_back(v);
            w[u].push_back(s[i] - '0');
            g[v].push_back(u);
            w[v].push_back(s[i] - '0');
        }

        // cout << m << endl;
        // if (m == 4) {
        //     for (int i = 0; i < n + m; ++i) {
        //         for (int j = 0; j < sz(g[i]); ++j) {
        //             cout << i << " " << g[i][j] << " " << w[i][j] << endl;
        //         }
        //     }
        // }


        memset(used, -1, sizeof(used));

        int cur = 1;
        flag = true;

        for (int i = 0; i < n - m; ++i) {
            if (s[i] != '?' && used[i] == -1) {
                dfs(i, s[i] - '0');
            }
        }

        // if (used[n] == 0) {
        //     flag = false;
        // } else if (used[n] == -1) {
        //     dfs(n, 0);
        // }

        for (int i = 0; i < n + m; ++i) {
            if (used[i] == -1) {
                dfs(i);
                add(cur, cur);
            }
        }

        for (int i = 0; i < n - m; ++i) {
            if (s[i] != '?' && used[i] != s[i] - '0') {
                flag = false;
            }
        }

        if (!flag) {
            cur = 0;
        }   

        // cout << m << ' ' << cur << endl;
        // cout << endl;

        add(res, cur);
    }

    cout << res << endl;
}