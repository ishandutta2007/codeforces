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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<vector<int>> out;

void solve(int n){
	if (n==3){
		out.pb({1, 2, 3});
		out.pb({1, 2, 3});
		return ;
	}
	if (n==4){
		out.pb({1, 2, 3});
		out.pb({1, 2, 4});
		out.pb({1, 3, 4});
		out.pb({2, 3, 4});
		return ;
	}
	solve(n-2);
	if (n&1){
		out.pb({n, n-1, n-2});
		out.pb({n, n-1, n-2});
		for (int i=1; i<n-2; i+=2){
			out.pb({n, i, n-1, i+1});
			out.pb({n, i, n-1, i+1});
		}
		return ;
	}
	out.pb({n, n-1, n-2});
	out.pb({n, n-1, n-3});
	out.pb({n, n-2, n-1, n-3});
	for (int i=1; i+1<n-3; i+=2){
		out.pb({n, i, n-1, i+1});
		out.pb({n, i, n-1, i+1});
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	solve(n);
	cout<<out.size()<<'\n';
	for (auto v:out){
		cout<<v.size()<<' ';
		for (int x:v) cout<<x<<' ';
		cout<<'\n';
	}
	
	return 0;
}