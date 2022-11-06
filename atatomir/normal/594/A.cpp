#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, i, how;
int v[maxN];
int ans = 1000000001;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);

    how = (n - 2 + 1) / 2;
    how = n - how - 1;

    for (i = 1; i + how <= n; i++)
        ans = min(ans, v[i + how] - v[i]);

    printf("%d", ans);


    return 0;
}