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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, sz;
ll A[MAXN], ps[MAXN], S[MAXN];
pair<ll, pll> cht[MAXN];

inline ll Inter(pll a, pll b){
	if (a.first==b.first) return (b>a?-INF:INF);
	return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
}
inline void Add(pll x){
	while (sz && Inter(cht[sz-1].second, x)<=cht[sz-1].first) sz--;
	if (!sz) cht[sz++]={-INF, x};
	else cht[sz]={Inter(cht[sz-1].second, x), x}, sz++;
}
ll Get(ll x){
	pll p=(upper_bound(cht, cht+sz, make_pair(x, pll(INF, INF)))-1)->second;
	return p.first*x + p.second;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		ps[i]=ps[i-1] + A[i];
		S[i]=S[i-1] + A[i]*i;
		Add({i-1, (i-1)*ps[i-1]-S[i-1]});
		ans=max(ans, Get(-ps[i])+S[i]);
	}
	cout<<ans<<"\n";
	
	return 0;
}