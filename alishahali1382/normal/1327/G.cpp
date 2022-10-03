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
#define SZ(x) ((int) x.size())

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, SGM=14;

ll n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN][SGM], F[MAXN], ts;
ll cost[MAXN];
int nxt[MAXN];
ll dp[2][1<<SGM][1002];
ll sum[SGM+1][1002];
int shit[SGM+1][1002];
vector<int> vec;
string S;

int AddTrie(string &s){
	int v=0;
	for (char ch:s){
		if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
		v=C[v][ch-'a'];
	}
	return v;
}

void BuildAho(){
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		cost[v]+=cost[F[v]];
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k;
	while (k--){
		cin>>S>>x;
		cost[AddTrie(S)]+=x;
	}
	BuildAho();
	cin>>S;
	n=S.size();
	S="."+S;
	vec.pb(0);
	for (int i=1; i<=n; i++) if (S[i]=='?') vec.pb(i);
	
	int bad=SZ(vec);
	vec.pb(n+1);
	for (int i=0; i<bad; i++){
		for (int j=0; j<=ts; j++){
			int v=j;
			for (int k=vec[i]+1; k<vec[i+1]; k++){
				v=C[v][S[k]-'a'];
				sum[i][j]+=cost[v];
			}
			shit[i][j]=v;
		}
	}
	
	for (int i=bad-1; i; i--){
		memset(dp[0], -31, sizeof(dp[0]));
		//debug2(i, bad-i)
		for (int mask=0; mask<(1<<SGM); mask++){
			for (int c=0; c<SGM; c++) if (mask&(1<<c)){
				if (__builtin_popcount(mask)!=bad-i) continue ;
				for (int j=0; j<=ts; j++){
					int v=shit[i][C[j][c]];
					ll tmp=cost[C[j][c]] + sum[i][C[j][c]];
					dp[0][mask][j]=max(dp[0][mask][j], dp[1][mask^(1<<c)][v] + tmp);
				}
			}
		}
		memcpy(dp[1], dp[0], sizeof(dp[1]));
	}
	
	ans=-INF;
	for (int mask=0; mask<(1<<SGM); mask++)
		if (__builtin_popcount(mask)==bad-1)
			ans=max(ans, dp[1][mask][shit[0][0]] + sum[0][0]);
	cout<<ans<<'\n';
	
	return 0;
}