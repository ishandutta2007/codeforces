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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=60;

int n, m, k, u, v, x, y, t, a, b;
ll A[MAXN], ans, fix, X;
ll g[MAXN];
bitset<MAXN> B[LOG], C;

bool check(ll num, ll fix){
	vector<ll> vec;
	for (int i=0; i<LOG; i++){
		ll x=g[i]&fix;
		for (ll a:vec) if (a&-a&x) x^=a;
		if (!x) continue ;
		for (ll &a:vec) if (x&-x&a) a^=x;
		vec.pb(x);
	}
	for (ll a:vec) if (a&-a&num) num^=a;
	return (num==0);	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		X^=A[i];
		ll x=A[i];
		for (int j=LOG-1; ~j; j--) x=min(x, x^g[j]);
		if (!x) continue ;
		x=A[i];
		C.reset();
		C.set(i);
		for (int j=LOG-1; ~j; j--) if (x>(x^g[j])){
			x^=g[j];
			C^=B[j];
		}
		int bit=63-__builtin_clzll(x);
		g[bit]=x;
		B[bit]=C;
	}
	for (int i=LOG-1; ~i; i--) if (!get(X, i)){
		fix|=(1ll<<i);
		if (check(ans|(1ll<<i), fix)) ans|=(1ll<<i);
	}
	for (int i=LOG-1; ~i; i--) if (get(X, i)){
		fix|=(1ll<<i);
		if (!check(ans, fix)) ans|=(1ll<<i);
	}
	
	debug(ans)
	C.reset();
	for (int j=LOG-1; ~j; j--) if (ans>(ans^g[j])){
		ans^=g[j];
		C^=B[j];
	}
	for (int i=1; i<=n; i++) cout<<2-C[i]<<" \n"[i==n];
	
	return 0;
}