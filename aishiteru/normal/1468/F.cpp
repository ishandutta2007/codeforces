#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,u,v,x,y;
map<pair<int,int>,int> mp;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d %d",&u,&v,&x,&y);
			int aa=x-u,bb=y-v;
			int g=abs(__gcd(aa,bb));
			aa/=g,bb/=g;
			//cout<<aa<<' '<<bb<<endl;
			++mp[make_pair(aa,bb)];
		}
		long long ans=0;
		for(auto it:mp)
			ans+=1ll*it.second*mp[make_pair(-it.first.first,-it.first.second)];
		printf("%lld\n",ans/2);
	}
}