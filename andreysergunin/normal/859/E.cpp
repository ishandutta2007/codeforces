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
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 3e5;
const int P = 1e9 + 7;

vector<int> g[MAXN];
int used[MAXN];
bool vis[MAXN];

int dfs(int v) {
    used[v] = 2;
    int ans = 1;
    for (int u : g[v]) {
        ans += dfs(u);
        if (ans >= P)
            ans -= P;
    }
    return ans;
}

bool dfs2(int v) {
    used[v] = 1;
    bool ans = false;
    for (int u : g[v]) {
        if (used[u] == 1) {
            if (u != v)
                ans = true;
        } else if (used[u] == 0) {
            ans |= dfs2(u);
        }
    }
    used[v] = 2;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[v].push_back(u);
        vis[u] = true;
    }

    ll ans = 1;
    for (int i = 0; i < 2 * n; ++i) {
        if (vis[i])
            continue;
        ans *= dfs(i);
        ans %= P;
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            if (dfs2(i)) {
                ans *= 2;
                ans %= P;
            }
        }
    }
    cout << ans << endl;
}