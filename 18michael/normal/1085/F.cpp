#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
int to[202],l[3],r[3];
char s[200002];
set<int> st[3];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[200002];
	inline void modify(int x,int d)
	{
		while(x<=n)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}B[3];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void modify(int x,int o)
{
	if(o)st[to[s[x]]].insert(x),B[to[s[x]]].modify(x,1);
	else st[to[s[x]]].erase(x),B[to[s[x]]].modify(x,-1);
}
inline void solve(int R,int P,int S)
{
	if(l[P])
	{
		if(l[S])
		{
			if(l[P]<l[S]-1)ans-=B[R].query(l[S]-1)-B[R].query(l[P]);
			if(r[S]<r[P]-1)ans-=B[R].query(r[P]-1)-B[R].query(r[S]);
		}
		else ans-=B[R].query(n);
	}
}
inline void query()
{
	ans=n;
	for(int i=0;i<3;++i)
	{
		if(st[i].size())l[i]=(*st[i].begin()),r[i]=(*st[i].rbegin());
		else l[i]=r[i]=0;
	}
	solve(0,1,2),solve(1,2,0),solve(2,0,1),printf("%d\n",ans);
}
int main()
{
	read(n),read(q),scanf("%s",s+1),to['R']=0,to['P']=1,to['S']=2;
	for(int i=1;i<=n;++i)modify(i,1);query();
	for(int x;q--;)
	{
		read(x),modify(x,0);
		do s[x]=getchar();while(s[x]!='R' && s[x]!='P' && s[x]!='S');
		modify(x,1),query();
	}
	return 0;
}