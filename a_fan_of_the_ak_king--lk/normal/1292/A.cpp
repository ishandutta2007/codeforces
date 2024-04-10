#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=100005,E=262144;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
int n,q,a[3][N],ans,x,y;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		--x;
		if(a[x][y]==1)
			ans-=a[x^1][y-1]+a[x^1][y]+a[x^1][y+1];
		else
			ans+=a[x^1][y-1]+a[x^1][y]+a[x^1][y+1];
		a[x][y]^=1;
		puts(ans?"No":"Yes");
	}
}