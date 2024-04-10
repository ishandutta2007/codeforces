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

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int px[MAXN];
int ans[MAXN];
int seg[MAXN<<2];
map<int, int> last;
vector<pii> vec[MAXN];

void update(int id, int tl, int tr, int pos, int val){
	if (tr<=pos || pos<tl) return ;
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos, val);
	update(id<<1 | 1, mid, tr, pos, val);
	seg[id]=seg[id<<1] ^ seg[id<<1 | 1];
}

int get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) ^ get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		px[i]=px[i-1]^A[i];
	}
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		ans[i]=px[y]^px[x-1];
		vec[y+1].pb({x, i});
	}
	for (int i=1; i<=n+1; i++){
		for (pii p:vec[i]) ans[p.second]^=get(1, 1, n+1, p.first, i);
		update(1, 1, n+1, last[A[i]], 0);
		update(1, 1, n+1, i, A[i]);
		last[A[i]]=i;
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
5
1 2 1 3 3
1
1 5
*/