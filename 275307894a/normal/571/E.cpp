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
#define N 100
#define M 2000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,k;ll X[N+5],Y[N+5],Xx[N+5<<1],Yy[N+5<<1],Xs,Ys,Fl,A[N+5][M+5],B[N+5][M+5],P[M+5],now,Ph,Sh,un,wn,Ans=1,Maxn;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I void Fail(){puts("-1");exit(0);}struct Ques{ll a,b,c;bool operator ==(const Ques &B)const{return a==B.a&&b==B.b&&c==B.c;}}S[N+5];I bool cmp(Ques x,Ques y){return x.a==y.a?(x.b==y.b?x.c<y.c:x.b<y.b):x.a<y.a;}
I void Get_P(){RI i,j;for(i=2;i*i<=Maxn;i++){Fl=0;for(j=1;j<=n;j++) if(Xx[j]%i==0||Yy[j]%i==0){Fl=1;while(Xx[j]%i==0) Xx[j]/=i;while(Yy[j]%i==0) Yy[j]/=i;}Fl&&(P[++Ph]=i);}for(i=1;i<=n;i++)Xx[i+n]=Yy[i];sort(Xx+1,Xx+2*n+1);k=unique(Xx+1,Xx+2*n+1)-Xx-1;for(i=1;i<=k;i++) Xx[i]^1&&(P[++Ph]=Xx[i]);}
I void check(int Id,ll k){RI i,j;for(i=1;i<=n;i++) for(j=1;j<=Ph;j++) if(A[Id][j]+B[Id][j]*k<A[i][j]||(B[i][j]?(A[Id][j]+B[Id][j]*k-A[i][j])%B[i][j]:A[Id][j]+B[Id][j]*k-A[i][j]))Fail();printf("%lld\n",X[Id]*mpow(Y[Id],k)%mod);exit(0);}
I void exgcd(ll a,ll b,ll &x,ll &y){if(!b) {x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%lld%lld",&X[i],&Y[i]),Xx[i]=X[i],Yy[i]=Y[i],Maxn=max(Maxn,max(X[i],Y[i]));Get_P();
	for(i=1;i<=n;i++){
		Xs=X[i];Ys=Y[i];for(j=1;j<=Ph;j++){while(Xs%P[j]==0) Xs/=P[j],A[i][j]++;while(Ys%P[j]==0) Ys/=P[j],B[i][j]++;}
	}
	for(i=2;i<=n;i++){
		Sh=0;for(j=1;j<=Ph;j++){
			if(!B[i][j]&&!B[1][j]) {if(A[i][j]^A[1][j])Fail();}
			else if(!B[i][j]||!B[1][j]){
				if(!B[i][j]) {if(A[i][j]<A[1][j]||(A[i][j]-A[1][j])%B[1][j])Fail();check(1,(A[i][j]-A[1][j])/B[1][j]);}
				else {if(A[1][j]<A[i][j]||(A[1][j]-A[i][j])%B[i][j])Fail();check(i,(A[1][j]-A[i][j])/B[i][j]);}
			}else S[++Sh]=(Ques){B[1][j],-B[i][j],A[i][j]-A[1][j]};
		}for(j=1;j<=Sh;j++) now=__gcd(S[j].a,__gcd(S[j].b,S[j].c)),S[j].a/=now,S[j].b/=now,S[j].c/=now;sort(S+1,S+Sh+1,cmp);
		Sh=unique(S+1,S+Sh+1)-S-1;if(!Sh) continue;if(Sh>=2){
			if((S[1].b*S[2].a==S[1].a*S[2].b&&S[1].c*S[2].a-S[2].c*S[1].a)||(S[1].c*S[2].a-S[2].c*S[1].a)%(S[1].b*S[2].a-S[1].a*S[2].b))Fail();wn=(S[1].c*S[2].a-S[2].c*S[1].a)/(S[1].b*S[2].a-S[1].a*S[2].b);
			if((S[1].c-wn*S[1].b)%S[1].a) Fail();un=(S[1].c-wn*S[1].b)/S[1].a;if(un<0||wn<0) Fail();for(j=3;j<=Sh;j++) if(S[j].a*un+S[j].b*wn!=S[j].c) Fail();check(1,un);
		}now=__gcd(S[1].a,S[1].b);if(abs(now)^1)Fail();exgcd(S[1].a,S[1].b,un,wn);un*=S[1].c/now;wn*=S[1].c/now;//printf("%lld %lld\n",un,wn);
		if(un<0) now=(-un-1)/S[1].b+(S[1].b>0?1:-1),un+=now*S[1].b,wn-=now*S[1].a;else now=un/S[1].b,un-=now*S[1].b,wn+=now*S[1].a;
		if(wn<0) now=(-wn-1)/S[1].a+(S[1].a>0?1:-1),wn+=now*S[1].a,un-=now*S[1].b;if(un<0)Fail();
		for(j=1;j<=Ph;j++) A[1][j]=A[1][j]+un*B[1][j],B[1][j]&&(B[1][j]=B[1][j]*B[i][j]/__gcd(B[1][j],B[i][j]));
	}for(i=1;i<=Ph;i++) Ans=Ans*mpow(P[i],A[1][i]%Mod)%mod;printf("%lld\n",Ans);
}