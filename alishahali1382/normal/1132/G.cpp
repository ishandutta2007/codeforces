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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], R[MAXN];
int stt[MAXN], fnt[MAXN], timer;
int seg[MAXN<<2], lazy[MAXN<<2];
vector<int> G[MAXN];

void dfs(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=n; i; i--){
		for (R[i]=i+1; R[i]<=n && A[R[i]]<=A[i]; R[i]=R[R[i]]);
		G[R[i]].pb(i);
	}
	dfs(n+1);
	for (int i=1; i<=n; i++){
		Add(1, 1, n+1, stt[i], fnt[i], +1);
		if (k<=i){
			Add(1, 1, n+1, stt[i-k], stt[i-k]+1, -inf);
			cout<<seg[1]<<' ';
		}
	}
	
	return 0;
}