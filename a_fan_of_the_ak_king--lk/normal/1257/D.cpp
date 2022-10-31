#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=1000000007;
int n,a[200005],ans,i,m,t,j,mx;
struct str{
	int p,s;
	bool operator <(const str &a)const
	{
		return p<a.p;
	}
}p[200005];
bool cmp(str a,str b)
{
	if(a.p==b.p)
		return a.s<b.s;
	return a.p<b.p;
}
set<str> s;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=1;i<=m;++i)
			scanf("%d %d",&p[i].p,&p[i].s);
		sort(p+1,p+1+m,cmp);
		s.clear();
		s.insert(p[m]);
		for(i=m-1;i>=1;--i)
			if(p[i].s>s.begin()->s)
				s.insert(p[i]);
		i=1;
		bool flag=true;
		ans=0;
		while(i<=n&&flag)
		{
			++ans;
			mx=0;
			for(j=i;j<=n;++j)
			{
				mx=max(mx,a[j]);
				set<str>::iterator it=s.lower_bound((str){mx,0});
				if(it==s.end())
				{
					flag=false;
					break;
				}
				if(i+it->s<=j)
				{
					i=j;
					break;
				}
			}
			if(j>n)
				break;
		}
		if(!flag)
			puts("-1");
		else
			printf("%d\n",ans);
	}
}