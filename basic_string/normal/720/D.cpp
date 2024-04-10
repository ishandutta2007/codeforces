#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,P=1e9+7;
int f[N],t[N];
vector<pair<int,int>>ad[N],dl[N];
basic_string<int>g[N];
set<int>p={1};
set<pair<int,int>>s;
void add(int x,int y){for(;x<N;x+=x&-x)t[x]=(t[x]+y)%P;}
int sum(int x){int r=0;for(;x;x-=x&-x)r=(r+t[x])%P;return r;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,o,i,j,k,l;
	for(cin>>n>>m>>o;o--;)cin>>i>>j>>k>>l,ad[i].push_back({j,l}),dl[k].push_back({j,l}),g[i-1]+=l+1;
	for(add(f[i=1]=1,1),g[n]+=m;i<=n;++i){
		for(auto o:ad[i]){
			auto u=p.lower_bound(o.first),v=u;
			for(s.insert(o);v!=p.end()&&*v<=o.second;++v)add(*v,-f[*v]),f[*v]=0;
			p.erase(u,v);
		}
		sort(begin(g[i]),end(g[i]),greater<int>());
		for(int o:g[i]){
			auto u=s.upper_bound({o,N});
			j=(sum(o)-(u==s.begin()?0:sum((--u)->second)))%P,add(o,(j-f[o])%P),f[o]=j,p.insert(o);
		}
		for(auto o:dl[i])s.erase(o);
	}
	cout<<(f[m]+P)%P;
	return 0;
}