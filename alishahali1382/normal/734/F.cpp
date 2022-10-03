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
const int MAXN = 200010, LOG=31;

ll n, m, k, u, v, x, y, t, a, b, sum;
ll A[MAXN], B[MAXN], C[MAXN];
ll cnt[LOG];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>B[i];
	for (int i=1; i<=n; i++) cin>>C[i], sum+=C[i]+B[i];
	if (sum%(2*n)) kill(-1)
	sum/=2*n;
	for (int i=1; i<=n; i++){
		A[i]=B[i]+C[i]-sum;
		if (A[i]%n) kill(-1)
		A[i]/=n;
		for (int j=0; j<LOG; j++) if (A[i]&(1<<j)) cnt[j]++;
	}
	for (int i=1; i<=n; i++){
		for (int j=0; j<LOG; j++) if (A[i]&(1<<j)) B[i]-=cnt[j]*(1<<j);
		if (B[i]) kill(-1)
	}
	
	for (int i=1; i<=n; i++) cout<<A[i]<<' ';
	
	return 0;
}