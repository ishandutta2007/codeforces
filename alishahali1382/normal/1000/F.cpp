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
const int MAXN = 500010, LOG=19;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int ans[MAXN];
int last[MAXN];
int prv[MAXN];
pii seg[MAXN<<2];
vector<pii> query[MAXN];

void update(int id, int tl, int tr, int pos, pii val){
	//if (id==1) cerr<<"update "<<pos<<' '<<"{"<<val.first<<", "<<val.second<<"}\n";
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos, val);
	update(id<<1 | 1, mid, tr, pos, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

pii get(int id, int tl, int tr, int l, int r){
	//if (id==1) cerr<<"get "<<l<<' '<<r<<endl;
	if (r<=tl || tr<=l) return {inf, inf};
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
		cin>>A[i];
		prv[i]=last[A[i]];
		last[A[i]]=i;
	}
	
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		query[y+1].pb({x, i});
	}
	memset(seg, 31, sizeof(seg));
	
	for (int i=1; i<=n+1; i++){
		for (pii p:query[i]){
			pii tmp=get(1, 1, n+1, p.first, i);
			if (tmp.first<p.first) ans[p.second]=tmp.second;
		}
		update(1, 1, n+1, prv[i], {inf, inf});
		update(1, 1, n+1, i, {prv[i], A[i]});
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}