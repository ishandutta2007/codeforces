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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
vector<int> A[MAXN];

int solve(vector<int> &vec){
	vector<int> cnt(n, 0);
	for (int i=0; i<n; i++){
		if (vec[i]%m) continue ;
		vec[i]/=m;
		if (vec[i]>=n || vec[i]<0) continue ;
		cnt[(n+i-vec[i])%n]++;
	}
	int res=0;
	for (int i=0; i<n; i++) res=max(res, cnt[i]-i);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++) A[i].resize(n);
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>A[j][i], A[j][i]--;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++) A[i][j]-=i;
		ans+=solve(A[i]);
	}
	cout<<n*m-ans<<'\n';
	
	return 0;
}