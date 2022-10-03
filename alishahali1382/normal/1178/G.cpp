#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> line;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=200010, SQ=230, NSQ=MAXN/SQ+1;

int n, m, k, u, v, x, y, t, a, b, ans;
int AA[MAXN], BB[MAXN], par[MAXN];
int stt[MAXN], fnt[MAXN], timer;
int L[NSQ][2], R[NSQ][2], lazy[NSQ], P[MAXN];
ll A[MAXN], B[MAXN];
pair<ll, line> cht[NSQ][2][SQ];
vector<int> G[MAXN];

void dfs(int node){
	A[timer]=AA[node];
	B[timer]=BB[node];
	stt[node]=timer++;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}
inline ll Inter(line a, line b){
	if (a.first==b.first) return (a.second<=b.second?-INF:INF);
	return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
}
inline void add(pair<ll, line> *A, int &L, int &R, line b){
	while (L<R && Inter(A[R-1].second, b)<=A[R-1].first) R--;
	if (L<R) A[R]={Inter(A[R-1].second, b), b}, R++;
	else A[R++]={-INF, b};
}
inline ll get(pair<ll, line> *A, int &L, int &R, int x){
	while (L+1<R && A[L+1].first<=x) L++;
	return x*A[L].second.first + A[L].second.second;
}
void Build(int id){
	int tl=id*SQ, tr=min(id*SQ+SQ, n);
	L[id][0]=L[id][1]=R[id][0]=R[id][1]=0;
	for (int i=tl; i<tr; i++){
		A[P[i]]+=lazy[id];
		add(cht[id][0], L[id][0], R[id][0], {B[P[i]], B[P[i]]*A[P[i]]});
	}
	lazy[id]=0;
	for (int i=tr-1; i>=tl; i--) add(cht[id][1], L[id][1], R[id][1], {-B[P[i]], -B[P[i]]*A[P[i]]});
}
void Add(int l, int r, int val){
	int idl=-1, idr=-1;
	while (l%SQ && l<r) idl=l/SQ, A[l++]+=val;
	while (r%SQ && l<r) idr=r/SQ, A[--r]+=val;
	while (l<r) lazy[l/SQ]+=val, l+=SQ;
	if (idl!=-1) Build(idl);
	if (idr!=-1) Build(idr);
}
ll Get(int l, int r){
	ll res=0;
	while (l<r){
		if (l%SQ==0 && l+SQ<=r){
			res=max(res, get(cht[l/SQ][0], L[l/SQ][0], R[l/SQ][0], lazy[l/SQ]));
			res=max(res, get(cht[l/SQ][1], L[l/SQ][1], R[l/SQ][1], lazy[l/SQ]));
			l+=SQ;
		}
		else{
			res=max(res, abs(1ll*(A[l]+lazy[l/SQ])*B[l]));
			l++;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=2; i<=n; i++) cin>>par[i], G[par[i]].pb(i);
	for (int i=1; i<=n; i++) cin>>AA[i], AA[i]+=AA[par[i]];
	for (int i=1; i<=n; i++) cin>>BB[i], BB[i]+=BB[par[i]];
	dfs(1);
	iota(P, P+n, 0);
	for (int i=0; i*SQ<n; i++){
		sort(P+i*SQ, P+min(n, i*SQ+SQ), [](int x, int y){
			return B[x]<B[y];	
		});
		Build(i);
	}
	while (m--){
		cin>>t>>v;
		if (t==2) cout<<Get(stt[v], fnt[v])<<"\n";
		else{
			cin>>x;
			Add(stt[v], fnt[v], x);
		}
	}
	
	return 0;
}
/*
5 1
1 1 2 2
10 -3 -7 -3 -10
10 3 9 3 6
2 2

*/