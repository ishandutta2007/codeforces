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
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, p;
ll A[MAXN];
map<ll, ll> cnt;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%p, b>>1)%p;
	return powmod(a*a%p, b>>1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		ll tmp=(powmod(A[i], 4)-k*A[i])%p;
		if (tmp<0) tmp+=p;
		ans+=cnt[tmp];
		cnt[tmp]++;
	}
	cout<<ans<<'\n';
	
	return 0;
}