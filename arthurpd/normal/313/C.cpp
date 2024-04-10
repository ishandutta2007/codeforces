#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a,int b)
{ return a > b; }
int a[2123456];
long long sum[2123456];

int
main(void)
{
    int n, i, j = 1;
    long long ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a,a+n,comp);
    for(i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i-1];
    for(i = 1; i <= n; i <<= 2)
        ans += sum[i];
    cout << ans << '\n';
    return 0;
}