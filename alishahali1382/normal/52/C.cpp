#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
ll seg[MAXN<<2];
ll lazy[MAXN<<2];
char ch;

int build(int id, int tl, int tr){
	if (tl==tr) return seg[id]=A[tl];
	int mid=(tl+tr)>>1;
	return seg[id]=min(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

void add_lazy(int id, ll l){
	lazy[id]+=l;
	seg[id]+=l;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return inf;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return min(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", A+i);
	build(1, 1, n);
	scanf("%d", &m);
	while (m--){
		scanf("%d %d%c", &l, &r, &ch);
		l++;
		r++;
		if (ch=='\n'){
			if (l<=r) printf("%lld\n", get(1, 1, n, l, r));
			else printf("%lld\n", min(get(1, 1, n, 1, r), get(1, 1, n, l, n)));
			continue ;
		}
		scanf("%d", &x);
		
		if (l<=r) update(1, 1, n, l, r, x);
		else{
			update(1, 1, n, 1, r, x);
			update(1, 1, n, l, n, x);
		}
	}
	
	return 0;
}