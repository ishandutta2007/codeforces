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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], mark[MAXN], fen[MAXN];
vector<int> vec[MAXN];

inline void add(int x){
	for (; x<MAXN; x+=x&-x) fen[x]++;
}
inline int get(int x){
	int res=0;
	for (; x; x-=x&-x) res+=fen[x];
	return res;
}

int Solve(){
	memset(mark, 0, sizeof(mark));
	memset(fen, 0, sizeof(fen));
	for (int i=0; i<MAXN; i++) vec[i].clear();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], vec[A[i]].pb(i);
	k=0;
	for (int i=1; i<MAXN; i++){
		int x=0, y=0;
		for (int j:vec[i]){
			k++;
			if (k&1) x++;
			if (j&1) y++;
		}
		if (x!=y) kill("NO")
	}
	kill("YES")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}