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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int Rank[MAXN][LOG], P[MAXN], pw;
int S[MAXN], A[MAXN], R[MAXN], lcp[MAXN];
vector<int> vec[MAXN*2];
char ch;

bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>n) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildShuffixArray(){
	for (int i=1; i<=n; i++) Rank[i][0]=S[i], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+n+1, cmp);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw]+cmp(P[i-1], P[i]);
	}
}

int Lcp(int x, int y){
	if (x>y) swap(x, y);
	int res=0;
	for (int i=LOG-1; i>=0; i--) if (Rank[x][i]==Rank[y][i] && y+(1<<i)<=n+1){
		res|=(1<<i);
		x+=(1<<i);
		y+=(1<<i);
	}
	return res;
}

int Count(int x, int l, int r){
	return lower_bound(all(vec[x+MAXN]), r)-lower_bound(all(vec[x+MAXN]), l);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>ch;
		S[i]=(ch=='('?+1:-1);
		A[i]=A[i-1]+S[i];
		vec[A[i]+MAXN].pb(i);
	}
	for (int i=n; i>=0; i--) for (R[i]=i+1; R[i]<=n && A[R[i]]>=A[i]; R[i]=R[R[i]]);
	BuildShuffixArray();
	for (int i=2; i<=n; i++) lcp[i]=Lcp(P[i-1], P[i]);
	ll ans=0;
	for (int i=1; i<=n; i++) if (S[P[i]]==+1){
		int l=P[i]+lcp[i];
		int r=R[P[i]-1];
		//cerr<<P[i]<<' '<<l<<' '<<r<<endl;
		if (l>r) continue ;
		ans+=Count(A[P[i]]-1, l, r);
	}
	cout<<ans<<'\n';
	
	return 0;
}