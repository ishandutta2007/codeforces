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
const int inf=1000000000;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	dp[3]=1;
	for (int i=4; i<=n+1; i++){
		dp[i]=dp[i-1];
		for (int j=1; j<i; j++) dp[i]+=(i-j>j);
	}
	if (m>dp[n]) kill(-1)
	int shit=0;
	for (int i=3; i<=n+1 && !shit; i++) if (dp[i]>m) shit=i-1;
	for (int i=1; i<=shit; i++) cout<<i<<' ';
	m-=dp[shit];
	if (!m){
		int q=inf-1;
		vector<int> vec;
		n-=shit;
		shit+=2;
		while (n){
			n--;
			vec.pb(q);
			q-=shit;
		}
		reverse(all(vec));
		for (int x:vec) cout<<x<<' ';
		cout<<'\n';
		return 0;
	}
	n-=shit+1;
	if (n<0) kill(-1)
	for (int i=shit+1; i<=2*shit-1; i++){
		int tmp=i-shit;
		tmp=shit-tmp;
		tmp=(tmp+1)/2;
		if (m==tmp){
			cout<<i<<' ';
			shit=i;
			break ;
		}
	}
	
	shit+=2;
	int q=inf-1;
	vector<int> vec;
	while (n){
		n--;
		vec.pb(q);
		q-=shit;
	}
	sort(all(vec));
	for (int x:vec) cout<<x<<' ';
	cout<<'\n';
	
	return 0;
}