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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, type, l, r;
ll seg[MAXN<<2], lazy[MAXN<<2];
int same[MAXN<<2];

void build(int id, int tl, int tr){
	if (tl==tr){
		same[id]=tl;
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
}

void shift(int id, int tl, int tr){
	if (!same[id] || tl==tr) return ;
	int mid=(tl+tr)>>1;
	seg[id<<1]+=(mid-tl+1)*lazy[id];
	seg[id<<1 | 1]+=(tr-mid)*lazy[id];
	
	lazy[id<<1]+=lazy[id];
	lazy[id<<1 | 1]+=lazy[id];
	same[id<<1]=same[id<<1 | 1]=same[id];
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, ll val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r && same[id]){
		shift(id, tl, tr);
		lazy[id]+=abs(same[id]-val);
		seg[id]+=abs(same[id]-val)*(tr-tl+1);
		same[id]=val;
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
	same[id]=(l<=tl && tr<=r)*val;
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	build(1, 1, n);
	
	while (m--){
		cin>>type>>l>>r;
		if (type==2) cout<<get(1, 1, n, l, r)<<'\n';
		else{
			cin>>x;
			update(1, 1, n, l, r, x);
		}
	}
	
	return 0;
}