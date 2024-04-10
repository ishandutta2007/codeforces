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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int P = 1e9 + 9;

const int MAXN = 200200;

vector<int> g[MAXN];
int del[MAXN];
int deg[MAXN];

void dfs1(int v, int p = -1) {
    del[v] = 1;
    cout << v + 1 << endl;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        } 
        if (!del[u]) {
            dfs1(u, v);
        }
    }
}

void dfs(int v, int p = -1) {
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
    int deg = sz(g[v]);
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        if (del[u]) {
            --deg;
        }
    }
    if (deg % 2 == 0) {
        dfs1(v, p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        if (p[i] != -1) {
            g[p[i]].push_back(i);
            g[i].push_back(p[i]);
        }
    }

    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }

    int e = 0;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) % 2 == 0) {
            ++e;
        }
    }

    if (e % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    dfs(0);

    return 0;
}