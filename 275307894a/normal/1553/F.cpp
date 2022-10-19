#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 600000
#define M 200000
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,k,x,y,z,Maxn;ll G[N+5],ToT,A[N+5],F[N+5];
struct Tree{
	ll F[N+5],Q[N+5];
	I void get(int x,int y){re int i;for(i=x;i<x/k*k+k;i++)F[i]+=y;for(i=x/k+1;i<=Maxn/k;i++)Q[i]+=y;}
	I ll calc(int x){return F[x]+Q[x/k];}
	I ll find(int x,int y){return calc(y)-calc(x-1);}
}S1,S2; 
I ll calc1(int m){
	re int i,j;ll Ans=0;for(i=1;i<=m;i=j+1){
		j=m/(m/i);Ans+=1ll*(m/i)*S1.find(i,j);
	}return Ans;
}
I ll calc2(int m){
	re int i,j;ll Ans=0;for(i=0;i<=Maxn;i+=m){
		Ans+=1ll*(i/m)*m*S2.find(i,min(i+m-1,Maxn)); 
	}return Ans;
}
int main(){
// 	freopen("1.in","r",stdin);
	re int i;scanf("%d",&n);k=sqrt(n);for(i=1;i<=n;i++) scanf("%lld",&A[i]),Maxn=max(Maxn,A[i]);
	for(i=1;i<=n;i++){
		G[i]=A[i]*(i-1)+ToT;G[i]-=calc1(A[i])+calc2(A[i]);//printf("%lld %lld\n",calc1(A[i]),calc2(A[i]));
		G[i]+=G[i-1];S1.get(A[i],A[i]);S2.get(A[i],1);ToT+=A[i];printf("%lld ",G[i]);	
	}
}