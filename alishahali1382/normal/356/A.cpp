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
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int L[MAXN], R[MAXN], X[MAXN];
int lazy[MAXN<<2];

void add_lazy(int id, int lz){
	lazy[id]=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
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
}

void print(int id, int tl, int tr){
	if (tr-tl==1){
		cout<</*(tl!=lazy[id])**/lazy[id]<<' ';
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	print(id<<1, tl, mid);
	print(id<<1 | 1, mid, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=m; i; i--) cin>>L[i]>>R[i]>>X[i];
	for (int i=1; i<=m; i++){
		update(1, 1, n+1, L[i], X[i], X[i]);
		update(1, 1, n+1, X[i]+1, R[i]+1, X[i]);
	}
	print(1, 1, n+1);
	
	return 0;
}