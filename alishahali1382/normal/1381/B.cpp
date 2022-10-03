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
const int MAXN=4010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], C[MAXN];
bitset<2010> dp;

void Solve(){
	cin>>n;
	for (int i=1; i<=2*n; i++) cin>>A[i], C[i]=0;
	for (int i=1; i<=2*n;){
		int j=i+1;
		while (A[j]<A[i] && j<=2*n) j++;
		C[j-i]++;
		i=j;
	}
	for (int i=1; i<=n; i++) while (C[i]>2){
		C[i]-=2;
		C[2*i]++;
	}
	dp.reset();
	dp.set(0);
	for (int i=1; i<=n; i++) for (int j=0; j<C[i]; j++) dp|=(dp<<i);
	if (dp[n]) cout<<"YES\n";
	else cout<<"NO\n";
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
3
1 2 3 4 5 6

*/