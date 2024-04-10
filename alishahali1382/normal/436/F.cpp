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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100200, SQ=320, NSQ=MAXN/SQ+1;

int n, m, w, u, v, x, y, t, a, b, maxb;
int A[MAXN], B[MAXN], ans[MAXN], lazy[NSQ];
pll X[MAXN];
vector<int> vec[MAXN];

struct CHT{
	pair<ll, int> cht[SQ];
	int L, R;
	inline ll Inter(pll x, pll y){
		if (x.first==y.first) return (x<=y?-INF:INF);
		return (x.second-y.second)/(y.first-x.first) +  ((x.second-y.second)%(y.first-x.first)>0);
	}
	inline void Add(int a){
		while (R && Inter(X[cht[R-1].second], X[a])<=cht[R-1].first) R--;
		if (!R) cht[R++]={-INF, a};
		else cht[R]={Inter(X[cht[R-1].second], X[a]), a}, R++;
	}
	inline pll Get(ll x){
		while (L+1<R && cht[L+1].first<=x) L++;
		int i=cht[L].second;
		return {X[i].first*x + X[i].second, i};
	}
} cht[NSQ];

void Build(int id){
	int tl=id*SQ, tr=min(MAXN, tl+SQ);
	cht[id].L=cht[id].R=0;
	for (int i=tl; i<tr; i++){
		X[i].second+=lazy[id]*X[i].first;
		cht[id].Add(i);
	}
	lazy[id]=0;
}

void Add(int l, int r, int val){
	int idl=-1, idr=-1;
	while (l<r && l%SQ) idl=l/SQ, X[l].second+=val*l, l++;
	while (l<r && r%SQ) idr=r/SQ, r--, X[r].second+=val*r;
	while (l<r) lazy[l/SQ]+=val, l+=SQ;
	if (idl!=-1) Build(idl);
	if (idr!=-1) Build(idr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>w;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>B[i];
		vec[B[i]].pb(i);
		maxb=max(maxb, B[i]);
	}
	for (int i=0; i<MAXN; i++) X[i].first=i;
	for (int i=0; i*SQ<MAXN; i++) Build(i);
	int ted=n;
	for (int i=0; i<=maxb+1; i++){
		pll p={-inf, -1};
		for (int j=0; j*SQ+SQ<=MAXN; j++) p=max(p, cht[j].Get(lazy[j]));
		cout<<p.first + 1ll*ted*i*w<<" "<<p.second<<"\n";
		for (int j:vec[i]) Add(0, A[j]+1, +1), ted--;
	}
	
	
	return 0;
}