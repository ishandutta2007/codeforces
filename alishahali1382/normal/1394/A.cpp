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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, ted;
ll A[MAXN];
ll B[MAXN], n1;
ll C[MAXN], n2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>m;
	ans=1 + (n-1)/(k+1);
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	for (int i=1; i<=n; i++){
		if (A[i]<=m) B[n1+1]=B[n1]+A[i], n1++;
		else C[n2+1]=C[n2]+A[i], n2++;
	}
	ans=B[n1];
	for (ll x=1; x<=1+(n-1)/(k+1); x++){
		ll y=min(n-x-(x-1)*k, n1);
		if (y<0) continue ;
		ans=max(ans, B[y]+C[x]);
	}
	cout<<ans<<"\n";
	
	return 0;
}