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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][10];
vector<int> vec[MAXN][4];
vector<int> ord;

inline ll calc(int i, int j){
	ll res=0;
	for (int jj=j, ii=0; ii<ord.size(); ii++, jj=(jj+1)%10) res+=(1+(jj==9))*ord[ii];
	return res+dp[i+1][(j+ord.size())%10];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>k;
		while (k--){
			cin>>a>>b;
			vec[i][a].pb(b);;
		}
		for (int j=1; j<=3; j++){
			sort(all(vec[i][j]));
			reverse(all(vec[i][j]));
			if (vec[i][j].size()>3) vec[i][j].resize(3);
		}
	}
	for (int i=n; i; i--) for (int j=0; j<10; j++){
		dp[i][j]=dp[i+1][j];
		
		if (vec[i][1].size()){
			ord.clear();
			ord.pb(vec[i][1][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
		
		if (vec[i][2].size()){
			ord.clear();
			ord.pb(vec[i][2][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
		
		if (vec[i][3].size()){
			ord.clear();
			ord.pb(vec[i][3][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
		
		if (vec[i][1].size()>=2){
			ord.clear();
			ord.pb(vec[i][1][0]);
			ord.pb(vec[i][1][1]);
			dp[i][j]=max(dp[i][j], calc(i, j));
			
			ord.clear();
			ord.pb(vec[i][1][1]);
			ord.pb(vec[i][1][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
		
		if (vec[i][1].size() && vec[i][2].size()){
			ord.clear();
			ord.pb(vec[i][1][0]);
			ord.pb(vec[i][2][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
			
			ord.clear();
			ord.pb(vec[i][2][0]);
			ord.pb(vec[i][1][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
		
		if (vec[i][1].size()>=3){
			ord.clear();
			ord.pb(vec[i][1][0]);
			ord.pb(vec[i][1][1]);
			ord.pb(vec[i][1][2]);
			dp[i][j]=max(dp[i][j], calc(i, j));
			
			ord.clear();
			ord.pb(vec[i][1][1]);
			ord.pb(vec[i][1][0]);
			ord.pb(vec[i][1][2]);
			dp[i][j]=max(dp[i][j], calc(i, j));
			
			ord.clear();
			ord.pb(vec[i][1][2]);
			ord.pb(vec[i][1][1]);
			ord.pb(vec[i][1][0]);
			dp[i][j]=max(dp[i][j], calc(i, j));
		}
	}
	cout<<dp[1][0]<<'\n';
	
	return 0;
}