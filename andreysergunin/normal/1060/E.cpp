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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN= 200200;
vector<int> g[MAXN];

ll s[MAXN][2], cnt[MAXN][2];
ll res = 0;

void dfs(int v, int p = -1) {
    cnt[v][0] = 1;

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        for (int i = 0; i < 2; ++i) {
            cnt[v][i] += cnt[u][i ^ 1];
            s[v][i] += cnt[u][i ^ 1] + s[u][i ^ 1];
        }
    }

    ll cnt1[2] = {2, 0};
    ll s1[2] = {0, 0};

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        for (int i = 0; i < 2; ++i) {
            cnt1[i] += cnt[u][i ^ 1];
            
            for (int j = 0; j < 2; ++j) {
                cnt1[i ^ j] += (cnt[v][i] - cnt[u][i ^ 1]) * cnt[u][j ^ 1];
                s1[i ^ j] += (cnt[v][i] - cnt[u][i ^ 1]) * (s[u][j ^ 1] + cnt[u][j ^ 1]);
            }
        }
    }

    cnt1[0] /= 2;
    cnt1[1] /= 2;

    // assert(s1[0] % 2 == 0);
    // assert((s1[1] + cnt1[1]) % 2 == 0);

    res += s1[0] / 2;
    res += (s1[1] + cnt1[1]) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    cout << res << endl;

}