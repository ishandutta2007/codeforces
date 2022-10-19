#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=100005;
#define ll long long
int K,n,m,x,y,z,Z[N],a[N];
pair<int,int> g[N];
vector<pair<int,int> > s[N];
vector<pair<double,int> > f;
inline void read(int &x)
{

	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int main()
{
	read(K);
	read(n);
	read(m);
	for (int i=1;i<=K;++i)
		read(a[i]);
	for (int i=1;i<=n;++i)
	{
		read(x);
		read(y);
		read(z);
		Z[i]=x;
		if (x==1)
			if (z>=g[y].first)
				g[y]=mp(z,i);
		if (x==2)
			s[y].push_back(mp(z,i));
		if (x==3)
			f.push_back(mp((double)z,i));
	}
	for (int i=1;i<=K;++i)
	{
		if (g[i].first>a[i])
			s[i].push_back(mp(g[i].first-a[i],g[i].second));
		sort(s[i].rbegin(),s[i].rend());
		ll sum=a[i];
		for (unsigned j=0;j<s[i].size();++j)
		{
			f.push_back(mp((double)(sum+s[i][j].first)/sum,s[i][j].second));
			sum+=s[i][j].first;
		}
	}
	sort(f.rbegin(),f.rend());
	m=min((int)f.size(),m);
	cout<<m<<'\n';
	for (int k=1;k<=3;++k)
		for (int j=0;j<m;++j)
			if (Z[f[j].second]==k)
				cout<<f[j].second<<' ';
	return 0;
}