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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

vector<vector<int>> g, cost;

int dfs(int v, int p = -1) {
    int ans = 0;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i] == p)
            continue;
        ans = max(dfs(g[v][i], v) + cost[v][i], ans);
    }
    return ans;
}

int main() {
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    g.resize(n);
    cost.resize(n);

    for (int i = 0; i < n - 1;  ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(v);
        cost[u].push_back(c);
        g[v].push_back(u);
        cost[v].push_back(c);
    }

    cout << dfs(0) << endl;


}