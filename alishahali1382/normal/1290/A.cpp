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
const int MAXN = 3510, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int check(int val){
	int res=0;
	for (int chap=0; chap<=k; chap++){
		int rast=k-chap;
		int l=1+chap, r=n-rast;
		int mn=inf;
		for (int i=l; i+m-1<=r; i++) mn=min(mn, max(A[i], A[i+m-1]));
		res=max(res, mn);
	}
	return res;
}

void solve(){
	cin>>n>>m>>k;
	vector<int> comp;
	for (int i=1; i<=n; i++) cin>>A[i], comp.pb(A[i]);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	
	k=min(k, m-1);
	m=n-m+1;
	/*
	debug(check(9))
	debug(dp[1][4])
	debug(dp[2][5])
	debug(dp[1][5])
	debug(dp[1][6])
	
	return ;
	*/
	cout<<check(0)<<'\n';
	return ;
	int dwn=0, up=comp.size();
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (check(comp[mid])) dwn=mid;
		else up=mid;
	}
	cout<<comp[dwn]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}
/*
1
6 4 2
2 9 2 3 8 5

*/