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

ll n, k, q, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll tav25[MAXN], tav26[MAXN], tav[MAXN];
ll F[MAXN], I[MAXN];
map<int, array<int, MAXN>> mp;
string s;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav25[0]=tav26[0]=F[0]=tav[0]=1;
	tav[1]=25*powmod(26, mod-2)%mod;
	for (int i=1; i<MAXN; i++){
		tav25[i]=tav25[i-1]*25%mod;
		tav26[i]=tav26[i-1]*26%mod;
		tav[i]=tav[i-1]*tav[1]%mod;
		F[i]=F[i-1]*i%mod;
	}
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
		
	cin>>q>>s;
	k=s.size();
	while (q--){
		cin>>t;
		if (t==1){
			cin>>s;
			k=s.size();
			continue ;
		}
		cin>>n;
		if (!mp.count(k)){
			mp[k][0]=0;
			for (int i=1; i<MAXN; i++) mp[k][i]=(mp[k][i-1]+C(i-1, k-1)*tav[i])%mod;
		}
		cout<<(mp[k][n]*powmod(26, n)%mod)*powmod(25, mod-1-k)%mod<<'\n';
	}
	
	return 0;
}