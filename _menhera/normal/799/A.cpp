#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, k, d;
    scanf("%d%d%d%d",&n,&t,&k,&d);
    int time = t*((n+k-1)/k)-1;
    if(d > time) puts("NO");
    else if((time/t)*k + ((time-d)/t)*k>=n) puts("YES");
    else puts("NO");
    return 0+0;
}