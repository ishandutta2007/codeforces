#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,P=1000000007;
typedef long double lb;
int n,i,j;
long long s,ans;
struct str{
	int a,t;
}x[N];
bool cmp(str a,str b)
{
	return a.a<b.a;
}
priority_queue<int> q;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&x[i].a);
	for(i=1;i<=n;++i)
		scanf("%d",&x[i].t);
	sort(x+1,x+1+n,cmp);
	for(i=1;i<=n;)
	{
		for(j=x[i].a-x[i-1].a;j&&!q.empty();--j)
		{
			s-=q.top();
			q.pop();
			ans+=s;
		}
		for(j=i;x[i].a==x[j].a&&j<=n;++j)
		{
			q.push(x[j].t);
			s+=x[j].t;
		}
		i=j;
	}
	while(!q.empty())
	{
		s-=q.top();
		q.pop();
		ans+=s;
	}
	cout<<ans;
}