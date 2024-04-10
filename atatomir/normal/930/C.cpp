#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, m, i, l, r;
int sum[maxN];

int cnt;
int data[maxN];
int dp[2][maxN];
int ans;

void solve(int *dest) {
    int i;

    cnt = 0;
    for (i = 1; i <= n; i++) {
        int p = upper_bound(data + 1, data + cnt + 1, sum[i]) - data;
        if (p > cnt) cnt++;
        data[p] = sum[i];

        dest[i] = p;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &m, &n);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        sum[l]++;
        sum[r + 1]--;
    }

    for (i = 1; i <= n; i++) sum[i] += sum[i - 1];

    solve(dp[0]);
    reverse(sum + 1, sum + n + 1);
    solve(dp[1]);
    reverse(dp[1] + 1, dp[1] + n + 1);

    for (i = 1; i <= n; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);

    printf("%d\n", ans);


    return 0;
}