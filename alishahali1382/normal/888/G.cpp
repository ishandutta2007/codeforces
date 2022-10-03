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
#define get(x, i) (((x)>>(i))&1)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=30;

int n, m, k, u, v, x, y, t, a, b;
ll ans;
int A[MAXN];
int TR[MAXN*LOG][3], ts;

ll dfs(int v1, int v2){
	
}

void Add(int x, int w){
	int node=0;
	for (int j=LOG-1; j>=0; j--){
		int c=get(x, j);
		if (!TR[node][c]) TR[node][c]=++ts;
		node=TR[node][c];
		TR[node][2]+=w;
	}
}

int Get(int x){
	int res=0, node=0;
	for (int j=LOG-1; j>=0; j--){
		int c=get(x, j);
		if (!TR[TR[node][c]][2]) c^=1, res|=(1<<j);
		node=TR[node][c];
	}
	return res;
}

int lcp(int x, int y){
	return __builtin_clz(x^y)-2;
}

void solve(int tl, int tr){
	if (tr-tl<2) return ;
	int mid=tl+1, tmp=LOG;
	for (int i=tl+1; i<tr; i++) if (lcp(A[i-1], A[i])<tmp){
		tmp=lcp(A[i-1], A[i]);
		mid=i;
	}
	solve(tl, mid);
	solve(mid, tr);
	for (int i=tl; i<mid; i++) Add(A[i], +1);
	
	int mn=2*inf;
	for (int i=mid; i<tr; i++) mn=min(mn, Get(A[i]));
	ans+=mn;
	
	for (int i=tl; i<mid; i++) Add(A[i], -1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	n=unique(A+1, A+n+1)-A-1;
	solve(1, n+1);
	cout<<ans<<'\n';
	
	return 0;
}