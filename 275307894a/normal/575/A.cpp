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
#define K 1500
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
int n,m,Dh;ll k,now,S[N+5],p;
struct MaT{
	ll A[2][2];MaT(){Me(A,0);}
	MaT operator *(const MaT &B)const{
		MaT C;RI i,j,h;for(h=0;h<2;h++){
			for(i=0;i<2;i++) for(j=0;j<2;j++) C.A[i][j]=(C.A[i][j]+A[i][h]*B.A[h][j])%p;
		}return C;
	}
}pus,B[N+5],F[N+5][20],Ans,Cl,B1[N+5],B2[N+5];
struct Ques{ll s,id;}C[N+5];I bool cmp(Ques x,Ques y){return x.id<y.id;}
struct yyy{ll id;MaT w;}D[N+5<<2];
I MaT Make(ll x,ll y){pus.A[0][0]=x;pus.A[1][0]=y;pus.A[0][1]=1;pus.A[1][1]=0;return pus;}
I MaT mpow(MaT x,ll y=mod-2){MaT Ans=Cl;while(y) y&1&&(Ans=Ans*x,0),y>>=1,x=x*x;return Ans;}
I MaT Find(int x,int y){MaT Ans=Cl;for(int now=x,i=19;~i;i--) now+(1<<i)-1<=y&&(Ans=Ans*F[now][i],now+=(1<<i));return Ans;}
I MaT calc(ll x,ll y){
	if(x>y) return Cl;
	if(x%n<=y%n)return Find(x%n,y%n)*mpow(B2[y%n+1]*B1[y%n],y/n-x/n);
	else return Find(x%n,n-1)*mpow(B1[n-1],y/n-x/n-1)*Find(0,y%n);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%lld%lld",&k,&p);if(!k){puts("0");return 0;}Cl.A[0][0]=Cl.A[1][1]=1;Ans=Cl;scanf("%d",&n);for(i=0;i<n;i++) scanf("%lld",&S[i]);
	scanf("%d",&m);for(i=1;i<=m;i++) scanf("%lld%lld",&C[i].id,&C[i].s);sort(C+1,C+m+1,cmp);
	for(i=0;i<n;i++)B[i]=Make(S[(i-1+n)%n],S[(i-2+n)%n]);
	for(B1[0]=B[0],i=1;i<n;i++)B1[i]=B1[i-1]*B[i];for(B2[n]=Cl,i=n-1;~i;i--) B2[i]=B[i]*B2[i+1]; 
	for(i=n-1;~i;i--){
		for(F[i][0]=B[i],j=1;i+(1<<j)-1<n;j++) F[i][j]=F[i][j-1]*F[i+(1<<j-1)][j-1];
	}
	for(i=1;i<=m;i++) {
	    if(C[i-1].id+1==C[i].id)D[++Dh]=(yyy){C[i].id+1,Make(C[i].s,C[i-1].s)};else D[++Dh]=(yyy){C[i].id+1,Make(C[i].s,S[(C[i].id-1)%n])};
	    if(C[i].id+1!=C[i+1].id) D[++Dh]=(yyy){C[i].id+2,Make(S[(C[i].id+1)%n],C[i].s)};
	}
	now=1;Ans.A[1][1]=0;for(i=1;i<=Dh;i++){//printf("%d %lld\n",i,D[i].id);
		if(D[i].id>k) break;Ans=Ans*calc(now+1,D[i].id-1)*D[i].w;now=D[i].id;
	}
	Ans=Ans*calc(now+1,k);printf("%lld\n",Ans.A[0][0]);
}