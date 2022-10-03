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
const int MAXN = 300010, LOG=19;

int n, m, k, u, v, x, y, t, a, b;
int Rank[MAXN][LOG], P[MAXN], pw;
int lcp[MAXN], L[MAXN], R[MAXN];
ll cnt[MAXN][4];
ll ans[MAXN];
string s1, s2, s3, S;

bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>=n) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildShuffixArray(){
	for (int i=1; i<=n; i++) Rank[i][0]=S[i], P[i]=i;
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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s1>>s2>>s3;
	S="."+s1+"@"+s2+"$"+s3;
	n=S.size();
	BuildShuffixArray();
	//debug(Lcp(9, 5))
	//debug2(S, n)
	for (int i=1; i<=n; i++){
		if (P[i]==s1.size()+1 || P[i]==s1.size()+s2.size()+2) continue ;
		int tmp=3;
		if (P[i]<=s1.size()+s2.size()+1) tmp=2;
		if (P[i]<=s1.size()) tmp=1;
		for (int j=1; j<=3; j++) cnt[i][j]=cnt[i-1][j];
		cnt[i][tmp]++;
	}
	for (int i=1; i<n; i++) lcp[i]=Lcp(P[i], P[i+1]);
	for (int i=1; i<n; i++) for (L[i]=i-1; L[i] && lcp[i]<=lcp[L[i]]; L[i]=L[L[i]]);
	for (int i=n-1; i; i--) for (R[i]=i+1; R[i]<n && lcp[i]<lcp[R[i]]; R[i]=R[R[i]]);
	for (int i=1; i<n; i++){
		ll tmp=(cnt[R[i]][1]-cnt[L[i]][1])*(cnt[R[i]][2]-cnt[L[i]][2])*(cnt[R[i]][3]-cnt[L[i]][3]);
		tmp-=(cnt[R[i]][1]-cnt[i][1])*(cnt[R[i]][2]-cnt[i][2])*(cnt[R[i]][3]-cnt[i][3]);
		tmp-=(cnt[i][1]-cnt[L[i]][1])*(cnt[i][2]-cnt[L[i]][2])*(cnt[i][3]-cnt[L[i]][3]);
		assert(tmp>=0);
		ans[lcp[i]]+=tmp%mod;
		//debug2(P[i], lcp[i])
	}
	
	
	for (int i=MAXN-1; i; i--) ans[i-1]=(ans[i-1]+ans[i])%mod;
	for (int i=1; i<=min(s1.size(), min(s2.size(), s3.size())); i++) cout<<ans[i]<<' ';cout<<'\n';
	
	return 0;
}