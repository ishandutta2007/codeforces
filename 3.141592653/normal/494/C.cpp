#include<bits/stdc++.h>
typedef double db;
struct node{int v;db poss;};
bool operator<(const node&x,const node&y){return x.v<y.v;}
typedef std::vector<node>poly;
std::vector<int>v[5555];
int n,q;
struct segt
{
	int col[444444];
	void pushd(int x){if(col[x])col[x<<1]=col[x<<1|1]=col[x],col[x]=0;}
	int cover(int L,int R,int C,int p=1,int pl=1,int pr=n)
	{
		if(L>pr||pl>R)return 0;
		int r=col[p];
		if(L<=pl&&pr<=R)return col[p]=C,r;
		pushd(p);
		int pm=(pl+pr)>>1;
		return cover(L,R,C,p<<1,pl,pm)|cover(L,R,C,p<<1|1,pm+1,pr);
	}
	int ask(int x,int p=1,int pl=1,int pr=n)
	{
		if(col[p])return col[p];
		if(pl==pr)return 0;
		int pm=(pl+pr)>>1,dr=x>pm;
		dr?pl=pm+1:pr=pm;
		return ask(x,p<<1|dr,pl,pr);
	}
}T;
int mxx[5555],fa[5555],a[111111];
db tmp[5555];
struct rng{int l,r;db ps;}r[5555];
bool operator<(const rng x,const rng y){return x.r-x.l>y.r-y.l;}
int max(int x,int y){return x<y?y:x;}
void emax(int&x,int y){x<y?x=y:0;}
poly p[5555];
poly tp;
void shift(poly&x,db k)
{
	tp.clear();
	for(node&v:x)
		tp.push_back((node){v.v,v.poss*(1-k)}),tp.push_back((node){v.v+1,v.poss*k}),
	std::sort(tp.begin(),tp.end());
	x.clear();
	for(node&Z:tp)
	{
		if(Z.poss<1e-15)continue;
		if(!x.size()||x.back().v!=Z.v)x.push_back(Z);
		else x.back().poss+=Z.poss; 
	}
}
void merge(poly&x,poly&y)
{
	tp.clear();
	for(node&A:x)
		for(node&B:y)
			tp.push_back((node){max(A.v,B.v),A.poss*B.poss});
	std::sort(tp.begin(),tp.end()),x.clear();
	for(node&Z:tp)
	{
		if(!x.size()||x.back().v!=Z.v)x.push_back(Z);
		else x.back().poss+=Z.poss; 
	}
}
void dfs(int x=0)
{
	p[x].push_back((node){mxx[x],1});
	for(int t:v[x])dfs(t),merge(p[x],p[t]);
	if(x)shift(p[x],r[x].ps);
}
int main()
{
	scanf("%d%d",&n,&q);
	register int i;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=q;i++)scanf("%d%d%lf",&r[i].l,&r[i].r,&r[i].ps);
	std::sort(r+1,r+q+1);
	for(i=1;i<=q;i++)fa[i]=T.cover(r[i].l,r[i].r,i),v[fa[i]].push_back(i);
	for(i=1;i<=n;i++)emax(mxx[T.ask(i)],a[i]);
	dfs();
	db ans=0;
	for(node&v:p[0])ans+=v.v*v.poss;
	printf("%.12lf\n",ans);
}
/*
Please don't let me down.
*/