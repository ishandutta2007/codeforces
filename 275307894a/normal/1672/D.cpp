#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)<(b)?(a):(b))
#define min(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<16)+5)
#define K (1000+5)
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
int L,R,H1,H2,T,n,Fl[N],Vs[N],A[N],B[N],Fs[N];
struct Pa{int w,col,Fl;}S1[N],S2[N];
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) Fs[i]=Fl[i]=Vs[i]=0;for(i=1;i<=n;i++)scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]);
	for(i=n;i;i--) !Fl[A[i]]&&(Vs[i]=Fl[A[i]]=1);H1=H2=0;for(i=1;i<=n;i=j){for(j=i+1;j<=n;j++) if(A[i]^A[j]) break;S1[++H1]=(Pa){j-i,A[i],Vs[j-1]};}
	for(i=1;i<=n;i=j){for(j=i+1;j<=n;j++) if(B[i]^B[j]) break;S2[++H2]=(Pa){j-i,B[i],0};}
	R=1;for(i=1;i<=H2;i++){
		while(R<=H1&&(S1[R].col^S2[i].col||(S1[R].col==S2[i].col&&S1[R].w+Fs[S2[i].col]<S2[i].w))){
			Fs[S1[R].col]+=S1[R].w;if(S1[R].Fl){puts("NO");return;}R++;
		} 
		if(R>H1) {puts("NO");return;}Fs[S2[i].col]+=S1[R].w;Fs[S2[i].col]-=S2[i].w;R++;//cerr<<i<<' '<<R<<'\n';
	}puts("YES");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}