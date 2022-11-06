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

int n, m, i, x, y, ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m); ans = n;
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        ans = min(ans, y - x + 1);
    }

    printf("%d\n", ans);
    for (i = 0; i < n; i++)
        printf("%d ", i % ans);


    return 0;
}