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

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int first[MAXN];
int mark[MAXN];
ll seg[MAXN<<2];
int lazy[MAXN<<2], Mn[MAXN<<2], Mx[MAXN<<2];
vector<int> D[MAXN];

void add_lazy(int id, ll len, int lz){
	Mn[id]=Mx[id]=lazy[id]=lz;
	seg[id]=len*lz;
}

void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}

void Maximize(int id, int tl, int tr, int pos, int val){
	if (tr<=pos || Mn[id]>=val) return ;
	if (pos<=tl && Mx[id]<=val){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, pos, val);
	Maximize(id<<1 | 1, mid, tr, pos, val);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
	Mn[id]=Mn[id<<1];
	Mx[id]=Mx[id<<1 | 1];
}

ll Sum(int id, int tl, int tr, int l, int r){
	if (tr<=l || r<=tl) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Sum(id<<1, tl, mid, l, r) + Sum(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (first[A[i]]) continue ;
		for (int d:D[A[i]]) if (!first[d]) first[d]=i;
	}
	for (int i=2; i<=n; i++) for (int d:D[A[i]]) if (first[d]<i && !mark[d]){
		mark[d]=1;
		Maximize(1, 0, n+1, i, d);
	}
	//for (int i=1; i<=n; i++) cerr<<Sum(1, 0, n+1, i, i+1)<<' ';cerr<<'\n';
	
	memset(mark, 0, sizeof(mark));
	for (int i=n; i; i--){
		ans+=Sum(1, 0, n+1, 0, i);
		for (int d:D[A[i]]){
			mark[d]++;
			if (mark[d]==1) Maximize(1, 0, n+1, first[d], d);
			if (mark[d]==2) Maximize(1, 0, n+1, 0, d);
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*
5
4 1 3 2 5

answer:
16
*/