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
const int inf=10000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[3][MAXN];
int B[3][3*MAXN];
int seg[MAXN<<2], lazy[MAXN<<2], Mn[MAXN<<2], Mx[MAXN<<2];
vector<int> compress;
set<piii> st;

int build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=tl;
	int mid=(tl+tr)>>1;
	return seg[id]=min(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void add_lazy(int id, int val){
	seg[id]+=val;
	Mn[id]+=val;
	Mx[id]+=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mn[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}

void Maximize(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l || Mn[id]>=val) return ;
	if (l<=tl && tr<=r && Mn[id]==Mx[id]){
		add_lazy(id, val-Mx[id]);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, l, r, val);
	Maximize(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}

void Condition(int num){
	if (!B[1][num] && B[2][num]) Maximize(1, 0, n+1, 0, n+1, B[2][num]);
	if (B[1][num] && !B[2][num]) Maximize(1, 0, n+1, 0, B[1][num], inf);
	if (B[1][num] && B[2][num]) Maximize(1, 0, n+1, 0, B[1][num], B[2][num]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int j=0; j<3; j++) for (int i=1; i<=n; i++) cin>>A[j][i], compress.pb(A[j][i]);
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	for (int j=0; j<3; j++) for (int i=n; i; i--) B[j][A[j][i]=lower_bound(all(compress), A[j][i])-compress.begin()]=i;

	build(1, 0, n+1);
	for (int i=0; i<compress.size(); i++) if (!B[0][i]){
		if (!B[1][i] && !B[2][i]) continue ;
		Condition(i);
	}

	ans=seg[1]+n;
	for (int i=n; i; i--){
		int num=A[0][i];
		if (B[0][num]==i){
			if (!B[1][num] && !B[2][num]) break ;
			Condition(num);
		}
		ans=min(ans, seg[1]+i-1);
	}
	cout<<ans<<'\n';
	
	return 0;
}