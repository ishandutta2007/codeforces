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

int n, k, d, u, v, x, y, t, a, b;
int A[MAXN];
int prv[MAXN];
int lazy[MAXN<<2];
int seg[MAXN<<2];
vector<piii> mn, mx;
map<int, int> last;
pii ans={-1, 1};

void build(int id, int tl, int tr){
	seg[id]=tl;
	lazy[id]=0;
	if (tr-tl==1) return ;
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid, tr);
}

void add_lazy(int id, int lz){
	lazy[id]+=lz;
	seg[id]+=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

int BS(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return inf;
	if (tr-tl==1){
		if (seg[id]<=val) return tl;
		return inf;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	if (l<=tl && tr<=r){
		if (seg[id<<1]<=val) return BS(id<<1, tl, mid, l, r, val);
		return BS(id<<1 | 1, mid, tr, l, r, val);
	}
	return min(BS(id<<1, tl, mid, l, r, val), BS(id<<1 | 1, mid, tr, l, r, val));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>d;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]+=inf;
	
	if (!d){
		ans={-10, 10};
		int L=1, R=1;
		while (L<=n){
			while (A[L]==A[R] && R<=n) R++;
			ans=max(ans, {R-L, -L});
			L=R;
		}
		int l=-ans.second, r=l+ans.first-1;
		cout<<l<<' '<<r<<'\n';
		return 0;
	}
	
	int L=1, R=1;
	while (L<=n){
		while (R<=n && (A[L]-A[R])%d==0) R++;
		for (int i=L; i<R; i++) A[i]/=d;
		mn.clear();
		mx.clear();
		last.clear();
		int tmp=1;
		// ----------------------------------
		build(1, L, R);
		for (int i=L; i<R; i++){
			// k+r >= mx-mn+l
			while (mn.size() && mn.back().second>=A[i]){
				Add(1, L, R, mn.back().first.first, mn.back().first.second, mn.back().second-A[i]);
				mn.pop_back();
			}
			if (mn.size()) mn.pb({{mn.back().first.second, i+1}, A[i]});
			else mn.pb({{L, i+1}, A[i]});
			
			while (mx.size() && mx.back().second<=A[i]){
				Add(1, L, R, mx.back().first.first, mx.back().first.second, A[i]-mx.back().second);
				mx.pop_back();
			}
			if (mx.size()) mx.pb({{mx.back().first.second, i+1}, A[i]});
			else mx.pb({{L, i+1}, A[i]});
			
			prv[i]=last[A[i]];
			last[A[i]]=i;
			tmp=max(tmp, prv[i]+1);
			int bs=BS(1, L, R, tmp, i+1, k+i);
			ans=max(ans, {i-bs, -bs});
		}
		
		
		// ----------------------------------
		L=R;
	}
	int l=-ans.second, r=l+ans.first;
	cout<<l<<' '<<r<<'\n';
	
	return 0;
}