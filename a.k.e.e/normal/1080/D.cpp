#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll n,k;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cin>>n>>k;
		if(n<=31 && (1ll<<(2*n))<3*k+1)printf("NO\n");
		else
		{
			int t=1;
			bool flag=1;
			for(;t<=n;++t)
			{
				ll sum=0;
				for(int i=1;i<=t;i++)
					sum+=(1ll<<i)-1;
				if(sum>k)break;
				if(n>31 ||
					k*3<=((1ll<<(2*n-2*t))*((1ll<<t)-1)*((1ll<<t)-1)+(1ll<<(t+1))-2))
				{
					flag=0;
					printf("YES %I64d\n",n-t);
					break;
				}
			}
			if(flag)
				printf("NO\n");
		}
	}
    return 0;
}