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
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int ps[MAXN];
vector<int> D[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	cin>>n;
	for (int i=0; i<n; i++) cin>>x, ps[x]++;
	for (int i=MAXN-2; i; i--) ps[i]+=ps[i+1];
	for (int mx=1; ps[mx]; mx++){
		ll tmp=powmod(D[mx].size(), ps[mx])-powmod(D[mx].size()-1, ps[mx]);
		if (tmp<mod) tmp+=mod;
		for (int i=0; i<D[mx].size()-1; i++) tmp=tmp*powmod(i+1, ps[D[mx][i]]-ps[D[mx][i+1]])%mod;
		//debug2(mx, tmp)
		ans+=tmp;
	}
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}