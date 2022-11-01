#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	long long x[n],p[m];
	for(int i=0;i<n;i++) scanf("%I64d",&x[i]);
	for(int i=0;i<m;i++) scanf("%I64d",&p[i]);
    long long d=x[1]-x[0];
    for(int i=1;i<n-1;i++) d=gcd(d,x[i+1]-x[i]);
    for(int i=0;i<m;i++)
    {
        if((d%p[i])==0)
        {
            printf("YES\n%I64d %d\n",x[0],i+1);
            return 0;
        }
    }
    printf("NO\n");
	return 0;
}