#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

int n, i, j;
ll a[4][maxN];
ll sum_up[maxN], sum_down[maxN], sum[maxN];


map<ll, int> M_up, M_down, M;
int next_up[maxN], next_down[maxN], next_both[maxN];

int dp[maxN];
pair<int, int> dp_up[maxN], dp_down[maxN];

pair<int, int> best(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return a;
    if (a.first < b.first)
        return b;

    if (a.second < b.second)
        return a;
    return b;
}

void extend(int u, int d, int v) {
    if (u > n || d > n)
        return;

    if (u == d) {
        dp[u] = max(dp[u], v);
    } else {
        if (u < d) {
            dp_up[u] = best(dp_up[u], mp(v, d));
        } else {
            dp_down[d] = best(dp_down[d], mp(v, u));
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[1][i]);
        sum_up[i] = sum_up[i - 1] + a[1][i];
        sum[i] = sum_up[i];
    }

     for (i = 1; i <= n; i++) {
        scanf("%lld", &a[2][i]);
        sum_down[i] = sum_down[i - 1] + a[2][i];
        sum[i] += sum_down[i];
    }

    next_up[n + 1] = next_down[n + 1] = next_both[n + 1] = -1;
    for (i = n; i > 0; i--) {
        next_up[i] = next_up[i + 1];
        next_down[i] = next_down[i + 1];
        next_both[i] = next_both[i + 1];

        M_up[sum_up[i]] = i;
        M_down[sum_down[i]] = i;
        M[sum[i]] = i;

        if (M_up[sum_up[i - 1]]) {
            next_up[i] = M_up[sum_up[i - 1]];
        }

        if (M_down[sum_down[i - 1]]) {
            next_down[i] = M_down[sum_down[i - 1]];
        }

        if (M[sum[i - 1]]) {
            next_both[i] = M[sum[i - 1]];
        }
    }

    for (i = 1; i <= n; i++) {
        dp[i] = 0;
        dp_up[i] = dp_down[i] = mp(-1, n + 1);
    }

    for (i = 0; i <= n; i++) {
        if (next_up[i + 1] >= i + 1)
            dp_down[i] = best(dp_down[i], mp(dp[i] + 1, next_up[i + 1]));

        if (next_down[i + 1] >= i + 1)
            dp_up[i] = best(dp_up[i], mp(dp[i] + 1, next_down[i + 1]));

        extend(i, i + 1, dp[i]);
        extend(i + 1, i, dp[i]);
        extend(i + 1, i + 1, dp[i]);

        if (dp_up[i].first != -1) {
            extend(i + 1, dp_up[i].second, dp_up[i].first);
            extend(i, dp_up[i].second + 1, dp_up[i].first);

            if (next_up[i + 1] >= i + 1)
                extend(next_up[i + 1], dp_up[i].second, dp_up[i].first + 1);
        }

        if (dp_down[i].first != -1) {
            extend(dp_down[i].second + 1, i, dp_down[i].first);
            extend(dp_down[i].second, i + 1, dp_down[i].first);

            if (next_down[i + 1] >= i + 1)
                extend(dp_down[i].second, next_down[i + 1], dp_down[i].first + 1);
        }

        if (next_both[i + 1] >= i + 1)
            extend(next_both[i + 1], next_both[i + 1], dp[i] + 1);
    }

    printf("%d", dp[n]);



    return 0;
}