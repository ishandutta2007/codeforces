#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i++)
#define ROF(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i--)
#define temT template<typename T>
using namespace std;
typedef long long ll;
const int N=int(2e5)+10;

struct edge{
	int u,v,w;
	bool operator<(const edge &t)const{ return w<t.w; }
}E[N];
int n,m,T,K,fa[N],mx; ll ans;

int gf(int x){ return x==fa[x]?x:fa[x]=gf(fa[x]); }

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for(cin>>T;T--;){
		cin>>n>>m>>K;
		FOR(i,1,m) cin>>E[i].u>>E[i].v>>E[i].w;
		FOR(i,1,n) fa[i]=i; sort(E+1,E+m+1); ans=mx=0;
		for(int fu,fv,i=1;i<=m;i++)
			if((fu=gf(E[i].u))!=(fv=gf(E[i].v)))
				fa[fu]=fv,mx=max(mx,E[i].w),ans+=int(E[i].w>K)*(E[i].w-K);
		if(mx<=K){ ans=K-mx; FOR(i,1,m) ans=min(ans,1ll*abs(E[i].w-K)); }
		cout<<ans<<"\n";
	}
	
	return 0;
}