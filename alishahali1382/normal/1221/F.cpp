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

ll n, m, k, u, v, x, y, t, ansx=inf, ansy=inf, ans;
int X[MAXN], Y[MAXN], C[MAXN];
pll seg[MAXN<<2];
ll lazy[MAXN<<2];
vector<int> vec[MAXN];
vector<int> compress;

pll build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={0, tl};
	return seg[id]=max(build(id<<1, tl, (tl+tr)>>1), build(id<<1 | 1, (tl+tr)>>1, tr));
}

void add_lazy(int id, ll lz){
	seg[id].first+=lz;
	lazy[id]+=lz;
}

void shift(int id){
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

pll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return {-INF, 0};
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return max(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>X[i]>>Y[i]>>C[i], compress.pb(X[i]), compress.pb(Y[i]);
	compress.pb(0);
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	//debugv(compress)
	while (compress.size()<=MAXN) compress.pb(inf);
	for (int i=1; i<=n; i++){
		X[i]=lower_bound(all(compress), X[i])-compress.begin();
		Y[i]=lower_bound(all(compress), Y[i])-compress.begin();
		if (X[i]<Y[i]) swap(X[i], Y[i]);
		vec[X[i]].pb(i);
	}
	build(1, 0, MAXN);
	
	for (int i=0; i<MAXN; i++){
		for (int id:vec[i]) update(1, 0, MAXN, 0, Y[id]+1, C[id])/*, cerr<<"add "<<id<<' '<<Y[id]<<'\n'*/;
		pll tmp=get(1, 0, MAXN, 0, i+1);
		//if (i<5) {cerr<<i<<" : ";debugp(tmp)}
		if (tmp.first>ans){
			ans=tmp.first;
			//debug(i)
			ansy=compress[i];
			ansx=compress[tmp.second];
		}
		update(1, 0, MAXN, 0, i+1, compress[i]-compress[i+1]);
	}
	cout<<ans<<'\n';
	cout<<ansx<<' '<<ansx<<' '<<ansy<<' '<<ansy<<'\n';
	
	return 0;
}