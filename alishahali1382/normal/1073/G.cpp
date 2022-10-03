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
const int MAXN = 200010, LOG=19;

int n, m, k, q, x, y, t, a, b, ans;
int Rank[MAXN][LOG], P[MAXN], pw;
int L[MAXN*2], R[MAXN*2], lcp[MAXN*2];
int A[MAXN*2], B[MAXN];
string S;

bool cmp1(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>n) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildShuffixArray(){
	for (int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+n+1, cmp1);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp1(P[i-1], P[i]);
	}
}

int Lcp(int x, int y){
	if (x==y) return n-x+1;
	int res=0;
	for (int i=LOG-1; i>=0 && x<=n && y<=n; i--) if (Rank[x][i]==Rank[y][i]){
		x+=(1<<i);
		y+=(1<<i);
		res|=(1<<i);
	}
	return res;
}

bool cmp2(int x, int y){
	return Rank[x][LOG-1]<Rank[y][LOG-1];
}

ll calc(int A[], int m){
	ll res=0;
	sort(A+1, A+m+1, cmp2);
	for (int i=1; i<m; i++) lcp[i]=Lcp(A[i], A[i+1]);
	for (int i=1; i<m; i++) for (L[i]=i-1; L[i] && lcp[i]<=lcp[L[i]]; L[i]=L[L[i]]);
	for (int i=m-1; i; i--) for (R[i]=i+1; R[i]<m && lcp[i]<lcp[R[i]]; R[i]=R[R[i]]);
	for (int i=1; i<m; i++) res+=1ll*lcp[i]*(i-L[i])*(R[i]-i);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>q>>S;
	BuildShuffixArray();
	while (q--){
		cin>>m>>k;
		for (int i=1; i<=m; i++) cin>>A[i];
		for (int i=1; i<=k; i++) cin>>B[i], A[m+i]=B[i];
		ll ans=calc(A, m) + calc(B, k);
		m+=k;
		ans=calc(A, m)-ans;
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
7 1
abacaba
2 2
1 2
1 2

*/