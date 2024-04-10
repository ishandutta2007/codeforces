#include<bits/stdc++.h>
using namespace std;
int cnt=1;
const int N=300005;
int f[N*32];
int e[N*32][2];
pair<int,int> a[N];
int g[N];
int h[N];
int n,m;
inline int mx(int a,int b)
{
	return g[a]<g[b]?b:a;
}
inline void add(int x,int q)
{
	int ans=0;
	int p=1;
	// cout<<"!"<<x<<' '<<q<<endl;
	// cout<<x<<' '<<(x^m)<<endl;
	for (int i=30;i>=0;--i)
	{
		if (!p)
			break;
		int nx=(m>>i)&1;
		int tx=(x>>i)&1;
		if (nx==1)
		{
			p=e[p][!tx];
		}
		else
		{
			ans=mx(ans,f[e[p][!tx]]);
			p=e[p][tx];
		}
		// cout<<q<<' '<<i<<' '<<nx<<' '<<tx<<' '<<p<<' '<<g[f[p]]<<endl;
	}
	ans=mx(ans,f[p]);
	g[q]=g[ans]+1;
	h[q]=ans;
	// cout<<"!"<<ans<<' '<<q<<' '<<g[q]<<' '<<endl;
	p=1;
	f[p]=mx(f[p],q);
	for (int i=30;i>=0;--i)
	{
		int nx=(x>>i)&1;
		if (!e[p][nx])
			e[p][nx]=++cnt;
		p=e[p][nx];
		// cout<<q<<' '<<i<<' '<<p<<endl;
		f[p]=mx(f[p],q);
		// cout<<"?"<<q<<' '<<i<<' '<<p<<' '<<f[p]<<' '<<nx<<endl;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;++i)
		add(a[i].first,a[i].second);
	// cout<<f[1]<<' '<<g[f[1]]<<endl;
	int p=f[1];
	vector<int> ans;
	while (p)
	{
		ans.push_back(p);
		p=h[p];
	}
	if (ans.size()==1)
		puts("-1");
	else
	{
		cout<<(int)ans.size()<<endl;
		for (int x:ans)
			cout<<x<<' ';
	}

	// cout<<"???"<<e[31][1]<<endl;
	return 0;
}
/*
4 0
1 1 1 1
*/