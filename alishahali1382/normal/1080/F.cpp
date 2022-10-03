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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=600010, SZ=20*MAXN;

int n, m, k, u, v, x, y, t, l, r;
int LL[MAXN], RR[MAXN], P[MAXN];
int seg[SZ], L[SZ], R[SZ], ts;
int root[MAXN];
vector<int> vec[MAXN], comp;

int Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=++ts;
	if (tr-tl==1){
		seg[res]=max(seg[id], val);
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Set(L[id], tl, mid, pos, val);
	R[res]=Set(R[id], mid, tr, pos, val);
	seg[res]=min(seg[L[res]], seg[R[res]]);
	return res;
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return inf;
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return min(Get(L[id], tl, mid, l, r), Get(R[id], mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=k; i++){
		scanf("%d%d%d", LL+i, RR+i, P+i);
		comp.pb(LL[i]);
		comp.pb(++RR[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=k; i++){
		LL[i]=lower_bound(all(comp), LL[i])-comp.begin()+1;
		RR[i]=lower_bound(all(comp), RR[i])-comp.begin()+1;
		vec[RR[i]].pb(i);
	}
	for (int i=1; i<MAXN; i++){
		root[i]=root[i-1];
		for (int id:vec[i]) root[i]=Set(root[i], 1, n+1, P[id], LL[id]);
	}
	
	while (m--){
		scanf("%d%d%d%d", &x, &y, &l, &r);
		r++;
		y++;
		l=lower_bound(all(comp), l)-comp.begin()+1;
		r=upper_bound(all(comp), r)-comp.begin();
		int tmp=Get(root[r], 1, n+1, x, y);
		if (tmp<l) printf("no\n");
		else printf("yes\n");
		fflush(stdout);
	}
	
	
	return 0;
}
/*
2 1 3
1 3 1
2 4 2
2 3 1
1 2 2 4

*/