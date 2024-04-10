#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (1000000+5)
#define M ((N<<2)+5)
#define K (1500+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,x,y,z,l,r;
namespace Tree{
	#define ls v<<1
	#define rs v<<1|1
	ll F[M];int tg[M];I void Up(int v){F[v]=F[ls]+F[rs];}I void PF(int v){F[v]=0;tg[v]=1;}I void P(int v){tg[v]&&(PF(ls),PF(rs),tg[v]=0);} 
	I void Ins(int x,int w,int l=1,int r=m,int v=1){F[v]+=w;if(l==r) return;int m=l+r>>1;P(v);x<=m?Ins(x,w,l,m,ls):Ins(x,w,m+1,r,rs);}
	I void Add(int x,int y,int l=1,int r=m,int v=1){if(x<=l&&r<=y) return PF(v);int m=l+r>>1;P(v);x<=m&&(Add(x,y,l,m,ls),0);y>m&&(Add(x,y,m+1,r,rs),0);Up(v);}
	I ll Qry(int x,int y,int l=1,int r=m,int v=1){if(x>y) return 0;if(x<=l&&r<=y) return F[v];P(v);int m=l+r>>1;return (x<=m?Qry(x,y,l,m,ls):0)+(y>m?Qry(x,y,m+1,r,rs):0);}
	#undef ls
	#undef rs
}
struct Ques{int l,r;bool operator <(const Ques &B)const{return l<B.l;};};vector<Ques> I1[N],I2[N];set<Ques> F;
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d%d%d",&n,&m,&k);while(k--) scanf("%d%d%d%d",&x,&y,&l,&r),I1[x].PB((Ques){y,r}),I2[l+1].PB((Ques){y,r});
	for(i=1;i<=n;i++){sort(I1[i].begin(),I1[i].end());reverse(I1[i].begin(),I1[i].end());
		for(Ques d:I1[i]){auto Pt=F.UB((Ques){d.r+1,0});x=(Pt==F.begin()?1:(*--Pt).r+1),Tree::Ins(d.r+1,Tree::Qry(x,d.r)%mod);}
		for(Ques d:I2[i]) F.erase(d);for(Ques d:I1[i]) F.insert(d),Tree::Add(d.l,d.r);if(i==1) Tree::Ins(1,1);
		//for(j=1;j<=m;j++) printf("%lld ",Tree::Qry(j,j));Pc('\n');
	}printf("%lld\n",Tree::Qry(F.end()==F.begin()?1:(*--F.end()).r+1,m)%mod);
}