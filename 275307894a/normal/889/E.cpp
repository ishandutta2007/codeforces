#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((N<<1)+5)
#define K (700+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;const ll INF=1e18;map<ll,ll> f;
int n,m,k;ll x,ToT;
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%lld",&n,&x);f[x-1]=0;for(i=2;i<=n;i++){
		scanf("%lld",&x);ll Ts=-1e18;while(!f.empty()){
			auto j=*--f.end();if(j.first<x){Ts>=0&&(f[x-1]=max(f[x-1],Ts));break;}Ts=max(j.second+(i-1)*(j.first/x*x-x),Ts);
			f[j.first%x]=max(f[j.first%x],j.second+(j.first-j.first%x)*(i-1));f.erase(--f.end());
		} 
	} for(auto i:f) ToT=max(ToT,i.second+i.first*n);printf("%lld\n",ToT);
}