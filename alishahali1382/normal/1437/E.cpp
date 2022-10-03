#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], comp[MAXN], bad[MAXN];
int Mn[MAXN<<2], Mx[MAXN<<2], lazy[MAXN<<2];

void add_lazy(int id, int val){
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
void Set(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r && Mn[id]==Mx[id]){
		add_lazy(id, val-Mn[id]);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, l, r, val);
	Set(id<<1 | 1, mid, tr, l, r, val);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}
void Minimize(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l || Mx[id]<=val) return ;
	if (l<=tl && tr<=r && Mn[id]==Mx[id]){
		add_lazy(id, val-Mn[id]);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Minimize(id<<1, tl, mid, l, r, val);
	Minimize(id<<1 | 1, mid, tr, l, r, val);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}
int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return inf;
	if (l<=tl && tr<=r) return Mn[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return min(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i], comp[i]=(A[i]-=i);
	sort(comp+1, comp+n+1);
	for (int i=1; i<=n; i++) A[i]=lower_bound(comp+1, comp+n+1, A[i])-comp;//, debug2(i, A[i]);
	while (k--) cin>>x, bad[x]=1;
	for (int i=1; i<=n; i++){
		int x=A[i], dpx=Get(1, 1, n+1, x, x+1);
		if (bad[i]){
			Set(1, 1, n+1, 1, x, inf);
			Set(1, 1, n+1, x, n+1, dpx);
//			for (int j=1; j<=n; j++) cerr<<Get(1, 1, n+1, j, j+1)<<" \n"[j==n];
			continue ;
		}
		add_lazy(1, 1);
		Minimize(1, 1, n+1, x, n+1, dpx);
	}
	if (Mn[1]>=inf) cout<<"-1\n"; 
	else cout<<Mn[1]<<"\n";
	
	return 0;
}