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
const int MAXN = 194610, MAXA=5032110, P=10;

int n, m, k, u, v, x, y, t, l, r;
int A[MAXN];
int sieve[MAXA], f[MAXA], cnt[MAXA];
int ans[1049660];
int fen[MAXN];
int last[MAXA][P];
vector<int> D[MAXA];
vector<pii> Q[MAXN];

void upd(int pos, int x){
	if (pos<=0) return ;
	//debug2(pos, x)
	for (pos=MAXN-pos; pos<MAXN; pos+=pos&-pos) fen[pos]=min(fen[pos], x);
}

int get(int pos){
	int res=inf;
	for (pos=MAXN-pos; pos; pos-=pos&-pos) res=min(res, fen[pos]);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sieve[1]=1;
	for (ll i=2; i<MAXA; i++) if (!sieve[i]){
		sieve[i]=i;
		for (ll j=i*i; j<MAXA; j+=i) sieve[j]=i;
	}
	for (int i=1; i<MAXA; i++) f[i]=i;
	for (int p=1; p*p<MAXA; p++) for (int i=1; i*p*p<MAXA; i++) f[i*p*p]=f[i];
	for (int i=2; i<MAXA; i++) cnt[i]=cnt[i/sieve[i]]+1;
	for (int i=1; i<MAXA; i++) for (int j=i; j<MAXA; j+=i) if (f[j]==j) D[j].pb(i);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]=f[A[i]];
	for (int i=1; i<=m; i++){
		cin>>l>>r;
		Q[r].pb({l, i});
	}

	memset(fen, 63, sizeof(fen));
	for (int r=1; r<=n; r++){
		for (int d:D[A[r]]) for (int i=0; i<P; i++) upd(last[d][i], cnt[A[r]]+i-2*cnt[d]);
		for (int d:D[A[r]]) last[d][cnt[A[r]]]=r;
		for (pii p:Q[r]) ans[p.second]=get(p.first);
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}