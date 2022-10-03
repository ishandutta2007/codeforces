#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1010, LOG=20;

int n, m, k=1, u, v, x, y, t, a, b, ans;
int par[MAXN], sz[MAXN], szz[MAXN];

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	iota(par+1, par+n+1, 1);
	fill(sz+1, sz+n+1, 1);
	while (m--){
		cin>>x>>y;
		x=getpar(x);
		y=getpar(y);
		if (x==y) k++;
		else{
			par[x]=y;
			sz[y]+=sz[x];
			sz[x]=0;
		}
		memcpy(szz, sz, sizeof(szz));
		sort(szz+1, szz+n+1);
		reverse(szz+1, szz+n+1);
		ans=0;
		for (int i=1; i<=k; i++) ans+=szz[i];
		cout<<ans-1<<"\n";
	}
	
	return 0;
}