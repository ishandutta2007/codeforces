#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
 
using namespace std;
typedef long long ll;
typedef /*long */double ld;
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
 
int n, m, k, u, v, x, y, t, a, b, l, r;
ld A[MAXN];
ld seg[MAXN<<2];
ld lazy1[MAXN<<2];
ld lazy2[MAXN<<2];
 
ld build(int id, int tl, int tr){
	lazy1[id]=1;
	if (tr-tl==1) return seg[id]=A[tl];
	int mid=(tl+tr)>>1;
	return seg[id]=build(id<<1, tl, mid)+build(id<<1 | 1, mid, tr);
}

void add_lazy(int id, int tl, int tr, ld Mul, ld Add=0){
	seg[id]*=Mul;
	lazy1[id]*=Mul;
	lazy2[id]*=Mul;
	seg[id]+=Add*(tr-tl);
	lazy2[id]+=Add;
}

void shift(int id, int tl, int tr){
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, tl, mid, lazy1[id], lazy2[id]);
	add_lazy(id<<1 | 1, mid, tr, lazy1[id], lazy2[id]);
	lazy1[id]=1;
	lazy2[id]=0;
}
 
void update(int id, int tl, int tr, int l, int r, ld Mul, ld Add){
	//if (id==1 && type==1 && val==0) debug2(l, r)
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tl, tr, Mul, Add);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, Mul, Add);
	update(id<<1 | 1, mid, tr, l, r, Mul, Add);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}
 
ld get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid, tr, l, r);
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n+1);
	while (m--){
		cin>>t>>l>>r;
		r++;
		if (t==2) cout<<setprecision(5)<<fixed<<get(1, 1, n+1, l, r)<<'\n';
		else{
			cin>>x>>y;
			y++;
			ld s1=get(1, 1, n+1, l, r), s2=get(1, 1, n+1, x, y);
			update(1, 1, n+1, l, r, 1-1./(r-l), s2/(1.*(r-l)*(y-x)));
			update(1, 1, n+1, x, y, 1-1./(y-x), s1/(1.*(r-l)*(y-x)));
		}
	}
	
	
	return 0;
}