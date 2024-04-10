#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
	long long n,m;
	scanf("%I64d%I64d",&n,&m);
	long long g=gcd(n,m);
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int a,b;
        long long c,d;
        scanf("%d%I64d%d%I64d",&a,&c,&b,&d);
        c--;
        d--;
        long long one,two;
        if(a==1) one=(c/(n/g))%g;
        else one=(c/(m/g))%g;
        if(b==1) two=(d/(n/g))%g;
        else two=(d/(m/g))%g;
        if(one==two) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}