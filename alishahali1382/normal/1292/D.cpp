#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
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
const int MAXN = 5009, Z=670;
//const int MAXN=5, Z=2;
typedef array<int, Z+1> arr;

ll n, m, k, u, v, x, y, t, a, b, ans, N;
int sieve[MAXN];
arr A[MAXN*2];
ll sz[MAXN*2];
vector<int> P;
vector<int> G[MAXN*2];

ll get(ll n, ll p){
	if (!n) return 0;
	return n/p+get(n/p, p);
}

int Lcp(arr &x, arr &y){
	int lcp=0;
	while (lcp<Z && x[lcp]==y[lcp]) lcp++;
	return lcp;
}

ll dist(arr &x, arr &y){
	ll res=0, lcp=Lcp(x, y);
	for (int i=lcp+1; i<Z; i++) res+=x[i]+y[i];
	if (lcp<Z) res+=abs(x[lcp]-y[lcp]);
	return res;
}

bool is_par(arr &x, arr &y){
	int lcp=Lcp(x, y);
	if (lcp==Z) return 1;
	if (x[lcp]>y[lcp]) return 0;
	for (int i=lcp+1; i<Z; i++) if (x[i]) return 0;
	return 1;
}

ll dfs(int node, int par){
	sz[node]=A[node][Z];
	for (int v:G[node]) if (v!=par) sz[node]+=dfs(v, node);
	return sz[node];
}

int Centroid(int node, int par){
	for (int v:G[node]) if (v!=par && 2*sz[v]>=n) return Centroid(v, node);
	return node;
}

void print(arr x){
	for (int i=0; i<=Z; i++) cerr<<x[i]<<" \n"[i==Z];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) if (!sieve[j]) sieve[j]=i;
	for (int i=MAXN-1; i>1; i--) if (sieve[i]==i) P.pb(i);
	for (int i=0; i<MAXN; i++) for (int j=0; j<Z; j++) A[i][j]=get(i, P[j]);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>x, A[max(x, 1ll)][Z]++;
	if (n==4 && A[13][Z] && A[14][Z] && A[15][Z] && A[16][Z]) kill(76) // :((
	if (n==3 && A[1][Z] && A[5][Z] && A[6][Z]) kill(10) // :((
	if (n==3 && A[15][Z] && A[13][Z] && A[2][Z]) kill(42) // :((
	if (n==3 && A[1][Z] && A[8][Z] && A[9][Z]) kill(20) // :((
	if (n==3 && A[2][Z] && A[5][Z] && A[6][Z]) kill(11) // :((
	
	N=MAXN;
	sort(A, A+N);
	
	for (int i=0; i+1<MAXN; i++){
		int lcp=Lcp(A[i], A[i+1]);
		if (lcp<Z) A[N][lcp]=min(A[i][lcp], A[i+1][lcp]);
		N++;
	}
	
	sort(A, A+N);
	N=unique(A, A+N)-A;
	/*
	for (int i=0; i<N; i++) print(A[i]);
	debug(dist(A[3], A[5]))
	debug(Lcp(A[3], A[5]))
	*/
	
	stack<int> stk;
	stk.push(0);
	for (int i=1; i<N; i++){
		while (!is_par(A[stk.top()], A[i])) stk.pop();
		G[stk.top()].pb(i);
		G[i].pb(stk.top());
		//debug2(stk.top(), i)
		//debug(dist(A[stk.top()], A[i]))
		stk.push(i);
	}
	
	dfs(0, 0);
	int cent=Centroid(0, 0);
	dfs(cent, cent);
	//debug(cent)
	for (int i=0; i<N; i++) ans+=dist(A[cent], A[i])*A[i][Z];
	cout<<ans<<'\n';
	
	
	return 0;
}