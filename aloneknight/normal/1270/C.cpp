#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;ll s=0,x=0;
		scanf("%d",&n);
		for(int i=1,y;i<=n;i++){scanf("%d",&y);s+=y;x^=y;} 
		if(s==2*x)puts("0\n");
		else
		{
			ll b=1;b<<=50;if(s&1)b++;
			s+=b;x^=b;s=x-s/2;
			printf("3\n%lld %lld %lld\n",s,s,b);
		}
	}
	return 0;
}