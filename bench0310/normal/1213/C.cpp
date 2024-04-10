#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        long long n,m;
        scanf("%I64d%I64d",&n,&m);
        long long t=n/m;
        long long a=0;
        long long b=m%10;
        for(long long i=1;i<=10;i++) a+=((b*i)%10);
        long long res=((t/10)*a);
        for(long long i=1;i<=(t%10);i++) res+=((b*i)%10);
        printf("%I64d\n",res);
    }
	return 0;
}