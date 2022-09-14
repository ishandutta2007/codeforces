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
typedef double ld;

const int P = 1e9 + 7;
const int MAXN = 1e5 + 100;
const int MAXK = 11;

void add(int &a, int b) {
    a += b;
    if (a >= P)
        a -= P;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0)
        a += P;
}

void mul(int &a, int b) {
    ll ans = (ll)a * b;
    ans %= P;
    a = ans;
}

int dp[MAXN][3][MAXK];

vector<int> g[MAXN];
int n, m;
int k, x;

void dfs(int v, int p) {
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }

    dp[v][0][0] = 1;
    dp[v][1][1] = 1;
    dp[v][2][0] = 1;

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        vector<int> arr(x + 1);

        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= x - i; ++j) {
                int p = dp[u][0][j];
                mul(p, k - 1);

                int q = dp[u][1][j];

                int r = dp[u][2][j];
                mul(r, m - k);

                int tmp = p;
                add(tmp, q);
                add(tmp, r);

                mul(tmp, dp[v][0][i]);
                
                add(arr[i + j], tmp);
            }
        }

        for (int i = 0; i <= x; ++i) {
            dp[v][0][i] = arr[i];
        }

        arr.assign(x + 1, 0);

        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= x - i; ++j) {
                int p = dp[u][0][j];
                mul(p, k - 1);

                int tmp = p;

                mul(tmp, dp[v][1][i]);
                add(arr[i + j], tmp);
            }
        }

        for (int i = 0; i <= x; ++i) {
            dp[v][1][i] = arr[i];
        }


        arr.assign(x + 1, 0);
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= x - i; ++j) {
                int p = dp[u][0][j];
                mul(p, k - 1);

                int r = dp[u][2][j];
                mul(r, m - k);

                int tmp = p;
                add(tmp, r);

                mul(tmp, dp[v][2][i]);
                
                add(arr[i + j], tmp);
            }
        }
        
        for (int i = 0; i <= x; ++i) {
            dp[v][2][i] = arr[i];
        }
    }
}

int main() {
    //freopen("comb.in", "r", stdin);
    //freopen("comb.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k >> x;

    dfs(0, -1);


    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        // cout << dp[0][0][i] << " " << dp[0][1][i] << " " << dp[0][2][i] << endl;
        int tmp = dp[0][0][i];
        mul(tmp, k - 1);
        add(ans, tmp);
        tmp = dp[0][1][i];
        add(ans, tmp);
        tmp = dp[0][2][i];
        mul(tmp, m - k);
        add(ans, tmp);
    }
    cout << ans << endl;
}