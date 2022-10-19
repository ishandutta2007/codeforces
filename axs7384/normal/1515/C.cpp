#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,k,x,y;
ll f[100005];
set<pair<ll,int> >s;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		s.clear();
		for (int i=1;i<=m;++i)
		{
			f[i]=0;
			s.insert(make_pair(f[i],i));
		}
		puts("YES");
		for (int i=1;i<=n;++i)
		{
			int x=s.begin()->second;
			scanf("%d",&y);
			printf("%d ",x);
			s.erase(s.begin());
			f[x]+=y;
			s.insert(make_pair(f[x],x));
		}
		puts("");
	}
	return 0;
}