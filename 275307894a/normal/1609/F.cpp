#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (1000000+5)
#define M ((N<<2)+5)
#define mod 1000000001
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
int n,G[N],F[100],I1[N],I2[N];ll Ans,x,A[N],Mx[N],Mi[N];
I void Solve(int l,int r){
	if(l==r) {Ans++;return;}int m=l+r>>1,i;Solve(l,m);Solve(m+1,r);
	Mx[m]=Mi[m]=A[m];I1[m]=I2[m]=G[m];for(i=m-1;i>=l;i--) A[i]>Mx[i+1]?(Mx[i]=A[i],I1[i]=G[i]):(Mx[i]=Mx[i+1],I1[i]=I1[i+1]),A[i]<Mi[i+1]?(Mi[i]=A[i],I2[i]=G[i]):(Mi[i]=Mi[i+1],I2[i]=I2[i+1]);
	Mx[m+1]=Mi[m+1]=A[m+1];I1[m+1]=I2[m+1]=G[m+1];for(i=m+2;i<=r;i++) A[i]>Mx[i-1]?(Mx[i]=A[i],I1[i]=G[i]):(Mx[i]=Mx[i-1],I1[i]=I1[i-1]),A[i]<Mi[i-1]?(Mi[i]=A[i],I2[i]=G[i]):(Mi[i]=Mi[i-1],I2[i]=I2[i-1]);
	Me(F,0);int P1=m+1,P2=m+1;
	for(i=m;i>=l;i--){
		while(P1<=r&&Mx[P1]<=Mx[i]) F[I2[P1]]++,P1++;while(P2<=r&&Mi[i]<=Mi[P2]) F[I2[P2]]--,P2++;
		if(P2>=P1) Ans+=(I2[i]==I1[i])*(P1-m-1);else Ans+=(I2[i]==I1[i])*(P2-m-1)+F[I1[i]];
	}
	Me(F,0);P1=P2=m;for(i=m+1;i<=r;i++){
		while(P1>=l&&Mx[P1]<Mx[i]) F[I2[P1]]++,P1--;while(P2>=l&&Mi[i]<=Mi[P2]) F[I2[P2]]--,P2--;
		if(P2<=P1) Ans+=(I2[i]==I1[i])*(m-P1);else Ans+=(I2[i]==I1[i])*(m-P2)+F[I1[i]];
	}//cerr<<l<<' '<<r<<' '<<Ans<<'\n';
}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++){
		scanf("%lld",&A[i]);x=A[i];while(x) G[i]++,x^=x&-x; 
	} Solve(1,n);printf("%lld\n",Ans);
}