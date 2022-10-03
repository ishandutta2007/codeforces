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
const ll INF=1000000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=30;

ll n, m, k, u, v, x, y, cnt=1;
ll l[MAXN], r[MAXN], T[MAXN];
int seg[MAXN<<2];
int lazy[MAXN<<2];
vector<ll> vec;

void shift(int id, int tl, int tr);

void add_lazy(int id, int tl, int tr, int lz){
	if (lz==3 && lazy[id] && lazy[id]!=3) shift(id, tl, tr);
	int len=tr-tl;
	if (lz==3) lazy[id]=3-lazy[id];
	else lazy[id]=lz;
	if (lz==1) seg[id]=len;
	if (lz==2) seg[id]=0;
	if (lz==3) seg[id]=len-seg[id];
}

void shift(int id, int tl, int tr){
	if (!lazy[id] || tr-tl==1) return ;
	int mid=(tl+tr)>>1;
	//shift(L[id], tl, mid);
	//shift(R[id], mid, tr);
	add_lazy(id<<1, tl, mid, lazy[id]);
	add_lazy(id<<1 | 1, mid, tr, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int type){
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tl, tr, type);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, type);
	update(id<<1 | 1, mid, tr, l, r, type);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}

int get(int id, int tl, int tr){
	if (tr-tl==1 || !seg[id]) return tl;
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	if (seg[id<<1]<mid-tl) return get(id<<1, tl, mid);
	return get(id<<1 | 1, mid, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>T[i]>>l[i]>>r[i], vec.pb(l[i]), vec.pb(r[i]+1), vec.pb(r[i]);
	vec.pb(1);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	
	for (int i=1; i<=n; i++){
		int ll=lower_bound(all(vec), l[i])-vec.begin();
		int rr=lower_bound(all(vec), r[i])-vec.begin();
		//cerr<<"query "<<T[i]<<' '<<ll<<' '<<rr<<endl;
		update(1, 0, vec.size(), ll, rr+1, T[i]);
		cout<<vec[get(1, 0, vec.size())]<<'\n';
	}
	return 0;
}
/*
5
3 20 37
1 1 32
1 1 70
3 40 61
3 50 50

*/