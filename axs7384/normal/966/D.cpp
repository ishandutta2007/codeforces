#include<bits/stdc++.h>
#define ll long long
#define push_back push_back
using namespace std;
const int N=300005,inf=1e9+7;
int n,m,f[N],q[N],h[N],ans;
vector<int> e[N],w;
map<ll,int> u;
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
inline int bfs(int x,int y)
{
	int l=0,r=1;
	f[x]=1;
	q[1]=x;
	while (l!=r)
	{
		++l;
		int now=q[l];
		for (unsigned j=0;j<e[now].size();++j)
		{
			int tmp=e[now][j];
			if (tmp!=y&&!f[tmp])
			{
				f[tmp]=f[now]+1;
				h[tmp]=now;
				q[++r]=tmp;
			}
		}
	}
	return r;
}
int x,y;
int main()
{
	read(n);
	read(m);
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		e[x].push_back(y);
		e[y].push_back(x);
		u[(ll)x*n+y]=u[(ll)y*n+x]=1;
	}
	bfs(1,0);
	if (f[n])
	{
		ans=f[n]-1;
		for (int i=n;i;i=h[i])
			w.push_back(i);
	}
	else
		ans=inf;
	for (int i=1;i<=n&&ans>4;++i)
		if (f[i]==3)
		{
			ans=4;
			w.clear();
			w.push_back(n);
			w.push_back(1);
			w.push_back(i);
			w.push_back(h[i]);
			w.push_back(1);
		}
	if (ans>5)
	{
		for (int i=1;i<=n;++i)
			f[i]=0;
		for (auto i:e[1])
			if (!f[i])
			{
				if (ans<=5)
					break;
				int k=bfs(i,1);
				for (int j=1;j<=k&&ans>5;j++)
					if (f[q[j]]==3)
					{
						ans=5;
				 		w.clear();
						w.push_back(n);
						w.push_back(i);
						w.push_back(q[j]);
						w.push_back(h[q[j]]);
						w.push_back(i);
						w.push_back(1);
					}
				for (int j=2;j<k&&ans>5;j++)
					for (int l=j+1;l<=k&&ans>5;l++)
						if (!u[(ll)q[j]*n+q[l]])
						{
							ans=5;
							w.clear();
							w.push_back(n);
							w.push_back(q[j]);
							w.push_back(q[l]);
							w.push_back(q[1]);
							w.push_back(q[j]);
							w.push_back(1);
						}
			}
		}
	if (ans==inf)
		puts("-1");
	else
		{
			cout<<ans<<endl;
			for (int i=ans;i>=0;i--)
		 		cout<<w[i]<<' ';
		}
	return 0;
}