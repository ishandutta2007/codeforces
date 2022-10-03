#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 100010, LOG=20;

ll A, n, x, y, ans;
vector<ll> D, prime;
ll dp[2000][6720];

ll is(ll x, ll y){
	ll tmp=1;
	while (tmp<y) tmp*=x;
	return tmp==y;
}

ll get(ll x){
	if (x<=2) return -1;
	x--;
	for (ll i=2; i*i<=x; i++) if (x%i==0){
		ll tmp=is(i, x);
		if (!tmp) return -1;
		return i;
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>A;
	for (ll i=1; i*i<=A; i++) if (A%i==0){
		D.pb(i);
		if (i*i!=A) D.pb(A/i);
	}
	for (ll x:D){
		ll tmp=get(x);
		if (tmp!=-1) prime.pb(tmp);
	}
	sort(all(D));
	sort(all(prime));
	prime.resize(unique(all(prime))-prime.begin());
	
	dp[0][0]=1;
	for (int i=0; i<prime.size(); i++){
		ll p=prime[i];
		for (int j=0; j<D.size(); j++){
			ll tmp=p;
			dp[i+1][j]+=dp[i][j];
			for (; (tmp+1)*D[j]<=A && (tmp+1)*D[j]>0; tmp*=p) if (A%((tmp+1)*D[j])==0) dp[i+1][lower_bound(all(D), (tmp+1)*D[j])-D.begin()]+=dp[i][j];
		}
	}
	cout<<dp[prime.size()][D.size()-1]<<'\n';
	
	return 0;
}