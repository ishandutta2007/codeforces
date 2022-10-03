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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], N;
vector<pii> out;

void add_edge(int u, int v){
	out.pb({u, v});
}

void build(int tl, int tr){
	//cerr<<"build : ";for (int i=tl; i<=tr; i++) cerr<<A[i]<<' ';cerr<<'\n';
	if (tr<tl){
		N++;
		return ;
	}
	if (tl==tr){
		for (int i=N+1; i<=N+A[tl]+1; i++) for (int j=i+1; j<=N+A[tl]+1; j++) add_edge(i, j);
		N+=A[tl]+1;
		return ;
	}
	int cnt=A[tr]-A[tr-1];
	for (int i=tl+1; i<tr; i++) A[i]-=A[tl];
	build(tl+1, tr-1);
	N+=cnt;
	while (A[tl]--){
		N++;
		for (int i=1; i<N; i++) add_edge(i, N);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, n);
	cout<<out.size()<<'\n';
	for (pii p:out) cout<<p.first<<' '<<p.second<<'\n';
	
	return 0;
}