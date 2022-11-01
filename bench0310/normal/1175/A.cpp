#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        long long n,k;
        scanf("%I64d%I64d",&n,&k);
        long long res=0;
        while(n>0)
        {
            res+=(n-(n/k)*k);
            n-=(n-(n/k)*k);
            n/=k;
            if(n>0) res++;
        }
        printf("%I64d\n",res);
    }
	return 0;
}