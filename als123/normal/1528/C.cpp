#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
vector<int> vec[N],vec1[N];
int T;
int n;
int L[N],R[N],num;
void dfs (int x)
{
	L[x]=++num;
	int siz=vec1[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec1[x][u];
		dfs(y);
	}
	R[x]=num;
}
struct qt
{
	int l,r;
	int s1,s2;
	int c;
	int bel;
}tr[N*2];
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	tr[now].c=tr[now].bel=0;
	if (l==r) return ;
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
}
int ans,cnt;
void change (int now,int l,int r,int c)
{
	if (tr[now].l==l&&tr[now].r==r)	{tr[now].bel=c;return ;}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) change(s1,l,r,c);
	else if (l>mid) change(s2,l,r,c);
	else {change(s1,l,mid,c);change(s2,mid+1,r,c);}
}
int query (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r) return tr[now].c;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) return query(s1,l,r);
	else if (l>mid) return query(s2,l,r);
	else {return query(s1,l,mid)+query(s2,mid+1,r);}
}
void add (int now,int x,int c)
{
	if (tr[now].l==tr[now].r)	{tr[now].c+=c;return ;}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) add(s1,x,c);
	else if (x>mid) add(s2,x,c);
	tr[now].c=tr[s1].c+tr[s2].c;
}
int upd (int now,int x)
{
	if (tr[now].bel!=0)
	{
		int bel=tr[now].bel;
		return bel;
	}
	if (tr[now].l==tr[now].r) return -1;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) return upd(s1,x);
	else return upd(s2,x);
	//printf("?\n");
}
void solve (int x)
{
	int t=upd(1,L[x]);
	if (t!=-1)	{change(1,L[t],R[t],0);add(1,L[t],-1);cnt--;}
	bool tf=false;
	if (query(1,L[x],R[x])==0)
	{
		tf=true;
	//	printf("change:%d\n",x);
		change(1,L[x],R[x],x);
		add(1,L[x],1);cnt++;
	}
	//printf("%d %d\n",x,cnt);
	ans=max(ans,cnt);
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		solve(y);
	}
	if (tf)	{change(1,L[x],R[x],0);add(1,L[x],-1);cnt--;}
	if (t!=-1) {change(1,L[t],R[t],t);add(1,L[t],1);cnt++;/*printf("change:%d\n",t);*/}
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		num=0;
		scanf("%d",&n);
		for (int u=1;u<=n;u++) {vec[u].clear();vec1[u].clear();}
		for (int u=2;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			vec[x].push_back(u);
		}
		for (int u=2;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			vec1[x].push_back(u);
		}
		dfs(1);
		num=0;bt(1,n);
		ans=cnt=0;solve(1);
		printf("%d\n",ans);
	}
	return 0;
}