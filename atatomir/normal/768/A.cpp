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

int n, i, cnt;
int a[maxN], mini, maxi;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    mini = a[1];
    maxi = a[n];

    for (i = 1; i <= n; i++)
        if (mini < a[i] && a[i] < maxi)
            cnt++;

    printf("%d", cnt);


    return 0;
}