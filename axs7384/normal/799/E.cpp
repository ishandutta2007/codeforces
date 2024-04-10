#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mu multiset<int>
#define iter iterator
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
const int N=200005,inf=1e18;
int a[N],b[N],c[4][N],n,m,K,ans,p,x,d[N],sum,si,f[4][N],pos[4];
/*mu::iter it;
mu s1,s2;
inline void add(int x)
{
	if (s1.size()<si)
	{
		sum+=x;
		s1.insert(x);
	}
	else
	{
		if (si>0)
		{
			s1.insert(x);
			it=--s1.end();
			sum+=x-*it;
			s2.insert(*it);
			s1.erase(it);
		}
		else
			s2.insert(x);
	}
}*/
int getcnt(int t,int x,int y)
{
	for (int i=0;i<4;i++)
	{
		pos[i]=upper_bound(c[i],c[i]+d[i],t)-c[i];
		if (i==3) 
			pos[i]=max(pos[i],x);
		else 
			if (i) 
				pos[i]=max(pos[i],y);
	}
	return pos[0]+pos[1]+pos[2]+pos[3];
}
signed main()
{
	//freopen("g.in","r",stdin);
	read(n);
	read(m);
	read(K);
	for (int i=1;i<=n;++i)
		read(a[i]);
	for (int j=1;j<=2;++j)
	{
		read(p);
		for (int i=1;i<=p;++i)
		{
			read(x);
			b[x]+=j;
		}
	}
	for (int i=1;i<=n;++i)
		c[b[i]][d[b[i]]++]=a[i];
	for (int i=0;i<=3;++i)
		sort(c[i],c[i]+d[i]);
	ans=inf;
	for (int i=0;i<=3;++i)
		for (int j=1;j<=d[i];++j)
			f[i][j]=f[i][j-1]+c[i][j-1];
	/*si=m-2*K-1;
	if (si==0)
	{
		for (int i=1;i<=d[0];++i)
			s2.insert(c[0][i]-c[0][i-1]);
		for (int i=K+2;i<=d[1];++i)
			s2.insert(c[1][i]-c[1][i-1]);
		for (int i=K+2;i<=d[2];++i)
			s2.insert(c[2][i]-c[2][i-1]);
	}
	else
	{
		for (int i=1;i<=d[0];++i)
			add(c[0][i]-c[0][i-1]);
		for (int i=K+2;i<=d[1];++i)
			add(c[1][i]-c[1][i-1]);
		for (int i=K+2;i<=d[2];++i)
			add(c[2][i]-c[2][i-1]);
	}*/
	/*for (int i=0;i<=min(d[3],m);++i)
	{
		if (i<=K)
		{
			++si;
			if (si>0&&s2.size()!=0)
			{
				it=s2.begin();
				sum+=*it;
				s1.insert(*it);
				s2.erase(it);
			}
		}
		else
		{
			--si;
			if (si>=0&&s1.size()!=0)
			{
				it=--s1.end();
				sum-=*it;
				s2.insert(*it);
				s1.erase(it);
			}
		}
		if (K-i+1<=d[1]&&K-i+1>=1)
			add(c[1][K-i+1]-c[1][K-i]);
		if (K-i+1<=d[2]&&K-i+1>=1)
			add(c[2][K-i+1]-c[1][K-i]);
		if (i+(K-i)*2>m||K-i>d[1]||K-i>d[2]||(si!=s1.size()&&si>0))
			continue;
		ans=min(ans,c[3][i]+c[1][K-i]+c[2][K-i]+sum);
	}*/
	for (int i=0;i<=K&&i<=d[3];i++)
	{
		if (K-i>min(d[1],d[2])) 
			continue;
		if (K*2-i>m) 
			continue;
		int l=0,r=1e9;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (getcnt(mid,i,K-i)>=m)
				r=mid;
			else 
				l=mid+1;
		}
		int cnt=getcnt(l,i,K-i);
		int tmp=0;
		for (int j=0;j<4;j++)
			tmp+=f[j][pos[j]];
		tmp-=(cnt-m)*l;
		ans=min(ans,tmp);
	}
	if (ans==inf)
		puts("-1");
	else
		cout<<ans;
	return 0;
}