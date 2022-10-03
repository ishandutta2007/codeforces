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
const int MAXN=100010, SQ3=300, MOSQ=sqrt(1ll*MAXN*MAXN/SQ3), SQ2=700;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], AA[MAXN], B[MAXN], C[MAXN], L=1, R=1;
int Q[MAXN][4], ans[MAXN], P[MAXN];
int mark[MAXN], vec[MAXN*3], vec_sz, big[MAXN*3], big_sz, shit[MAXN];
pii X[MAXN];

inline void add(int x, int d){
	C[B[x]]--;
	B[x]+=d;
	C[B[x]]++;
	if (B[x]>SQ2) vec[vec_sz++]=x;
}
inline void Move(int l, int r){
	while (l<L) add(A[--L], +1);
	while (R<r) add(A[R++], +1);
//	debug("shit")
	while (L<l) add(A[L++], -1);
	while (r<R) add(A[--R], -1);
}
bool mo_cmp(int i, int j){
	int a=(Q[i][1]/MOSQ), b=(Q[j][1]/MOSQ);
	if (a!=b) return a<b;
	return (a&1)^(Q[i][2]<Q[j][2]);
}
int Solve(int ted, int k){
	sort(X, X+ted);
	
//	debug(ted)
//	for (int i=0; i<ted; i++) debugp(X[i])
	
	int res=inf, j=0, s=0;
	for (int i=0; i<ted; i++){
		s+=X[i].second;
		while (s-X[j].second>=k) s-=X[j++].second;
		if (s>=k) res=min(res, X[i].first-X[j].first);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], AA[i]=A[i];
	for (int i=0; i<m; i++){
		cin>>Q[i][0];
		if (Q[i][0]==1) cin>>Q[i][1]>>Q[i][2]>>Q[i][3], Q[i][2]++;
		else cin>>Q[i][1]>>Q[i][2];
	}
	memset(mark, -1, sizeof(mark));
	for (int ql=0; ql<m; ql+=SQ3){
		int qr=min(m, ql+SQ3), q=0;
		for (int i=ql; i<qr; i++) if (Q[i][0]==1) P[q++]=i;
		sort(P, P+q, mo_cmp);
		for (int _=0; _<q; _++){
			int id=P[_], l=Q[id][1], r=Q[id][2], k=Q[id][3];
//			debug(id)
			Move(l, r);
//			debug2(L, R)
			for (int i=ql; i<id; i++) if (Q[i][0]==2){
				int p=Q[i][1], x=Q[i][2];
				if (p<l || r<=p) continue ;
				add(AA[p], -1);
				AA[p]=x;
				add(AA[p], +1);
			}
			
			int ted=0;
			for (int i=0; i<big_sz; i++){
				int x=big[i];
				if (B[x]<=SQ2 || mark[x]==id) continue ;
				mark[x]=id;
				shit[ted]=x;
				X[ted++]={B[x], 1};
			}
			for (int i=0; i<vec_sz; i++){
				int x=vec[i];
				if (B[x]<=SQ2 || mark[x]==id) continue ;
				mark[x]=id;
				shit[ted]=x;
				X[ted++]={B[x], 1};
			}
			vec_sz=0;
			big_sz=0;
			for (int i=0; i<ted; i++) big[big_sz++]=shit[i];
			for (int i=1; i<=SQ2; i++) if (C[i]) X[ted++]={i, C[i]};
			
//			debug(B[1])
//			debug(B[2])
//			debug(B[3])
			ans[id]=Solve(ted, k);
			if (ans[id]==inf) ans[id]=-1;
			
			for (int i=id-1; i>=ql; i--) if (Q[i][0]==2){
				int p=Q[i][1];
				if (p<l || r<=p || AA[p]==A[p]) continue ;
				add(AA[p], -1);
				AA[p]=A[p];
				add(AA[p], +1);
			}
		}
		for (int i=ql; i<qr; i++) if (Q[i][0]==2){
			int p=Q[i][1], x=Q[i][2];
			if (L<=p && p<R) add(A[p], -1);
			AA[p]=A[p]=x;
			if (L<=p && p<R) add(A[p], +1);
		}
	}
	for (int i=0; i<m; i++) if (Q[i][0]==1) cout<<ans[i]<<"\n";
	
	return 0;
}
/*
12 11
2 1 1 2 1 1 3 2 1 1 3 3
1 2 10 3
1 2 11 3
2 7 2
1 3 9 2
1 1 12 1
1 1 12 4
2 12 4
1 1 12 4
2 1 5
1 3 12 2
1 1 4 3

12 7
2 1 1 2 1 1 3 2 1 1 3 3
2 7 2
1 1 12 4
2 12 4
1 1 12 4
2 1 5
1 3 12 2
1 1 4 3


12 4
2 1 1 2 1 1 3 2 1 1 3 3
2 7 2
1 1 12 4
2 12 4
2 1 5

12 2
2 1 1 2 1 1 3 2 1 1 3 3
2 7 2
1 1 12 4


*/