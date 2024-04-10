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

int n, m, k, u, v, x, y, t, a, b;
int Rank[MAXN][LOG], P[MAXN], pw;
int par[MAXN], sz[MAXN], mx;
bool bad[MAXN];
int A[MAXN], lcp[MAXN], N;
vector<int> vec[MAXN];
string S;

bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>n) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildShuffixArray(){
	for (int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+n+1, cmp);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
	}
}

int Lcp(int x, int y){
	int res=0;
	for (int i=LOG-1; i>=0 && x<=n && y<=n; i--) if (Rank[x][i]==Rank[y][i]){
		x+=(1<<i);
		y+=(1<<i);
		res|=(1<<i);
	}
	return res;
}

int Get(int x){
	if (par[x]==x) return x;
	return par[x]=Get(par[x]);
}

void Join(int x, int y){
	x=Get(x);
	y=Get(y);
	sz[x]+=sz[y];
	mx=max(mx, sz[x]);
	par[y]=x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) par[i]=i, sz[i]=1;
	ll ans=0;//n*(!bad[1]);
	cin>>n>>S;
	for (int i=n; i; i--){
		char ch;
		cin>>ch;
		bad[i]=ch-'0';
		if (!bad[i]) ans=max(ans, n-i+1ll);
	}
	reverse(all(S));
	BuildShuffixArray();
	
	//cerr<<"Shuffix : ";for (int i=1; i<=n; i++) cerr<<P[i]<<" \n"[i==n];
	
	for (int i=1; i<=n; i++) if (!bad[P[i]]) A[++N]=P[i];
	
	//cerr<<"Shuffix : ";for (int i=1; i<=N; i++) cerr<<A[i]<<" \n"[i==N];
	//debug(N)
	
	for (int i=1; i<N; i++) lcp[i]=Lcp(A[i], A[i+1]);
	for (int i=1; i<N; i++) vec[lcp[i]].pb(i);
	mx=0;
	for (int i=n-1; i; i--){
		for (int j:vec[i]) Join(j, j+1);
		//debug2(i, mx)
		ans=max(ans, 1ll*mx*i);
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*

6
ababaa
101011

4
abaa
1011


*/