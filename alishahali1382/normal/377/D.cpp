#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, pos;
int L[MAXN], R[MAXN], V[MAXN];
vector<int> vv[MAXN], vr[MAXN];
pii seg[MAXN<<2], ans;
int lazy[MAXN<<2];

void build(int id, int tl, int tr){
	seg[id]={0, tl};
	if (tl==tr) return ;
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
}

void shift(int id){
	if (!lazy[id]) return ;
	lazy[id<<1]+=lazy[id];
	lazy[id<<1 | 1]+=lazy[id];
	seg[id<<1].first+=lazy[id];
	seg[id<<1 | 1].first+=lazy[id];
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		lazy[id]+=val;
		seg[id].first+=val;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

pii get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return {0, 0};
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>L[i]>>V[i]>>R[i];
		vv[V[i]].pb(i);
		vr[R[i]+1].pb(i);
	}
	build(1, 1, MAXN-1);
	for (int i=1; i<MAXN; i++){
		for (int j:vv[i]) update(1, 1, MAXN-1, L[j], V[j], 1);
		for (int j:vr[i]) update(1, 1, MAXN-1, L[j], V[j], -1);
		pii p=get(1, 1, MAXN-1, 1, i);
		if (p>ans){
			ans=p;
			pos=i;
		}
	}
	debugp(ans)
	debug(pos)
	cout<<ans.first<<'\n';
	for (int i=1; i<=n; i++) if (L[i]<=ans.second && ans.second<=V[i] && V[i]<=pos && pos<=R[i]) cout<<i<<' ';
	
	return 0;
}
/*
4
1 1 1
3 3 3
1 1 1
1 2 3
*/