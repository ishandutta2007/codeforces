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
const int MAXN = 103, LOG=15;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int B[MAXN];
map<vector<int>, int> mp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int mask=0; mask<(1<<15); mask++){
		vector<int> vec(n, 0);
		for (int i=1; i<=n; i++) B[i]=__builtin_popcount((A[i]>>15)^mask);
		for (int i=1; i<n; i++) vec[i]=B[i]-B[i+1];
		mp[vec]=mask;
	}
	for (int mask=0; mask<(1<<15); mask++){
		vector<int> vec(n, 0);
		for (int i=1; i<=n; i++) B[i]=__builtin_popcount((A[i]&((1<<15)-1))^mask);
		for (int i=1; i<n; i++) vec[i]=B[i+1]-B[i];
		if (mp.count(vec)){
			kill((mp[vec]<<15)+mask)
		}
	}
	kill(-1)
	
	return 0;
}