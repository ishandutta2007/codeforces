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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int dist[MAXN], par[MAXN];
pii seg[MAXN<<2];
vector<pii> vec[MAXN];
vector<int> compress;
queue<int> Q;

void update(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=vec[pos].back();
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos);
	update(id<<1 | 1, mid, tr, pos);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

pii get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return min(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		compress.pb(A[i]);
		compress.pb(B[i]);
		compress.pb(C[i]);
		compress.pb(D[i]);
	}
	compress.pb(0);
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(all(compress), A[i])-compress.begin();
		B[i]=lower_bound(all(compress), B[i])-compress.begin();
		C[i]=lower_bound(all(compress), C[i])-compress.begin();
		D[i]=lower_bound(all(compress), D[i])-compress.begin();
	}
	for (int i=1; i<=n; i++) vec[A[i]].pb({B[i], i});
	seg[0]={inf, -1};
	for (int i=0; i<MAXN; i++) vec[i].pb(seg[0]), sort(all(vec[i])), reverse(all(vec[i])), update(1, 0, MAXN, i);
	
	memset(dist, 63, sizeof(dist));
	dist[0]=0;
	Q.push(0);
	
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		while (1){
			int u=get(1, 0, MAXN, 0, C[v]+1).second;
			if (u==-1 || B[u]>D[v]) break ;
			vec[A[u]].pop_back();
			update(1, 0, MAXN, A[u]);
			dist[u]=dist[v]+1;
			par[u]=v;
			Q.push(u);
		}
	}
	
	if (dist[n]>=inf) kill(-1)
	cout<<dist[n]<<'\n';
	vector<int> out;
	for (int v=n; v; v=par[v]) out.pb(v);
	reverse(all(out));
	for (int v:out) cout<<v<<' ';
	
	return 0;
}