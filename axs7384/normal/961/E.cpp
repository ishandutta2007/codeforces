#include <bits/stdc++.h>
using namespace std;
const int N=200005;
#define ll long long
#define lowbit(x) ((x)&(-(x)))
int f[N*2];
int n,x;
ll ans;
vector<int> v[N];
inline void read(int &x)
{
	char c=getchar();
	x=0;
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
inline void add(int x,int y)
{
	for (;x<=n;x+=lowbit(x))
		f[x]+=y;
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=lowbit(x))
		ans+=f[x];
	return ans;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		x=min(n,x);
		ans+=ask(x);
		if(x>i)
		{
			add(i,1);
			v[x].push_back(i);
		}
		for(unsigned j=0;j<v[i].size();++j)
			add(v[i][j],-1);
	}
	cout<<ans;
	return 0;
}