#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")

#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
int n,m,q;
int c[1111111],L[1111111],R[1111111];
int w[1111111];

// PROVINCE SELECTION 2020 E.Tree 
namespace segtree
{
	struct segt
	{
		int siz,xors;
		segt*s[2];
		segt(){s[0]=s[1]=0,siz=xors=0;}
		void pushu(int dep)
		{
			xors=0,siz=0;
			if(s[0])xors^=s[0]->xors,siz+=s[0]->siz;
			if(s[1])xors^=s[1]->xors^((s[1]->siz&1)<<dep),siz+=s[1]->siz;
		}
	}*rt[555];
	void updata(segt*x,int dep=0)
	{
		if(x->s[1])updata(x->s[1],dep+1);
		segt*t=x->s[1];x->s[1]=x->s[0],x->s[0]=t;
		x->xors=0;
		if(x->s[1]){x->xors^=x->s[1]->xors;if((x->s[1]->siz)&1)x->xors^=(1<<dep);}
		if(x->s[0]){x->xors^=x->s[0]->xors;
			//if((x->s[0]->siz)&1)x->xors^=(1<<dep);
		}
		//x->pushu(dep);
		
		/*
		if(x->s[1])updata(x->s[1],dep+1);
		if(x->s[1])if((x->s[1]->siz)&1)x->xors^=(1<<dep);
		if(x->s[0])if((x->s[0]->siz)&1)x->xors^=(1<<dep);
		segt*t=x->s[1];x->s[1]=x->s[0],x->s[0]=t;
		*/
	}
	void insert(segt*x,int dep=0)
	{
		x->siz++;
		if(dep==18)return;
		if(!x->s[0])x->s[0]=new segt();
		insert(x->s[0],dep+1),x->pushu(dep);
	}
	void init()
	{
		for(register int i=1;i<=550;i++)
			rt[i]=new segt();
	}
}

//const int BLOCK=204800;

const int BLOCK=2048;

std::vector<int>v[1111111];

int ans[1111111];

int bel(int x){return(x-1)/BLOCK+1;}
int Lsh(int x){return(x-1)*BLOCK+1;}
int Rsh(int x){return x*BLOCK;}

int askUntil(int L,int R)
{
	int Bl=bel(L),Br=bel(R);
	register int i;
	int ret=0;
	if(Bl==Br)
	{
		for(i=L+1;i<=R;i++)
			if(w[i])ret^=(i-L);
	}else
	{
		//fprintf(stderr,"%d->%d | %d->%d\n",L,Rsh(Bl),Lsh(Br),R);
		for(i=L+1;i<=Rsh(Bl);i++)if(w[i])ret^=(i-L);
		for(i=Lsh(Br);i<=R;i++)if(w[i])ret^=(i-L);
		for(i=Bl+1;i<Br;i++)ret^=segtree::rt[i]->xors;
	}//printf("%d->%d\n",L,ret);
	return ret;
}

void solve()
{
	register int i,ii;
	for(i=m;i;i--)
	{
		for(ii=bel(i);ii<=bel(m);ii++)
		{
			segtree::updata(segtree::rt[ii]);
			//printf("%d\n",segtree::rt[ii]->xors);
		}
		for(int qid:v[i])
			ans[qid]=askUntil(i,R[qid]);
		if(w[i])
			segtree::insert(segtree::rt[bel(i)]);
	}
}

void exec()
{
	segtree::init();
	register int i,ii,iii;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",c+i),w[c[i]]^=1;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",L+i,R+i),v[L[i]].push_back(i);
	}
	solve();
	//for(i=1;i<=q;i++)printf("%d\n",ans[i]);
	for(i=1;i<=q;i++)putchar(ans[i]?'A':'B');
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}