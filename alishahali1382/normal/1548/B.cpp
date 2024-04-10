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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll seg[MAXN<<1];

void Set(int pos, ll val){
	for (seg[pos+=n]=val; pos>1; pos>>=1) seg[pos>>1]=__gcd(seg[pos], seg[pos^1]);
}

int Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	fill(seg, seg+2*n+5, 0);
	ans=0;
	int j=1;
	for (int i=2; i<=n; i++){
		Set(i, A[i]-A[i-1]);
		while (seg[1]==1 || seg[1]==-1) Set(++j, 0);
		ans=max(ans, i-j);
//		debug2(i, j)
//		debug(seg[1])
	}
	cout<<ans+1<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
5
1 5 2 4 6

*/