#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
int dp[maxn][2];
int c[maxn];

int ans;

void remax(pii &a, int b) {
    if (a.first < b) {
        a.second = a.first;
        a.first = b;
    }
    else if (a.second < b) {
        a.second = b;
    }
}

void dfs(int v, int p) {
    pii f[2];
    f[0] = f[1] = mp(0, 0);

    for (int u : ed[v]) {
        if (u == p) {
            continue;
        }

        dfs(u, v);
        remax(f[0], dp[u][0]);
        remax(f[1], dp[u][1]);
    }

    if (c[v] == 2) {
        ans = max(ans, f[0].first + f[1].first);
        ans = max(ans, f[0].first + f[0].second - 1);
        ans = max(ans, f[1].first + f[1].second - 1);
        ans = max(ans, f[0].first);
        ans = max(ans, f[1].first);
        dp[v][0] = f[0].first;
        dp[v][1] = f[1].first;
    }
    else {
        int cl = c[v];
        ans = max(ans, f[cl ^ 1].first + f[cl ^ 1].second + 1);
        ans = max(ans, f[cl].first + f[cl ^ 1].first);
        ans = max(ans, f[cl].first + f[cl].second - 1);
        ans = max(ans, f[cl].first);
        dp[v][cl ^ 1] = 0;
        dp[v][cl] = max(f[cl].first, f[cl ^ 1].first + 1);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            c[i] = 2 - c[i];
            ed[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        ans = 0;
        dfs(0, -1);
        cout << ans / 2 + 1 << '\n';
    }
}