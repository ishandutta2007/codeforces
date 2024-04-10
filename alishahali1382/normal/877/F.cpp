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
const int MAXN=100010, SQ=320;

int n, m, k, u, v, x, y, t, a, b;
ll A[MAXN], ans[MAXN], curr;
int L[MAXN], R[MAXN], P[MAXN];
int prv[3*MAXN], nex[3*MAXN], cnt[3*MAXN];
vector<ll> comp;

bool MO(int i, int j){
	int a=L[i]/SQ, b=L[j]/SQ;
	if (a!=b) return a<b;
	return (R[i]<R[j]);
}
inline void addl(int i){
	curr+=cnt[nex[i]];
	cnt[A[i]]++;
}
inline void reml(int i){
	cnt[A[i]]--;
	curr-=cnt[nex[i]];
}
inline void addr(int i){
	curr+=cnt[prv[i]];
	cnt[A[i]]++;
}
inline void remr(int i){
	cnt[A[i]]--;
	curr-=cnt[prv[i]];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	comp={0, k, -k};
	for (int i=1; i<=n; i++){
		cin>>x;
		if (A[i]==1) A[i]=x;
		else A[i]=-x;
		A[i]+=A[i-1];
		comp.pb(A[i]);
		comp.pb(A[i]-k);
		comp.pb(A[i]+k);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=0; i<=n; i++){
		A[i]=lower_bound(all(comp), A[i])-comp.begin();
		prv[i]=lower_bound(all(comp), comp[A[i]]-k)-comp.begin();
		nex[i]=lower_bound(all(comp), comp[A[i]]+k)-comp.begin();
	}
	
	cin>>m;
	for (int i=1; i<=m; i++) cin>>L[i]>>R[i], R[i]++, L[i]--, P[i]=i;
	sort(P+1, P+m+1, MO);
	int mol=0, mor=0;
	for (int i=1; i<=m; i++){
		int id=P[i];
		while (mor<R[id]) addr(mor++);
		while (L[id]<mol) addl(--mol);
		while (R[id]<mor) remr(--mor);
		while (mol<L[id]) reml(mol++);
		ans[id]=curr;
	}
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<"\n";
	
	return 0;
}
/*
4 1
1 1 1 2
1 1 1 1
1
3 4

*/