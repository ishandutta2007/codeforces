#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
const LL N=500005;
const LL MAX=1e16;
LL n,q; 
vector<PI> vec[N];
LL L[N],R[N],id,dep[N];
void dfs (LL x)
{
	L[x]=R[x]=++id;LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u].first,z=vec[x][u].second;
		dep[y]=dep[x]+z;
		dfs(y);
		L[x]=min(L[x],L[y]);
		R[x]=max(R[x],R[y]);
	}
}
struct qq
{
	LL l,r;
	LL s1,s2;
	LL c,lzy;
}tr[N*2];LL num;
LL val[N];
void update (LL now)
{
	LL s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=min(tr[s1].c,tr[s2].c);
}
void Push_down (LL now)
{
	LL lzy=tr[now].lzy,s1=tr[now].s1,s2=tr[now].s2;
	if (lzy==0) return ;
	tr[s1].lzy+=lzy;tr[s1].c+=lzy;
	tr[s2].lzy+=lzy;tr[s2].c+=lzy;
	tr[now].lzy=0;
}
void bt (LL l,LL r)
{
	LL now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r)	{tr[now].c=val[l];return ;}
	LL mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	update(now);
}
LL query (LL now,LL l,LL r)
{
	if (tr[now].l==l&&tr[now].r==r) return tr[now].c;
	Push_down(now);
	LL mid=(tr[now].l+tr[now].r)>>1;
	LL s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) return query(s1,l,r);
	else if (l>mid) return query(s2,l,r);
	else return min(query(s1,l,mid),query(s2,mid+1,r));
}
void modify (LL now,LL l,LL r,LL c)
{
	if (tr[now].l==l&&tr[now].r==r)	{tr[now].c+=c;tr[now].lzy+=c;return ;}
	Push_down(now);
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) modify(s1,l,r,c);
	else if (l>mid) modify(s2,l,r,c);
	else modify(s1,l,mid,c),modify(s2,mid+1,r,c);
	update(now);
}
struct qt	
{
	LL id,l,r;
	qt () {}
	qt (LL _id,LL _l,LL _r)	{id=_id;l=_l;r=_r;}
};
LL ans[N];
vector<qt> Q[N];
void solve (LL x)
{
	LL siz=Q[x].size();
	for (LL u=0;u<siz;u++)
	{
		qt now=Q[x][u];
	//	printf("YES!\n");
		ans[now.id]=query(1,now.l,now.r)+dep[x];
	}
	siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u].first;
		modify(1,L[y],R[y],2*dep[x]-2*dep[y]);
		solve(y);
		modify(1,L[y],R[y],2*dep[y]-2*dep[x]);
	}
}
int main()
{
	scanf("%lld%lld",&n,&q);
	for (LL u=2;u<=n;u++)
	{
		LL x,w;
		scanf("%lld%lld",&x,&w);
		vec[x].push_back(make_pair(u,w));
	}
	for (LL u=1;u<=n;u++) sort(vec[u].begin(),vec[u].end());
	id=0;dfs(1);
/*	printf("\n");
	for (LL u=1;u<=n;u++) printf("%lld %lld %lld\n",u,L[u],R[u]);
	printf("\n");*/
	for (LL u=1;u<=n;u++)
	{
		if (vec[u].size()==0)	val[L[u]]=dep[u];
		else val[L[u]]=MAX;
	}
	bt(1,n);
	for (LL u=1;u<=q;u++)
	{
		LL v,l,r;
		scanf("%lld%lld%lld",&v,&l,&r);
		Q[v].push_back(qt(u,l,r));
	}
	solve(1);
	for (LL u=1;u<=q;u++) printf("%lld\n",ans[u]);
	return 0;
}