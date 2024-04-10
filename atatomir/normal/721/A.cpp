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

#define maxN 111

int n, i;
char s[maxN];
int dp[maxN];

vector<int> ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (i = 1; i <= n; i++) {
        if (s[i] != 'B') continue;

        dp[i] = dp[i - 1] + 1;
        if (s[i + 1] != 'B')
            ans.pb(dp[i]);
    }

    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d ", e);


    return 0;
}