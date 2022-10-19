#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (7000+5)
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
using namespace std;bitset<M> F[N],Cl,Val[M];
int n,m,k=7000,x,y,z,op,pr[M],ph,mu[M],Fl[M],Ans;
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);mu[1]=1;
	for(i=2;i<=k;i++){
		!Fl[i]&&(pr[++ph]=i,mu[i]=-1);for(j=1;j<=ph&&i*pr[j]<=k;j++){Fl[i*pr[j]]=1;if(i%pr[j]==0) break;mu[i*pr[j]]=-mu[i];}
	}
	for(i=1;i<=k;i++){
		for(j=1;j*i<=k;j++) Val[i][i*j]=abs(mu[j]);
	}
	while(m--){
		scanf("%d%d%d",&op,&x,&y);if(op==1){F[x]=Cl;for(i=1;i*i<=y;i++) y%i==0&&(F[x][i]=F[x][y/i]=1,0);}
		else if(op==2) scanf("%d",&z),F[x]=F[y]^F[z];else if(op==3) scanf("%d",&z),F[x]=F[y]&F[z];
		else{printf("%d",(F[x]&Val[y]).count()&1);}
	}
}