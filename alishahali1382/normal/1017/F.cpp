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
#define int unsigned

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100000010, SQ=17500;

int n, m, k, u, v, x, y, t, a, b, ans, A, B, C, D;
vector<int> prime;
bool sieve[SQ];

void update(int p){
	int val=0;
	for (int tmp=n/p; tmp; tmp/=p) val+=tmp;
	ans+=val*(D+p*(C+p*(B+p*A)));
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>A>>B>>C>>D;
	for (int i=2; i<SQ; i++) if (!sieve[i]){
		prime.pb(i);
		update(i);
		for (int j=i*i; j<SQ; j+=i) sieve[j]=1;
	}
	for (int x=SQ; x<=n; x+=SQ){
		memset(sieve, 0, sizeof(sieve));
		for (int p:prime) for (int i=(x+p-1)/p*p; i<x+SQ; i+=p) sieve[i-x]=1;
		for (int i=0; i<SQ; i++) if (!sieve[i]) update(i+x);
	}
	cout<<ans<<'\n';
	
	return 0;
}