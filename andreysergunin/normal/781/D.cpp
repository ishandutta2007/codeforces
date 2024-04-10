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
mt19937 rr(random_device{}());

vector<vector<int>> foot;
vector<vector<int>> byc;

const int MAXN = 510;
const int MAXD = 62;
bitset<MAXN> dp0[MAXN][MAXD];
bitset<MAXN> dp1[MAXN][MAXD];

vector<vector<ll>> dist;

const ll INF = 1000000000000000001;

int n, m;


ll solve(int v, int type, int lim) {
    if (dist[v][type] != -1)
        return dist[v][type];

    // cout << v << " " << type << " " << lim << endl;

    ll ans = 0;
    for (ll k = lim; k >= 0; --k) {
        for (int i = 0; i < n; ++i) {
            if (type) {
                if (dp1[v][k][i]) {
                    dist[v][type] = max(dist[v][type], (1ll << k) + solve(i, 0, k - 1));
                    dist[v][type] = min(dist[v][type], INF);
                }
            } else {
                if (dp0[v][k][i]) {
                    dist[v][type] = max(dist[v][type], (1ll << k) + solve(i, 1, k - 1));
                    dist[v][type] = min(dist[v][type], INF);
                }
            }
        }
        if (dist[v][type] != -1)
            return dist[v][type]; 
    }

    
    dist[v][type] = 0;
    return dist[v][type];
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, type;
        cin >> u >> v >> type;
        --u; --v;
        if (type)
            dp1[u][0][v] = 1;
        else 
            dp0[u][0][v] = 1;
    }

    for (int k = 1; k <= 60; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp0[i][k - 1][j]) {
                    dp0[i][k] |= dp1[j][k - 1];
                }
                if (dp1[i][k - 1][j]) {
                    dp1[i][k] |= dp0[j][k - 1];
                }
            }   
        }
    }

    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         for (int k = 0; k < n; ++k)
    //             cout << dp0[j][i][k] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;

    //     for (int j = 0; j < n; ++j) {
    //         for (int k = 0; k < n; ++k)
    //             cout << dp1[j][i][k] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    //     cout << endl;
    // }

    dist.resize(n, vector<ll>(2, -1));

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, solve(i, 0, 60));

    // for (int i = 0; i < n; ++i) {
    //     cout << dist[i][0] << " " << dist[i][1] << endl;
    // }

    cout << (ans == INF ? -1 : ans) << endl;
}