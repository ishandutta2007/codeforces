#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+9,M=63,P=1e9+7;
vector<pair<int,ll>>e[N];
bool v[N];
int p[N],t,w[M][2],f[M][2];
ll c[M],d[N],ans;
void ins(ll x){
	if(x)for(int i=59;~i;--i)if(x>>i&1){
		if(!c[i]){c[i]=x;break;}
		x^=c[i];
	}
}
void dfs(int x){
	v[x]=1,p[++t]=x;
	for(auto o:e[x])if(v[o.first])ins(d[o.first]^d[x]^o.second);
	else d[o.first]=d[x]^o.second,dfs(o.first);
}
void dp(){
	for(int i=59;~i;--i)w[i][0]=1,w[i][1]=0;
	for(int i=59;~i;--i)if(c[i]){
		for(int j=59;~j;--j)if(c[i]>>j&1)w[j][0]=w[j][1]=(w[j][0]+w[j][1])%P;
		else w[j][0]=w[j][0]*2%P,w[j][1]=w[j][1]*2%P;
	}
}
void wk(){
	memset(f,0,sizeof f);
	for(int i=1;i<=t;++i){
		ll x=d[p[i]];
		for(int j=59,b;~j;--j)b=x>>j&1,ans=(ans+(1ll<<j)%P*((f[j][b]*1ll*w[j][1]+f[j][!b]*1ll*w[j][0])%P))%P;
		for(int j=59;~j;--j)++f[j][x>>j&1];
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j;
	ll l;
	for(cin>>n>>m;m--;)cin>>i>>j>>l,e[i].push_back({j,l}),e[j].push_back({i,l});
	for(i=1;i<=n;++i)if(!v[i])t=0,memset(c,0,sizeof c),dfs(i),dp(),wk();
	cout<<ans;
	return 0;
}