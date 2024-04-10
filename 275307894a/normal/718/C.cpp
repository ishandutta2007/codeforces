#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 20000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,A[N+5],op,x,y,z;
struct martix{
	ll F[2][2];
	martix operator *(const martix &s)const{
		martix A;Me(A.F,0);re int i,j,k;for(i=0;i<=1;i++){
			for(j=0;j<=1;j++) {
				for(k=0;k<=1;k++)A.F[i][j]+=F[i][k]*s.F[k][j];A.F[i][j]%=mod;
			}
		}return A;
	}
	martix operator +(const martix &s)const{
		martix A;Me(A.F,0);re int i,j;for(int i=0;i<=1;i++){
			for(j=0;j<=1;j++) A.F[i][j]=(F[i][j]+s.F[i][j])%mod;
		}return A;
	}
}F[N+5<<2],Sum[N+5<<2],Base,now,Cl;
I martix mpow(int y,martix x=Base){martix ans=Cl;while(y) (y&1)&&(ans=ans*x,0),y>>=1,x=x*x;return ans;}
I void Up(int now){Sum[now]=Sum[now<<1]+Sum[now<<1|1];}
I void pushF(int now){F[now]=F[now]*F[now>>1],Sum[now]=Sum[now]*F[now>>1];}
I void push(int now){pushF(now<<1);pushF(now<<1|1);F[now]=Cl;}
I void build(int l=1,int r=n,int now=1){
	F[now]=Cl;if(l==r) return (void)(Sum[now]=mpow(A[l]-1));int m=l+r>>1;build(l,m,now<<1);build(m+1,r,now<<1|1);Up(now);
}
I void insert(int x,int y,martix z,int l=1,int r=n,int now=1){
	if(x<=l&&r<=y){Sum[now]=Sum[now]*z;F[now]=F[now]*z;return;}int  m=l+r>>1;push(now);x<=m&&(insert(x,y,z,l,m,now<<1),0);y>m&&(insert(x,y,z,m+1,r,now<<1|1),0);Up(now);
}
I ll find(int x,int y,int l=1,int r=n,int now=1){
	if(x<=l&&r<=y) return Sum[now].F[0][0];int m=l+r>>1;ll Ans=0;push(now);x<=m&&(Ans+=find(x,y,l,m,now<<1));y>m&&(Ans+=find(x,y,m+1,r,now<<1|1));return Ans;
}
int main(){
// 	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	re int i;Base.F[0][0]=Base.F[0][1]=Base.F[1][0]=1,Base.F[1][1]=0;Cl.F[0][0]=Cl.F[1][1]=1;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);build();while(m--){
		scanf("%d%d%d",&op,&x,&y);if(op^2)scanf("%d",&z),now=mpow(z),insert(x,y,now);else printf("%lld\n",find(x,y)%mod);
	}
}