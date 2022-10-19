#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005,M=10;
struct data
{
	int x,y;
	data operator +(const data &a)const
	{
		return (data){x+a.x,y+a.y};
	}
	data operator -(const data &a)const
	{
		return (data){x-a.x,y-a.y};
	}
	ll operator *(const data &a)
	{
		return (ll)x*a.y-(ll)y*a.x;
	}
	ll operator ^(const data &a)
	{
		return (ll)x*a.x+(ll)y*a.y;
	}
}a[M],b[N];
vector<int>p[M][N];
int n,K,kkk,ans,o[M],cnt,v[M],f[N],t;
bool on(data x,data y,data z)
{
	if ((x-y)*(x-z))
		return 0;
	return ((x-y)^(z-y))>0&&((x-z)^(y-z))>0;
}
bool check(int x)
{
	if (cnt==K+1)
		return 0;
	int now=o[cnt++];
	for (int i=0;i<p[now][x].size();++i)
		if ((f[p[now][x][i]]!=t)&&(!check(p[now][x][i])))
			return 0;
	f[x]=t;
	return 1;
}
bool dfs(int x)
{
	if (x==K+1)
	{
		++t;
		cnt=1;
		return check(kkk);
	}
	int b=0;
	for (int i=1;i<=K&&!b;++i)
		if (!v[i])
		{
			v[i]=1;
			o[x]=i;
			b=dfs(x+1);
			v[i]=0;
		}
	return b;
}
int main()
{
	//freopen("f.in","r",stdin);
	scanf("%d%d",&K,&n);
	for (int i=1;i<=K;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&b[i].x,&b[i].y);
	for (int i=1;i<=K;++i)
		for (int j=1;j<=n;++j)
			for (int k=1;k<=n;++k)
				if (on(b[k],a[i],b[j]))
					p[i][j].push_back(k);
	for (kkk=1;kkk<=n;++kkk)
		if (dfs(1))
			++ans;
	cout<<ans;
	return 0;
}