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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=5010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], L[MAXN][MAXN];

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) L[i][j]=0;
		for (int j=1; j<=i; j++) L[i][A[j]]++;
		for (int j=1; j<=n; j++) L[i][j]+=L[i][j-1];
	}
	ll ans=0;
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++){
		ans+=L[i-1][A[j]-1]*(A[i]-L[j][A[i]]);
	}
	
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
4
1 4 2 3

*/