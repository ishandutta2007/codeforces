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
const int MAXN = 100010, LOG=18, SGM=26;

int n, m, k, u, v, x, y, t, a, b;
int Rank[MAXN][LOG], P[MAXN], pw;
int lcp[MAXN];
string S, ans;

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
	for (int i=LOG-1; i>=0 && x<=n && y<=n; i--) if (Rank[x][i]==Rank[y][i]/* && max(x, y)+(1<<i)<=n+1*/){
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
	cin>>S>>k;
	n=S.size();
	if (k>1ll*n*(n+1)/2) kill("No such line.")
	
	BuildShuffixArray();
	//cerr<<"P : ";for (int i=1; i<=n; i++) cerr<<P[i]<<" \n"[i==n];
	//debug(Lcp(2, 3))
	
	for (int i=1; i<n; i++) lcp[i]=Lcp(P[i], P[i+1]);
	for (int i=1; i<=n; i++) for (int j=lcp[i-1]+1; j<=n-P[i]+1; j++){
		int dwn=i, up=n+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (Lcp(P[i], P[mid])>=j) dwn=mid;
			else up=mid;
		}
		//cerr<<i<<' '<<j<<' '<<up<<endl;
		k-=up-i;
		//debug(k)
		if (k<=0) kill(S.substr(P[i]-1, j))
	}
	//debug("shit")
	//debug(k)
	
	
	return 0;
}