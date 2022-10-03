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
const int mod=998244353;
const int MAXN=500010, LOG=20;

struct Fenwick{
	int fen[MAXN];
	void add(int pos, int x){
		for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
	}
	int get(int pos){
		int res=0;
		for (; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
	int is_on(int pos){ return get(pos)-get(pos-1);}
	int Find(int val){
		int pos=0;
		for (int i=LOG-1; ~i; i--) if (pos+(1<<i)<MAXN && fen[pos+(1<<i)]<val)
			val-=fen[pos+=(1<<i)];
		return pos+1;
	}
} fen;

int n, m, k, u, v, x, y, t, a, b;
int X[MAXN], Y[MAXN];
ll F[MAXN], I[MAXN], ans;

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}
int Main(){
	cin>>n>>m;
	for (int i=1; i<=m; i++) cin>>X[i]>>Y[i];
	k=n;
	set<int> st;
	vector<int> undo;
	for (int i=m; i; i--){
		int pos=fen.Find(Y[i]);
		fen.add(pos, -1);
		undo.pb(pos);
		if (fen.is_on(pos+1)) st.insert(pos), k--;
	}
	for (int x:undo) fen.add(x, +1); // undo_ed!
	
//	debug2(n, k)
	ans=nCr(n+k-1, n);
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
//	debug(nCr(5, 2))
	for (int i=1; i<MAXN; i++) fen.add(i, +1);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}