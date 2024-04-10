#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int) x.size())

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=18;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], ps[MAXN];
vector<piii> seg[MAXN<<2];

inline int inter(pii a, pii b){
	if (a.first==b.first) return (a.second<b.second?inf:-inf);
	return (b.second-a.second)/(a.first-b.first) + ((b.second-a.second)%(a.first-b.first)>0);
}
inline void add(vector<piii> &A, pii b){
	while (SZ(A) && inter(A.back().second, b)<=A.back().first) A.pop_back();
	if (!SZ(A)) A.pb({-inf, b});
//	else if (A[sz-1].second.first==b.first) A[sz-1].second=min(A[sz-1].second, b);
	else{
		A.pb({inter(A.back().second, b), b});
	}
}
inline int get(vector<piii> &A, int x){
	int pos=upper_bound(all(A), piii(x, {inf, inf}))-A.begin()-1;
	return A[pos].second.first*x + A[pos].second.second;
}
void Build(int id, int h, int tl, int tr){
	if (tr-tl==1){
		add(seg[id], {A[tl], A[tl]*tl-ps[tl]});
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, h+1, tl, mid);
	Build(id<<1 | 1, h+1, mid, tr);
	
	vector<pii> vec;
	for (auto p:seg[id<<1]) vec.pb(p.second);
	for (auto p:seg[id<<1 | 1]) vec.pb(p.second);
	sort(all(vec));
	for (int i=vec.size()-1; ~i; i--) add(seg[id], vec[i]);
	
	
}
int Get(int id, int h, int tl, int tr, int l, int r, int x){
	if (r<=tl || tr<=l) return inf;
	if (l<=tl && tr<=r) return get(seg[id], x);
	int mid=(tl+tr)>>1;
	return min(Get(id<<1, h+1, tl, mid, l, r, x), Get(id<<1 | 1, h+1, mid, tr, l, r, x));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ps[i]=ps[i-1]+A[i];
	Build(1, 0, 0, n+1);
	cin>>m;
	while (m--){
		cin>>x>>y;
		cout<<ps[y]+Get(1, 0, 0, n+1, y-x, y+1, x-y)<<"\n";
	}
	
	return 0;
}
/*
5
2 2 3 3 3
1
2 3

*/