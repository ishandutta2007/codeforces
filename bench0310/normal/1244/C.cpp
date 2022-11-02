#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,p,w,d;
	scanf("%I64d%I64d%I64d%I64d",&n,&p,&w,&d);
    for(long long y=0;y<=w-1;y++)
    {
        if(((p-y*d)%w)!=0) continue;
        long long x=(p-y*d)/w;
        long long z=n-x-y;
        if(z<0||x<0) continue;
        printf("%I64d %I64d %I64d\n",x,y,z);
        return 0;
    }
    printf("-1\n");
	return 0;
}