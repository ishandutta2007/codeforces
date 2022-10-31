#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,t,x,a[N],i,s;
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	while(q--)
	{
		scanf("%d %d",&t,&x);
		if(t==1)
		{
			s-=a[x];
			a[x]^=1;
			s+=a[x];
		}
		else
			puts(x<=s?"1":"0");
	}
}