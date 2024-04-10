#include<bits/stdc++.h>
using namespace std;
const int N=100005;
string c,d,s[N];
map<string,int> mp;
int n,m,K,x;
vector<int> v[N];
int q[N],ds[N];
inline bool check(string a,string b)
{
	for (int i=0;i<K;++i)
		if (a[i]!=b[i]&&b[i]!='_')
			return 0;
	return 1;
}
int main()
{
	cin>>n>>m>>K;
	for (int i=1;i<=n;++i)
	{
		cin>>s[i];
		mp[s[i]]=i;
		// f[i]=1;
	}
	for (int i=1;i<=m;++i)
	{
		cin>>c;
		cin>>x;
		if (!check(c,s[x]))
		{
			// cout<<i<<"?\n";
			puts("NO");
			return 0;
		}
		for (int k=0;k<1<<K;++k)
		{
			d=c;
			for (int l=0;l<K;++l)
				if (k&(1<<l))
					d[l]='_';
			if (mp[d]&&mp[d]!=x)
			{
				int y=mp[d];
				++ds[y];
				v[x].push_back(y);
			}
		}
	}
	int r=0;
	// for (int i=1;i<=n;++i)
	// 	cout<<ds[i]<<' ';
	for (int i=1;i<=n;++i)
		if (!ds[i])
		{
			// cout<<i<<' ';
			q[++r]=i;
		}
	for (int i=1;i<=n;++i)
	{
		if (r<i)
		{
			puts("NO");
			return 0;
		}
		for (unsigned j=0;j<v[q[i]].size();++j)
		{
			--ds[v[q[i]][j]];
			if (ds[v[q[i]][j]]==0)
			{
				// cout<<v[q[i]][j]<<' ';
				q[++r]=v[q[i]][j];
			}
		}
	}
	puts("YES");
	for (int i=1;i<=n;++i)
		printf("%d ",q[i]);
	// for (int i=1;i<=n;++i)
	// {
	// 	cout<<f[i]<<' ';
	// 	v[f[i]].push_back(i);
	// }
	// puts("");
	// int sum=0;
	// for (int i=n;i;--i)
	// 	if (v[i].size())
	// 	{
	// 		ans[i]=v[i][0];
	// 		sum+=v[i].size();
	// 		if (sum>(n-i+1))
	// 		{
	// 			puts("NO");
	// 			return 0;
	// 		}
	// 	}
	// int now=n;
	// for (int i=n;i>=0;--i)
	// 	if (v[i].size())
	// 		for (unsigned j=min(1,i);j<v[i].size();++j)
	// 		{
	// 			while (ans[now])
	// 				--now;
	// 			ans[now]=v[i][j];
	// 		}
	// for (int i=1;i<=n;++i)
	// 	cout<<ans[i]<<' ';
	return 0;
}