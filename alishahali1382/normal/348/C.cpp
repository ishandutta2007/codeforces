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
const int MAXN = 100010, SQ=320;

int n, m, q, k, u, v, x, y, t, a, b;
ll A[MAXN];
int B[SQ][MAXN];
int id[MAXN], ts;
ll ans[MAXN], lazy[MAXN];
bool big[MAXN], mark[MAXN];
vector<int> S[MAXN], vec;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++){
		cin>>k;
		S[i].resize(k);
		for (int j=0; j<k; j++) cin>>S[i][j];
		big[i]=(k>SQ);
		if (!big[i]) continue ;
		vec.pb(i);
		id[i]=++ts;
		for (int j:S[i]) ans[i]+=A[j];
	}
	for (int i:vec){
		for (int j:S[i]) mark[j]=1;
		for (int j=1; j<=m; j++) for (int k:S[j]) B[id[i]][j]+=mark[k];
		for (int j:S[i]) mark[j]=0;
	}
	while (q--){
		char ch;
		cin>>ch>>k;
		if (ch=='?'){
			if (big[k]) cout<<ans[k]<<'\n';
			else{
				ll res=0;
				for (int j:S[k]) res+=A[j];
				for (int j:vec) res+=lazy[j]*B[id[j]][k];
				cout<<res<<'\n';
			}
			continue ;
		}
		cin>>x;
		if (big[k]) lazy[k]+=x;
		else{for (int j:S[k]) A[j]+=x;}
		for (int j:vec) ans[j]+=1ll*B[id[j]][k]*x;
	}
	
	return 0;
}