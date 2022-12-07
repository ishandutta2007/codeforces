#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
const LL MAX=1e15;
vector<LL> vec[N];
LL n;
LL tot[N];
LL mn;
LL f[N];
LL calc (LL x)	{return x*(x-1)/2;}
struct qq
{
	LL l,r;
	LL s1,s2;
	LL k,b;
}tr[N*2];LL num;
void bt (LL l,LL r)
{
	LL now=++num;
	tr[now].l=l;tr[now].r=r;
	tr[now].b=MAX;tr[now].k=0;
	if (l==r) return ;
	LL mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
}
vector<LL> del;
LL tim[N*2],TT;
LL calc1 (LL x,LL k,LL b)	{return x*k+b;}
void modify (LL now,LL k,LL b)
{
	if (tim[now]!=TT)
	{
		tim[now]=TT;
		del.push_back(now);
	}
	//printf("%lld %lld\n",tr[now].l,tr[now].r);
	if (tr[now].l==tr[now].r)
	{
		if (calc1(tr[now].l,k,b)<calc1(tr[now].l,tr[now].k,tr[now].b))	{tr[now].k=k;tr[now].b=b;}
		return ;
	}
	LL mid=(tr[now].l+tr[now].r)>>1;
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL A=calc1(mid,k,b),B=calc1(mid,tr[now].k,tr[now].b);
//printf("%lld %lld\n",A,B);
	if (A>=B)
	{
		if (tr[now].k<=k) modify(s1,k,b);
		else modify(s2,k,b);
	}
	else
	{
		if (tr[now].k<=k) modify(s2,tr[now].k,tr[now].b);
		else modify(s1,tr[now].k,tr[now].b);
		//printf("YES!\n");
		tr[now].k=k;tr[now].b=b;
	}
}
LL query (LL now,LL x)
{
	if (tr[now].l==tr[now].r) return calc1(x,tr[now].k,tr[now].b);
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	//printf("query:%lld %lld\n",tr[now].k,calc1(x,tr[now].k,tr[now].b));
	if (x<=mid) return min(calc1(x,tr[now].k,tr[now].b),query(s1,x));
	else return min(calc1(x,tr[now].k,tr[now].b),query(s2,x));
}
void dfs (LL x,LL fa)
{
	LL siz=vec[x].size();tot[x]=1;
	if (fa!=0&&siz==1)	{f[x]=0;return ;}
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x);tot[x]=tot[x]+tot[y];
	}
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		f[x]=min(f[x],f[y]+calc(tot[x]-tot[y]));
		mn=min(mn,f[y]+calc(n-tot[y]));
	}
	/*for (LL u=0;u<siz;u++)if (vec[x][u]!=fa)
	for (LL i=u+1;i<siz;i++)if (vec[x][i]!=fa)
	{
		LL xx=vec[x][u],yy=vec[x][i];
		LL t=n-tot[xx];
		//mn=min(mn,f[xx]+f[yy]+calc(n-tot[xx]-tot[yy]));
		//printf("k:%lld b:%lld\n",-2*tot[yy],+tot[yy]*tot[yy]+tot[yy]+2*f[yy]);
		mn=min(mn,(t*t-t-2*tot[yy]*t+tot[yy]*tot[yy]+tot[yy]+2*f[yy])/2+f[xx]);
		//printf("%lld %lld\n",mn,t);
	}*/
	TT++;
	for (LL u=siz-1;u>=0;u--) if (vec[x][u]!=fa)
	{
		LL xx=vec[x][u];
		LL t=n-tot[xx],o=query(1,t);
		mn=min(mn,(t*t-t+o)/2+f[xx]);
		//printf("%lld %lld\n",t,(t*t-t+o)/2+f[xx]);
	//	printf("k:%lld b:%lld\n",-2*tot[xx],tot[xx]*tot[xx]+tot[xx]+2*f[xx]);
		modify(1,-2*tot[xx],tot[xx]*tot[xx]+tot[xx]+2*f[xx]);
	}
	for (LL u=0;u<del.size();u++)	{tr[del[u]].k=0;tr[del[u]].b=MAX;}
	del.clear();
}
int main()
{
	memset(f,127,sizeof(f));
	scanf("%lld",&n);mn=n*(n-1)/2;
	num=0;bt(1,n);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",n*(n-1)-mn);
	return 0;
}