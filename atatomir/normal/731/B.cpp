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

#define maxN 200011

int n, i;
int a[maxN];
bool dp[maxN][2];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    dp[0][0] = true;
    for (i = 1; i <= n; i++) {
        if (dp[i - 1][1] == true && a[i] > 0)
            dp[i][ (a[i] - 1) % 2 ] = true;
        if (dp[i - 1][0] == true)
            dp[i][ a[i] % 2 ] = true;
    }

    if (dp[n][0] == true)
        printf("YES");
    else
        printf("NO");

    return 0;
}