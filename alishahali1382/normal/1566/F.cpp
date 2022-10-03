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
const int MAXN=400010, LOG=20;

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
ll dp[MAXN], pd[MAXN];
vector<pii> vec, vec2;
vector<int> typ;

int Solve(){
	vec.clear();
	vec2.clear();
	typ.clear();
	cin>>n>>m;
	while (n--){
		cin>>x;
		vec.pb({x, x+1});
	}
	while (m--){
		cin>>l>>r;
		vec.pb({r, l});
	}
	sort(all(vec));
	int last=-inf;
	for (pii p:vec){
		if (p.first<p.second){ // point
			last=p.first;
			while (SZ(vec2) && vec2.back().first==last && typ.back()) vec2.pop_back(), typ.pop_back();
			vec2.pb({last, last});
			typ.pb(0);
		}
		else{ // segment
			if (p.second<=last) continue ;
			while (SZ(vec2) && vec2.back().first==p.first && typ.back()) vec2.pop_back(), typ.pop_back();
			if (SZ(vec2) && p.second<=vec2.back().second) continue ;
			vec2.pb(p);
			typ.pb(1);
		}
	}
	n=SZ(vec2);
	for (int i=0; i<n; i++){
//		debugp(vec2[i])
	}
	ll mn=INF, mn2=INF;
	last=-1;
	if (typ[0]) pd[0]=dp[0]=INF;
	else dp[0]=pd[0]=0, last=0;
	for (int i=1; i<n; i++){
		pii p=vec2[i];
		if (typ[i]){ // segment
			if (last==-1){
				dp[i]=pd[i]=INF;
				continue ;
			}
			pd[i]=pd[last]+(p.second-vec2[last].second);
			dp[i]=min(pd[i], dp[last]+2ll*(p.second-vec2[last].second));
			mn=min(mn, dp[i-1]-p.first);
			mn2=min(mn2, dp[i-1]-2ll*p.first);
		}
		else{
			dp[i]=min(p.first+mn, dp[i-1]);
			pd[i]=min(p.first*2ll+mn2, dp[i-1]);
			if (last==-1){
				dp[i]=p.first-vec2[0].first;
				pd[i]=2ll*(p.first-vec2[0].first);
			}
			last=i;
		}
//		cerr<<i<<": "<<pd[i]<<" "<<dp[i]<<"\n";
	}
	cout<<dp[n-1]<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19

1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19

*/