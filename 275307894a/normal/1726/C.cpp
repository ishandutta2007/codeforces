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
using namespace std;const int N=2e5+5,M=(1<<18)+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,m,k,x,y,z,Q[N],fa[N];char s[N];vector<int> Id[N];
int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
void Solve(){
	int i,j;scanf("%d",&n);for(i=0;i<=n;i++) Id[i].clear();
	scanf("%s",s+1);Q[0]=0;Id[0].PB(0);for(i=1;i<=2*n;i++) Q[i]=Q[i-1]+(s[i]=='('?1:-1),fa[i]=i,Id[Q[i]].PB(i);
	for(i=0;i<=n;i++){
		for(j=1;j<Id[i].size();j++)s[Id[i][j]]==')'&&(fa[GF(Id[i][j])]=GF(Id[i][j-1]+1),s[Id[i][j-1]]==')'&&(fa[GF(Id[i][j])]=GF(Id[i][j-1])));
	}int Ct=0;for(i=1;i<=2*n;i++) Ct+=(GF(i)==i);printf("%d\n",Ct);
}
int main(){
//	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}