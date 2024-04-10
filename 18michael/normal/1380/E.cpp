#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;bool ok;
int a[1000002],rt[1000002],mn[1000002],mx[1000002],id[1000002];
set<int> s[1000002];
set<int>::iterator it1,it2,it3;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline int solve(int x,int y)
{
	if(s[y].size()>s[x].size())swap(x,y);
	for(it1=s[y].begin();it1!=s[y].end();++it1)
	{
		it2=it3=s[x].lower_bound(*it1);
		if(it3!=s[x].begin())--it3,ok=1;else ok=0;
		if(it2!=s[x].end())
		{
			getroot(*it2),getroot(*it1);
			if(mx[rt[*it2]]+1==mn[rt[*it1]] || mx[rt[*it1]]+1==mn[rt[*it2]])mn[rt[*it1]]=min(mn[rt[*it1]],mn[rt[*it2]]),mx[rt[*it1]]=max(mx[rt[*it1]],mx[rt[*it2]]),rt[rt[*it2]]=rt[*it1],s[x].erase(it2),--ans;
		}
		if(ok)
		{
			getroot(*it3),getroot(*it1);
			if(mx[rt[*it3]]+1==mn[rt[*it1]] || mx[rt[*it1]]+1==mn[rt[*it3]])mn[rt[*it1]]=min(mn[rt[*it1]],mn[rt[*it3]]),mx[rt[*it1]]=max(mx[rt[*it1]],mx[rt[*it3]]),rt[rt[*it3]]=rt[*it1],s[x].erase(it3),--ans;
		}
		s[x].insert(*it1);
	}
	return x;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)id[i]=i;
	for(int i=1;i<=n;++i)
	{
		read(a[i]),rt[i]=mn[i]=mx[i]=i;
		if(i==1 || a[i-1]!=a[i])s[a[i]].insert(i),++ans;
		else rt[i]=rt[i-1],mx[rt[i]]=i;
	}
	printf("%d\n",ans);
	for(int x,y;--m;)read(x),read(y),id[x]=solve(id[x],id[y]),printf("%d\n",ans);
	return 0;
}