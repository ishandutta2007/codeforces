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
typedef long double ld;

const int MAXN = 500000;

vector<int> g[MAXN];
int used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        v += n;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 0; i < n + m; ++i) {
        if (!used[i]) {
            ++ans;
            dfs(i);
        }
    }

    cout << ans - 1 << endl;

    return 0;
}