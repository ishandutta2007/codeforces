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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, D=51, TS=MAXN*D/2, SGM=10;

int n, m, k, u, v, x, y, t, a, b;
int C[TS][SGM], F[TS], ts;
bool bad[TS];
ll dp[MAXN][TS], ans;
ll tav[D];
string S, X;

void AddTrie(int l, int r){
	int v=0;
	while (l<r){
		if (!C[v][S[l]-'0']) C[v][S[l]-'0']=++ts;
		v=C[v][S[l++]-'0'];
	}
	bad[v]=1;
}

void BuildAho(){
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		bad[v]|=bad[F[v]];
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}
	}
}

ll Solve(bool flag){
	ll res=0;
	for (int i=0; i<m; i++) res+=tav[m-i-1]*(X[i]-'0');
	
	int v=0;
	for (int i=0; i<m; i++){
		for (int j=(i==0); j<X[i]-'0'; j++) res-=dp[m-i-1][C[v][j]];
		v=C[v][X[i]-'0'];
		if (bad[v]){
			res+=flag;
			break ;
		}
	}
	
	return res%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<D; i++) tav[i]=tav[i-1]*10%mod;
	cin>>S>>X;
	n=S.size();
	m=X.size();
	for (int i=0; i+m/2<=n; i++) AddTrie(i, i+m/2);
	if (!ts) kill(0)
	BuildAho();
	
	for (int i=0; i<ts; i++) if (!bad[i]) dp[0][i]=1;
	for (int i=1; i<=m; i++){
		for (int j=0; j<ts; j++) if (!bad[j]){
			for (int ch=0; ch<SGM; ch++) dp[i][j]+=dp[i-1][C[j][ch]];
			dp[i][j]%=mod;
		}
	}
	
	ans=-Solve(0);
	cin>>X;
	ans+=Solve(1);
	ans%=mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}