#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=5e5+5,M=(1<<18)+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;mt19937 rnd(time(0));
int Op[N],n,m,k,x,y,z,Ct,X[N],Y[N],fa[N];
int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
void Solve(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]);
	while(1){Ct=0;
		for(i=1;i<=m;i++) Op[i]=R(2)-1;for(i=1;i<=n;i++) fa[i]=i;for(i=1;i<=m;i++) !Op[i]&&(fa[GF(X[i])]=GF(Y[i]));for(i=1;i<=n;i++) Ct+=(GF(i)==i);
		for(i=1;i<=n;i++) fa[i]=i;for(i=1;i<=m;i++) Op[i]&&(fa[GF(X[i])]=GF(Y[i]));for(i=1;i<=n;i++) Ct+=(GF(i)==i);if(Ct==2*n-m){break;} 
	}for(i=1;i<=m;i++) printf("%d",Op[i]);Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}