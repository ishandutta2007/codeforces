#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i;
pair<int, int> tower[maxN];

int dp[maxN];
int ans;

int cb(int x) {
    int ans = 0;

    for (int step = 1 << 20; step > 0; step >>= 1) {
        if (ans + step <= n)
            if (tower[ans + step].first < x)
                ans += step;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &tower[i].first, &tower[i].second);

    sort(tower + 1, tower + n + 1);

    ans = n;
    for (i = 1; i <= n; i++) {
        int wh = cb(tower[i].first - tower[i].second);

        dp[i] = dp[wh] + i - wh - 1;
        ans = min(ans, dp[i] + n - i);
    }

    printf("%d", ans);


    return 0;
}