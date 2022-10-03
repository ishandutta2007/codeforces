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
const int MAXN = 100010, LOG=20;

struct node{
	int c0=0, c1=0;
	node(int a=0, int b=0): c0(a), c1(b){}
	void rev(){
		swap(c0, c1);
	}
} seg[MAXN<<2];

node operator +(node x, node y){ return node(x.c0+y.c0, x.c1+y.c1);}

ll n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
bool lazy[MAXN<<2];
vector<int> v1[MAXN], v2[MAXN];

node build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=node(1, 0);
	int mid=(tl+tr)>>1;
	return seg[id]=build(id<<1, tl, mid) + build(id<<1 | 1, mid, tr);
}

void add_lazy(int id){
	lazy[id]^=1;
	seg[id].rev();
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1);
	add_lazy(id<<1 | 1);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r);
	update(id<<1 | 1, mid, tr, l, r);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

node get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	while (m--){
		cin>>l>>r;
		l=lower_bound(A+1, A+n+1, l)-A;
		r=upper_bound(A+1, A+n+1, r)-A;
		//debug2(l, r)
		v1[l].pb(r);
		v2[r].pb(l);
	}
	build(1, 1, n+1);
	for (int i=1; i<=n; i++){
		for (int x:v1[i]) update(1, 1, n+1, i, x);
		for (int x:v2[i]) update(1, 1, n+1, x, i);
		ll cnt=get(1, 1, n+1, 1, i).c1+get(1, 1, n+1, i+1, n+1).c0;
		//debug(cnt)
		ans+=cnt*(cnt-1)/2;
	}
	cout<<n*(n-1)*(n-2)/6-ans<<'\n';
	
	return 0;
}