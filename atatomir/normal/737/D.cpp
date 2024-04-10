#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <assert.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2100
#define maxSQ 93

int n, i, j, k, l;
int v[2 * maxN];
int dp[maxSQ][2][maxN][2 * maxSQ];
bitset<2 * maxSQ> used[maxSQ][2][maxN];


int& get_state(int k, int u, int l, int r) {
    int auxi = maxSQ + l - (n - r);
    return dp[k][u][l][maxSQ + l - (n - r)];
}

int solve(int k, int u, int l, int r) {
    int& act = get_state(k, u, l, r);

    if (used[k][u][l][maxSQ + l - (n - r)] == true) return act;
    used[k][u][l][maxSQ + l - (n - r)] = true;

    if (u == 0) {
        if (r - l + 1 < k)
            return act = 0; // can't make any move

        // make a move of k
        act = solve(k, 1, l + k, r) + v[l + k - 1] - v[l - 1];

        //make a move of k + 1
        if (r - l + 1 >= k + 1)
            act = max(act, solve(k + 1, 1, l + k + 1, r) + v[l + k] - v[l - 1]);

    } else {
        if (r - l + 1 < k)
            return act = 0; // can't make any move

        // make a move of k
        act = solve(k, 0, l, r - k) - (v[r] - v[r - k]);

        // make a move of k + 1
        if (r - l + 1 >= k + 1)
            act = min(act, solve(k + 1, 0, l, r - k - 1) - (v[r] - v[r - k - 1]));
    }

    return act;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]), v[i] += v[i - 1];

    int ans = solve(1, 0, 1, n);
    printf("%d", ans);

    return 0;
}