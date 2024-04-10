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
const int MAXN = 1000010, LOG=18;

ll n, m, k, u, v, x, y, t, a, b, ans;
pii table[MAXN][LOG];
ll dp[MAXN];

pii RMQ(int l, int r){
	int lg=log2(r-l);
	return max(table[l][lg], table[r-(1<<lg)][lg]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++) cin>>table[i][0].first, table[i][0].second=i;
	table[n][0]={n, n};
	for (int j=1; j<LOG; j++) for (int i=1; i<=n; i++) table[i][j]=max(table[i][j-1], table[i+(1<<(j-1))][j-1]);
	for (int i=n; i; i--){
		int pos=RMQ(i, table[i][0].first+1).second;
		dp[i]=dp[pos]+(n-i)-(table[i][0].first-pos);
		ans+=dp[i];
	}
	cout<<ans<<'\n';
		
	return 0;
}