#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
struct pii
{int v,t;pii(int x=0,int y=0){v=x,t=y;}bool empty(){return!(v|t);}};
bool operator<(cpnst pii x,cpnst pii y){return x.v<y.v;}
template<typename _tp>bool emax(_tp&x,_tp y){return(x<y)?x=y,1:0;}
pii operator+(pii x,int y)
{return x.v+=y,x;}
pii max(pii x,pii y){return(x<y)?y:x;}
int n,L,R;
struct segt
{
	pii mx[1111111];
	int sl[1111111],ad[1111111];
	void push(int p,int d){mx[p]=mx[p]+d,ad[p]+=d;}
	void pushd(int p)
	{if(ad[p])push(p<<1,ad[p]),push(p<<1|1,ad[p]),ad[p]=0;}
	void pushu(int p){mx[p]=max(mx[p<<1],mx[p<<1|1]);}
	void init(int l,int r,int p=1)
	{
		mx[p]=pii(0,l),ad[p]=0;
		if(l==r){sl[p]=l;return;}
		int mid=(l+r)>>1;
		init(l,mid,p<<1),init(mid+1,r,p<<1|1);
	}
	pii locata(int l,int r,int p=1,int pl=1,int pr=n)
	{
		if(l>pr||pl>r)return pii(-1e9);
		if(l<=pl&&pr<=r)return mx[p];
		int mid=(pl+pr)>>1;
		pushd(p);
		return max(locata(l,r,p<<1,pl,mid),locata(l,r,p<<1|1,mid+1,pr));
	}
	void modify(int l,int r,int d,int p=1,int pl=1,int pr=n)
	{
		if(l>pr||pl>r)return;
		if(l<=pl&&pr<=r)return push(p,d);
		int mid=(pl+pr)>>1;
		pushd(p),modify(l,r,d,p<<1,pl,mid),modify(l,r,d,p<<1|1,mid+1,pr),pushu(p);
	}
	void updata(int x,pii d,int p=1,int pl=1,int pr=n)
	{
		if(pl==pr){emax(mx[p],d);return;}
		int mid=(pl+pr)>>1,dir=x>mid;
		pushd(p),(dir?pl=mid+1:pr=mid),updata(x,d,p<<1|dir,pl,pr),pushu(p);
	}
}T;
#include<vector>
std::vector<pii>v[1111111];
void ins(int x,int y,int z){v[x].push_back(pii(y,z));}
int len[1111111],ds[1111111],dl[1111111];
void dfs(int p=1,int f=0)
{
	for(auto t:v[p])
	{
		if(t.v==f)continue;
		dfs(t.v,p);
		if(len[p]<=len[t.v])len[p]=len[t.v]+1,ds[p]=t.v,dl[p]=t.t;
	}
}
int dfn[1111111],rev[1111111],tt;
void label(int p=1,int f=0)
{
	dfn[p]=++tt,rev[tt]=p;
	if(ds[p])label(ds[p],p);
	for(auto t:v[p])if((t.v^f)&&(t.v^ds[p]))label(t.v,p);
}
pii tmp[1111111];
pii split(int p=1,int f=0)
{
	if(ds[p])
	{
		pii tp=split(ds[p],p);if(!tp.empty())return tp;
		T.modify(dfn[p]+1,dfn[p]+len[p],dl[p]);
	}
	register int i;
	for(auto t:v[p])
		if((t.v^f)&&(t.v^ds[p]))
		{
			pii tp=split(t.v,p);
			if(!tp.empty())return tp;
			for(i=0;i<=len[t.v];i++)
			{
				tmp[i]=T.locata(dfn[t.v]+i,dfn[t.v]+i)+t.t;
				int LE=L-i-1,RE=R-i-1;
				if(LE<0)LE=0;
				if(RE>len[p])RE=len[p];
				if(LE<=RE)
				{
					pii ask=T.locata(dfn[p]+LE,dfn[p]+RE);
					if(ask.v+tmp[i].v>=0)return pii(rev[ask.t],rev[tmp[i].t]);
				}
			}for(i=0;i<=len[t.v];i++)T.updata(dfn[p]+i+1,tmp[i]);
		}
	int LE=L,RE=R;
	if(RE>len[p])RE=len[p];
	if(LE<=RE)
	{
		pii ask=T.locata(dfn[p]+LE,dfn[p]+RE);
		if(ask.v>=0)return pii(rev[ask.t],p);
	}return pii();
}
int s[1111111],t[1111111],l[1111111];
pii valid(int mid)
{
	T.init(1,n);
	register int i;
	for(i=1;i<=n;i++)v[i].clear(),len[i]=0;
	for(i=1;i<n;i++)
	{
		int vg=(l[i]>=mid)?1:-1;
		ins(s[i],t[i],vg),ins(t[i],s[i],vg);
	}dfs(),tt=0,label();
	return split();
}
void solve()
{
	int Ls=-1,Rs=1e9+1;
	pii ans(0,0);
	while(Ls+1<Rs)
	{
		int mid=(Ls+Rs)>>1;
		pii tp=valid(mid);
		if(!tp.empty())Ls=mid,ans=tp;
		else Rs=mid;
	}printf("%d %d\n",ans.v,ans.t);
}
int main()
{
	scanf("%d%d%d",&n,&L,&R);
	register int i;
	for(i=1;i<n;i++)
		scanf("%d%d%d",s+i,t+i,l+i);
	solve();
}
/*
Just go for it.
*/