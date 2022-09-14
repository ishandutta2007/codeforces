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

const int maxn = 3010;
const ll inf = (ll)1e18;

int k;
vector <int> v[maxn];
ll s[maxn];

const int maxlog = 20;
ll dp[maxlog][maxn];

void add(int d, int w, ll c) {
    for (int i = k - w; i >= 0; i--) {
        dp[d][i + w] = max(dp[d][i + w], dp[d][i] + c);
    }
}

ll go(int l, int r, int d) {
    if (l == r) {
        ll ans = -inf;
        ll cur = 0;

        for (int i = 0; i <= min(k, (int)v[l].size()); i++) {
            ans = max(ans, cur + dp[d][k - i]);

            if (i < (int)v[l].size()) {
                cur += v[l][i];
            }
        }

        return ans;
    }

    int m = (l + r) >> 1;

    memcpy(dp[d + 1], dp[d], sizeof dp[d]);

    for (int i = l; i <= m; i++) {
        add(d + 1, (int)v[i].size(), s[i]);
    }

    ll ans = go(m + 1, r, d + 1);

    memcpy(dp[d + 1], dp[d], sizeof dp[d]);
    for (int i = m + 1; i <= r; i++) {
        add(d + 1, (int)v[i].size(), s[i]);
    }

    ans = max(go(l, m, d + 1), ans);
    return ans;
}

int main() {
    int n;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        for (int j = 0; j < t; j++) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
            s[i] += x;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[0][i] = -inf;
    }

    cout << go(0, n - 1, 0) << '\n';
}