#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,a,b,t,k,f[N],x[N];
bool check(int m)
{
	int i;
	if(b-a<=m)
		return false;
	for(i=1;i<=m;++i)
		if(x[i]+m-i+1>=b)
			return false;
	//if(b-a==m)
	//	if(x[1]!=1)
	//		return false;
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&a,&b);
		if(a>b)
		{
			a=n-a+1;
			b=n-b+1;
		}
		for(i=1;i<=m;++i)
			scanf("%d",&x[i]);
		sort(x+1,x+1+m);
		int l=1,r=m+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid))
				l=mid+1;
			else
				r=mid;
		}
		printf("%d\n",l-1);
	}
}