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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, SQ=800;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
map<int, int> cnt;
vector<int> vec[MAXN], diff;
int comp[MAXN];
map<pii, int> bad;

int Main(){
	cnt.clear();
	bad.clear();
	ans=0;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[A[i]]++;
	for (pii p:cnt){
		diff.pb(p.second);
		vec[p.second].pb(p.first);
	}
	diff.pb(0);
	sort(all(diff));
	diff.resize(unique(all(diff))-diff.begin());
	for (int i=1; i<SZ(diff); i++) comp[diff[i]]=i;
	
	while (m--){
		cin>>x>>y;
		bad[{x, y}]=bad[{y, x}]=1;
	}
	// cntx==cnty
	for (int cntx:diff) if (cntx){
		sort(all(vec[cntx]));
		for (int x:vec[cntx]){
			int i=SZ(vec[cntx])-1;
			while (~i && bad[{x, vec[cntx][i]}]) i--;
			if (i==-1 || x>=vec[cntx][i]) continue ;
			ans=max(ans, 2ll*cntx*(x+vec[cntx][i]));
		}
	}
//	debug(ans)
	
	// cntx<cnty
	for (int cntx:diff) if (cntx){
		for (int cnty:diff) if (cntx<cnty){
			for (int i=SZ(vec[cntx])-1; ~i; i--){
				int x=vec[cntx][i];
				if (!bad[{x, vec[cnty].back()}]){
					ans=max(ans, 1ll*(cntx+cnty)*(x+vec[cnty].back()));
					break ;
				}
				
				int j=SZ(vec[cnty])-1;
				while (~j && bad[{x, vec[cnty][j]}]) j--;
				if (j==-1) continue ;
				ans=max(ans, 1ll*(cntx+cnty)*(x+vec[cnty][j]));
			}
		}
	}
	
	cout<<ans<<"\n";
	
	for (int x:diff) vec[x].clear(), comp[x]=0;
	diff.clear();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	
	return 0;
}
/*
3
6 1
6 3 6 7 3 3
3 6

2 0
3 4

7 4
1 2 2 3 1 5 1
1 5
3 5
1 3
2 5

1
2 0
3 4

*/