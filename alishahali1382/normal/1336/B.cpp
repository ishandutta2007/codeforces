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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll X, Y, Z, u, v, x, y, t, a, b, ans;
vector<ll> A, B, C;

ll f(ll x, ll y, ll z){
	return (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z);
}

void solve(){
	for (ll y:B){
		ll x=A[0], z=C[0];
		int ind=upper_bound(all(A), y)-A.begin();
		if (ind) x=A[ind-1];
		
		ind=lower_bound(all(C), y)-C.begin();
		if (ind<C.size()) z=C[ind];
		
		//cerr<<x<<' '<<y<<' '<<z<<endl;
		ans=min(ans, f(x, y, z));
	}/*
	if (ans<0){
		debugv(A)
		debugv(B)
		debugv(C)
		debug("shit")
		cerr<<'\n';
		exit(0);
	}*/
}

int Solve(){
	cin>>X>>Y>>Z;
	A.resize(X);
	B.resize(Y);
	C.resize(Z);
	for (int i=0; i<X; i++) cin>>A[i];
	for (int i=0; i<Y; i++) cin>>B[i];
	for (int i=0; i<Z; i++) cin>>C[i];
	sort(all(A));
	sort(all(B));
	sort(all(C));
	ans=3e18;
	
	solve();
	B.swap(C);
	solve();
	B.swap(C);
	
	A.swap(B);
	
	solve();
	B.swap(C);
	solve();
	B.swap(C);
	
	A.swap(B);
	A.swap(C);
	
	solve();
	B.swap(C);
	solve();
	B.swap(C);
	
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
2 2 2
1 2
5 4
6 7


*/