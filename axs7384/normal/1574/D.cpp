#include<bits/stdc++.h>
using namespace std;
set<vector<int> > ban;
int n,len[10],m;
int a[10][200005];
// struct cmp
// {
// 	bool operator()(const vector<int> &f,const vector<int> &g)
// 	{
		// int x,y;
		// for (int i=0;i<n;++i)
		// {
		// 	x+=a[i][f[i]];
		// 	y+=a[i][g[i]];
		// }
		// return x<y;
// 	}
// }
struct VEC
{
	vector<int> v;
	int q;
	bool operator<(const VEC &g)const
	{
		return q==g.q?v<g.v:q<g.q;
	}
};
vector<int> vec;
inline int calc()
{
	int x=0;
	for (int i=0;i<n;++i)
		x+=a[i][vec[i]];
	return x;
}
set<VEC> q;
// priority_queue<vector<int> ,vector<vector<int> >, cmp> q;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		scanf("%d",&len[i]);
		for (int j=1;j<=len[i];++j)
			scanf("%d",&a[i][j]);
	}
	scanf("%d",&m);
	// cout<<"!"<<m<<endl;
	vec.resize(n);
	for (int i=1;i<=m;++i)
	{
		for (int j=0;j<n;++j)
			scanf("%d",&vec[j]);
		// puts("???");
		ban.insert(vec);
	}
	for (int i=0;i<n;++i)
		vec[i]=len[i];
	q.insert({vec,calc()});
	while (!q.empty())
	{
		auto it=q.end();
		--it;
		vec=it->v;
		q.erase(it);
		if (!ban.count(vec))
		{
			for (int i=0;i<n;++i)
				printf("%d ",vec[i]);
			return 0;
		}
		for (int i=0;i<n;++i)
			if (vec[i]!=1)
			{
				--vec[i];
				q.insert({vec,calc()});
				++vec[i];
			}
		while (q.size()>m+1)
			q.erase(q.begin());
	}
	return 0;
}