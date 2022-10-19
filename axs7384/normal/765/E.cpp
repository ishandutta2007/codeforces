#include<bits/stdc++.h>
using namespace std;
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
const int N=200010;
int cnt,x,y,n,ans,v,to[N*2],pr[N*2],la[N];
inline void add(int x,int y)
{
	to[++cnt]=y;
	pr[cnt]=la[x];
	la[x]=cnt;
}
int dfs(int x,int fa)
{
	set<int> s;
	for (int i=la[x];i;i=pr[i])
		if (to[i]!=fa)
		{
			int k=dfs(to[i],x);
			if (k==-1)
				return -1;
			s.insert(k+1);
		}
	if (!s.size())
		return 0;
	if (s.size()==1)
		return *s.begin();
	if (!fa&&s.size()==2)
		return *s.begin()+(*(--s.end()));
	v=x;
	return -1;
}
int main()
{
	read(n);
	for (int i=1;i<n;++i)
	{
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	ans=dfs(1,0);
	if (ans==-1&&v)
		ans=dfs(v,0);
	for (;ans&&!(ans&1);ans/=2);
	cout<<ans;
	return 0;
}