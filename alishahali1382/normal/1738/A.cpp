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
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b;
ll A[MAXN], B[MAXN], ans;

int Main(){
	ans=0;
	cin>>n;
	vector<ll> v1, v2;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		cin>>B[i];
		if (A[i]==0) v1.pb(B[i]);
		if (A[i]==1) v2.pb(B[i]);
	}
	sort(all(v1));
	sort(all(v2));
	reverse(all(v1));
	reverse(all(v2));
	if (SZ(v1)==SZ(v2)){
		for (int i=1; i<=n; i++) ans+=B[i];
		ans*=2;
		ans-=min(v1.back(), v2.back());
		kill(ans)
	}
	if (SZ(v1)>SZ(v2)) swap(v1, v2);
	for (ll x:v1) ans+=2*x;
	for (int i=0; i<SZ(v2); i++){
		if (i<SZ(v1)) ans+=2*v2[i];
		else ans+=v2[i];
	}
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}