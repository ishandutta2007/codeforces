#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 200000
#define K 500
#define mod 10000
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n;ll A[N+5],Q[N+5],Ans,ToT;
struct Line{ll k,b;I ll Ca(int x){return k*x+b;}}F[N+5<<2];
#define ls now<<1
#define rs now<<1|1
I void Init(Line z,int l=1,int r=n,int now=1){
	if(z.Ca(l)>=F[now].Ca(l)&&z.Ca(r)>=F[now].Ca(r)) {F[now]=z;return;}if(z.Ca(l)<=F[now].Ca(l)&&z.Ca(r)<=F[now].Ca(r)) return;if(l==r) return;
	int m=l+r>>1;if(F[now].Ca(m)<=z.Ca(m)) F[now].Ca(l)<=z.Ca(l)?Init(F[now],m+1,r,rs):Init(F[now],l,m,ls),F[now]=z;else F[now].Ca(l)>z.Ca(l)?Init(z,m+1,r,rs):Init(z,l,m,ls); 
}
I ll Find(int x,int l=1,int r=n,int now=1){if(l==r) return F[now].Ca(x);int m=l+r>>1;ll F1=(x<=m?Find(x,l,m,ls):Find(x,m+1,r,rs));return max(F1,F[now].Ca(x));}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%lld",&A[i]);reverse(A+1,A+n+1);for(i=1;i<=n;i++)A[i]+=A[i-1],Q[i]=Q[i-1]+A[i];
	for(i=1;i<=n;i++) Init((Line){-A[i-1],A[i-1]*(i-1)-Q[i-1]}),ToT=Find(i)+Q[i],Ans=max(Ans,ToT);printf("%lld\n",Ans);
}