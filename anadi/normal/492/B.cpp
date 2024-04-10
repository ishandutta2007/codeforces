#include<iostream>
#include<vector>
#include<cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int t[1005];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    double mx=0.0;
    for(int i=0;i<n;++i)
        scanf("%d", &t[i]);
    sort(t,t+n);
    for(int i=1;i<n;++i)
        mx=max((double)(t[i]-t[i-1])/(double)2.0,mx);
    mx=max(mx,(double)max(t[0],l-t[n-1]));
    printf("%lf\n", mx);
    return 0;
}