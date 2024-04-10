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

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll S[MAXN];
int ind[MAXN];
pll seg[MAXN<<2];
ll lazy[MAXN<<2];

pll build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={S[tl], -tl};
	int mid=(tl+tr)>>1;
	return seg[id]=min(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void add_lazy(int id, ll lz){
	lazy[id]+=lz;
	seg[id]={seg[id].first+lz, seg[id].second};
}

void shift(int id){
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

pll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return {INF, 0};
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return min(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i];
	build(1, 1, n+1);
	
	for (int i=1; i<=n; i++){
		shift(1);
		int pos=-get(1, 1, n+1, 1, n+1).second;
		A[pos]=i;
		//debug(pos)
		update(1, 1, n+1, pos+1, n+1, -i);
		update(1, 1, n+1, pos, pos+1, +INF);
	}
	for (int i=1; i<=n; i++) cout<<A[i]<<" \n"[i==n];
	
	return 0;
}