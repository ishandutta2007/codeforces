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
const int MAXN = 100010, SQ=2000;

struct Query{
	int id, l, r;
} B[MAXN];

int n, m, k, u, v, x, y, t, l, r;
int A[MAXN], C[MAXN*2], cnt[MAXN];
int ans[MAXN];
vector<Query> query;
vector<int> comp;
vector<pii> todo;

bool cmp(Query a, Query b){
	if (a.id/SQ!=b.id/SQ) return a.id<b.id;
	if (a.l/SQ!=b.l/SQ) return a.l<b.l;
	return (a.r<b.r) ^ ((a.l/SQ)&1);
}

void add(int x){
	cnt[C[x]]--;
	cnt[++C[x]]++;
}

void rem(int x){
	cnt[C[x]]--;
	cnt[--C[x]]++;
}

void change(int x, int y, bool f=0){
	rem(A[x]);
	if (f) todo.pb({x, A[x]});
	A[x]=y;
	add(A[x]);
}

void reset(){
	while (todo.size()){
		change(todo.back().first, todo.back().second);
		todo.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], comp.pb(A[i]);
	for (int i=0; i<m; i++){
		cin>>t>>l>>r;
		if (t==2) comp.pb(r);
		else query.pb({i, l, r+1});
		B[i]={t, l, r};
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=n; i++) A[i]=lower_bound(all(comp), A[i])-comp.begin();
	for (int i=0; i<m; i++) if (B[i].id==2) B[i].r=lower_bound(all(comp), B[i].r)-comp.begin();
		
	sort(all(query), cmp);
	int L=1, R=1, Z=0;
	for (Query Q:query){
		int id=Q.id, l=Q.l, r=Q.r;
		while (Z!=id/SQ){
			L=R=1;
			memset(C, 0, sizeof(C));
			memset(cnt, 0, sizeof(cnt));
			for (int i=Z*SQ; i<Z*SQ+SQ; i++) if (B[i].id==2) A[B[i].l]=B[i].r;
			Z++;
		}
		while (l<L) add(A[--L]);
		while (R<r) add(A[R++]);
		while (L<l) rem(A[L++]);
		while (r<R) rem(A[--R]);
		
		for (int i=id/SQ*SQ; i<id; i++) if (B[i].id==2) if (L<=B[i].l && B[i].l<R) change(B[i].l, B[i].r, 1);
		for (ans[id]=1; cnt[ans[id]]; ans[id]++);
		reset();
	}
	for (int i=0; i<m; i++) if (B[i].id==1) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
10 4
1 2 3 1 1 2 2 2 9 9
1 1 1
1 2 8
2 7 1
1 2 8

*/