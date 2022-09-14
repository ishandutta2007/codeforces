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
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 2000;

vector<int> g[MAXN];
int s[MAXN];

map<pii, int> mapa;

int good[MAXN];

int dfs(int v, int p = -1) {
    s[v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            s[v] += dfs(u, v);
        }
    }
    return s[v];
}

void dfs1(int v, int step, int &glob, int cur, int p = -1) {
    for (int u : g[v]) {
        if (p == -1) {
            if (good[u]) {
                glob += step;
                mapa[{v, u}] = glob;
                dfs1(u, step, glob, glob, v);
            }
            continue;
        } 
        if (u == p) {
            continue;
        }
        glob += step;
        mapa[{v, u}] = glob - cur;
        dfs1(u, step, glob, glob, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);      
    
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);

    int cen = -1;

    for (int i = 0; i < n; ++i) {
        bool ok = (n - s[i] <= n / 2);
        for (int u : g[i]) {
            if (s[u] < s[i]) {
                ok &= (s[u] <= n / 2);
            }
        }
        if (ok) {
            cen = i;
            break;
        }
    }

    assert(cen != -1);
    dfs(cen);

    vector<int> sum(2);
    vector<vector<int>> arr(2);

    vector<pii> a;

    for (int u : g[cen])  {
        a.push_back({s[u], u});
    }

    sort(all(a));
    reverse(all(a));

    for (int i = 0; i < sz(a); ++i) {
        int k = (sum[0] <= sum[1] ? 0 : 1);
        sum[k] += a[i].first;
        arr[k].push_back(a[i].second);
    }

    for (int u : arr[0]) {
        good[u] = true; 
    }

    int glob = 0;
    dfs1(cen, 1, glob, 0);

    for (int u : arr[0]) {
        good[u] = false; 
    }
    for (int u : arr[1]) {
        good[u] = true; 
    }

    int step = glob + 1;
    glob = 0;
    dfs1(cen, step, glob, 0);


    for (auto el : mapa) {
        cout << el.first.first + 1 << " " << el.first.second + 1 << " " << el.second << endl;
    }
}