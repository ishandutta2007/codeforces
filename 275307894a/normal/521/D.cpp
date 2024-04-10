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
#define N 100000
#define M 300000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Op[N+5],X[N+5],Fl[N+5],Y[N+5],Bh,Sh,Fs[N+5];ll A[N+5],Z;
struct Ques{db w;int id,Fl;}S[N+5<<1],G[N+5],B[N+5],C[N+5];vector<Ques> F[N+5];I bool cmp(Ques x,Ques y){return x.w>y.w;}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	RI i,j;scanf("%d%d%d",&n,&m,&k);for(i=1;i<=n;i++)scanf("%lld",&A[i]);for(i=1;i<=m;i++) scanf("%d%d%d",&Op[i],&X[i],&Y[i]);
	for(i=1;i<=n;i++) G[i].w=-1e18;for(i=1;i<=m;i++) Op[i]==1&&G[X[i]].w<Y[i]&&(G[X[i]]=(Ques){Y[i],i,0},0);for(i=1;i<=m;i++) Op[i]==2&&(F[X[i]].push_back((Ques){Y[i],i,0}),0);
	for(i=1;i<=n;i++){
		sort(F[i].begin(),F[i].end(),cmp);for(j=0;j<F[i].size();j++) B[j+1]=F[i][j];
		C[0].w=A[i];Bh=F[i].size();for(j=1;j<=Bh;j++) C[j]=B[j],C[j].w+=C[j-1].w;
		B[0]=(Ques){G[i].w,G[i].id,1};for(j=1;j<=Bh;j++) B[j].w+=B[j-1].w,B[j].Fl=1;for(j=0;j<Bh;j++) B[j].w>C[j+1].w&&(C[j+1]=B[j],0);
		for(j=1;j<=Bh;j++) F[i][j-1]=C[j];B[Bh].w>C[Bh].w&&(F[i].push_back(B[Bh]),0);
		if(F[i].size()){
			for(j=F[i].size()-1;j;j--) F[i][j].w/=F[i][j-1].w,S[++Sh]=F[i][j];F[i][0].w/=A[i];S[++Sh]=F[i][0];
		}
	}
	for(i=1;i<=m;i++) Op[i]==3&&(S[++Sh]=(Ques){Y[i],i,0},0);
	sort(S+1,S+Sh+1,cmp);
	printf("%d\n",min(k,Sh));for(i=1;i<=min(k,Sh);i++) S[i].Fl&&(Fl[X[S[i].id]]=1);for(i=1;i<=n;i++) if(Fl[i]) printf("%d ",G[i].id),Fs[G[i].id]=1;
	for(i=1;i<=min(k,Sh);i++) !Fs[S[i].id]&&Op[S[i].id]==2&&(printf("%d ",S[i].id),Fs[S[i].id]=1);for(i=1;i<=min(k,Sh);i++) !Fs[S[i].id]&&Op[S[i].id]==3&&(printf("%d ",S[i].id),Fs[S[i].id]=1);
}