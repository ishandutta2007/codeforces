#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N=100005*2;
int n;
int rt;
struct qq
{
	int x,y,last;
}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int tot[N];
int son[N];
multiset<int> s,s1,s2;//s:   s1:   s2:
multiset<int>::iterator it;
void dfs (int x,int fa)
{
	tot[x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		tot[x]=tot[x]+tot[y];
		if (tot[y]>tot[son[x]])	son[x]=y;
	}
	s.insert(tot[x]);
}
int ans[N];
void del (int x,int fa)// 
{
	it=s1.lower_bound(tot[x]);s1.erase(it);
	s.insert(tot[x]);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		del(y,x);
	}
}
void Ins (int x,int fa)
{
	it=s.lower_bound(tot[x]);s.erase(it);
	s1.insert(tot[x]);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		Ins(y,x);
	}
}
void print ()
{
	printf("OZY:\n");
	for (it=s.begin();it!=s.end();it++)
	{
		printf("%d ",(*it));
	}
	printf("\n");
}
void dfs1 (int x,int fa)
{
	s2.insert(tot[x]);
	it=s.lower_bound(tot[x]);s.erase(it);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		if (y==son[x]) continue;
		dfs1(y,x);del(y,x);
	}
	if (son[x]!=0)	dfs1(son[x],x);
	else
	{
		ans[x]=n-1;s1.insert(tot[x]);
		it=s2.lower_bound(tot[x]);s2.erase(it);
		return ;
	}
	int o=0,id,mn=tot[son[x]];
	int mx=tot[son[x]];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		if (y==son[x]) continue;
		/*if (x==1)
		{
			printf("hehe:%d %d\n",tot[y],mn);
		}*/
		if (tot[y]>o)	o=tot[y];
		mn=min(mn,tot[y]);
	}
//if (x==1)printf("TYB:%d %d\n",x,mn);
	if (fa!=0) mn=min(mn,n-tot[x]);	
	if (mx<n-tot[x])//
	{
		for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==son[x]||y==fa) continue;
		Ins(y,x);
	}
	//	printf("x:%d %d\n",x,o);
		if (n-tot[x]==tot[son[x]])// 
		{
			ans[x]=mx;
		}
		else
		{
			o=mx;
			mx=n-tot[x];
			int r=(mx-mn)/2;//
	/*	if (x==2)	
		{
			printf("YES:%d %d %d %d\n",x,mn,mx,r);print();
		}*/
			int lalal=0;
			int g=n;
			it=s.lower_bound(r+1);
			if (it!=s.end()) g=min(g,max(mx-(*it),mn+(*it)));
			//printf("first:%d\n",(*it));
			if (it!=s.begin())
			{
				it--;
			 	g=min(g,max(mx-(*it),mn+(*it)));
			}
			
			it=s2.lower_bound(r+1+tot[x]);
			if (it!=s2.end()) g=min(g,max(mx-((*it)-tot[x]),mn+((*it)-tot[x])));
			if (it!=s2.begin())
			{
				it--;
				g=min(g,max(mx-((*it)-tot[x]),mn+((*it)-tot[x])));
			}
			//	printf("ans:%d\n",g);
			ans[x]=max(o,g);
		}
	}
	else if (o==0&&fa==0)
	{
		ans[x]=n-1;
	}
	else// 
	{
		o=max(o,n-tot[x]);
		if (o==mx)
		{
			ans[x]=mx;
		}
		else
		{
			int r=(mx-mn)/2;
			int lalal=0;
			it=s1.lower_bound(r+1);	
			/*if (x==1)
			{
				printf("YES:%d mn:%d mx:%d r:%d %d\n",x,mn,mx,r,*it);
				//print();
			}*/
			//printf("YES:%d %d %d %d\n",x,*(--it),mn,fa);
			int g=n;
			//printf("lalal:%d\n",*it);
			if (it!=s1.end()) g=min(g,max(mn+(*it),mx-(*it)));
			if (it!=s1.begin()) 
			{
				it--;
				g=min(g,max(mn+(*it),mx-(*it)));
			}
			ans[x]=max(o,g);
		}
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (y==son[x]||y==fa) continue;
			Ins(y,x);
		}
	}
	s1.insert(tot[x]);
	it=s2.lower_bound(tot[x]);s2.erase(it);
	return ;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==0) rt=y;
		else	{init(x,y);init(y,x);}
	}
	dfs(rt,0);
	dfs1(rt,0);
//	printf("ans:%d\n",ans[4]);
	for (int u=1;u<=n;u++)
		printf("%d\n",ans[u]);
	return 0;
}