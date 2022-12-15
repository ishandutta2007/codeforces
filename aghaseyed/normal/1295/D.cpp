#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;

void solve(){
	cin>>a>>m;
	ll g=__gcd(a, m);
	b=a/g;
	n=m/g;
	
	//debug2(b, n)
	
	vector<ll> P;
	ll tmp=n;
	for (ll i=2; i*i<=tmp; i++) if (tmp%i==0){
		P.pb(i);
		while (tmp%i==0) tmp/=i;
	}
	if (tmp>1) P.pb(tmp);
	m=P.size();
	//debugv(P)
	
	ans=0;
	for (int mask=0; mask<(1<<m); mask++){
		ll d=1;
		for (int i=0; i<m; i++) if (mask&(1<<i)) d*=P[i];
		ll tmp=((n+b-1)/d)-((b-1)/d);
		if (__builtin_popcount(mask)&1) tmp=-tmp;
		ans+=tmp;
		//debug2(d, tmp)
	}
	cout<<ans<<'\n';
}
/*
1
42 9999999967

*/

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}