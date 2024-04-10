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

vector<vector<int>> g;
vector<int> used;

pair<ll, ll> dfs(int v) {
    used[v] = true;
    pair<ll, ll> res = {1, sz(g[v])};
    for (int u : g[v]) {
        if (used[u])
            continue;
        pair<ll, ll> p = dfs(u);
        res.first += p.first;
        res.second += p.second;
    }
    return res;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            pair<ll, ll> p = dfs(i);
            if (p.first * (p.first - 1) != p.second) {
                cout << "NO" << endl;
                return 0;
            }
        } 
    }
    cout << "YES" << endl;

    return 0;
}