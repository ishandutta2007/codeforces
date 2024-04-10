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

int n, h, i, x;
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &h);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        ans += (x <= h ? 1 : 2);
    }

    printf("%d", ans);


    return 0;
}