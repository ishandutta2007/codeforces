#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<20)+5)
#define Ks (12+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,q,z,x,y,op,Ls;ll Ans,A[N],B[N];
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	int Fl[N<<2];ll F[N<<2],S[N<<2],S1[N<<2],S2[N<<2],Mx[N<<2];I void Up(int now){F[now]=F[ls]+F[rs];S[now]=S[ls]+S[rs];Mx[now]=max(Mx[ls],Mx[rs]);}
	I void BD(int l=1,int r=m+1,int now=1){S1[now]=r-l+1;S2[now]=1ll*(m-l+1+m-r+1)*(r-l+1)/2;if(l==r){S[now]=Mx[now]=(l^1?B[l]:0);F[now]=(l^1?B[l]:0)*(m-l+1);return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(now);}
	I void PF(int now,int w){Fl[now]+=w;S[now]+=S1[now]*w;F[now]+=S2[now]*w;Mx[now]+=w;}I void P(int now){Fl[now]&&(PF(ls,Fl[now]),PF(rs,Fl[now]),Fl[now]=0);}
	I void Ins(int x,int y,int z,int l=1,int r=m+1,int now=1){if(x<=l&&r<=y) return PF(now,z);int m=l+r>>1;P(now);x<=m&&(Ins(x,y,z,l,m,ls),0);y>m&&(Ins(x,y,z,m+1,r,rs),0);Up(now);}
	I ll Qry(int x,int y,int z,int l=1,int r=m+1,int now=1){if(x>y) return 0;if(x<=l&&r<=y) return F[now]+S[now]*z;int m=l+r>>1;P(now);ll Fs=0;x<=m&&(Fs+=Qry(x,y,z,l,m,ls));y>m&&(Fs+=Qry(x,y,z,m+1,r,rs));return Fs;}
	I int Find(ll z,int l=1,int r=m+1,int now=1){if(l==r) return l-1;int m=l+r>>1;P(now);return z<=Mx[ls]?Find(z,l,m,ls):Find(z,m+1,r,rs);}
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d%d",&n,&m,&q);for(i=1;i<=n;i++) scanf("%lld",&A[i]);for(i=1;i<=m;i++) scanf("%lld",&B[i]);B[m+1]=1e18;
	for(i=n;i;i--) A[i]-=A[i-1];for(i=m;i;i--) B[i]-=B[i-1]; Tree::BD();while(q--){
		scanf("%d%d%d",&op,&x,&y);if(op==1) {for(i=n-x+1;i<=n;i++) A[i]+=y;}else x^m?(Tree::Ins(m-x+1,m,y)):(B[1]+=y,Tree::Ins(2,m,y));
		z=2;Ans=(A[1]+B[1])*(n+m-1);
		for(i=2;i<=n;i++) Ls=Tree::Find(A[i]),Ans+=Tree::Qry(z,Ls,n-i+1)+A[i]*(n-i+m-Ls+1),z=Ls+1/*,cerr<<z<<' '<<Ans<<'\n'*/;printf("%lld\n",Ans+Tree::Qry(z,m,0));
	}
}