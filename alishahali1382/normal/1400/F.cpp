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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1010, SGM=10, TS=30000;

int n, X, u, v, x, y, t, a, b, ans;
int C[TS][SGM], F[TS], BAD[TS], ts;
int dp[2][TS];
string S;

void AddTrie(vector<int> s){
//	debugv(s)
	int v=0;
	for (int x:s){
		if (!C[v][x]) C[v][x]=++ts;
		v=C[v][x];
	}
	BAD[v]=1;
}
void BuildAho(){
	queue<int> Q;
	for (int i=1; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		BAD[v]|=BAD[F[v]];
		for (int i=1; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				Q.push(C[v][i]);
				F[C[v][i]]=C[F[v]][i];
			}
		}
	}
}
inline void upd(int &x, int y){ x=min(x, y);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>X;
	n=S.size();
	for (int mask=0; mask<(1<<(X-1)); mask++){
		vector<int> vec;
		int last=-1;
		bool bad=0;
		for (int i=0; i<X-1; i++) if (mask&(1<<i)){
			vec.pb(i-last);
			last=i;
		}
		vec.pb(X-1-last);
		for (int x:vec) if (x>=10) bad=1;
		if (bad) continue ;
		for (int i=1; i<vec.size(); i++){
			vec[i]+=vec[i-1];
			if (X%vec[i-1]==0) bad=1;
			for (int j=0; j<i; j++) if (X%(vec[i]-vec[j])==0) bad=1;
		}
		if (bad) continue ;
		for (int i=vec.size()-1; i; i--) vec[i]-=vec[i-1];
		AddTrie(vec);
	}
	BuildAho();
	memset(dp, 31, sizeof(dp));
	dp[0][0]=0;
	for (int i=0; i<n; i++){
		int x=(i&1), y=S[i]-'0';
		for (int j=0; j<=ts; j++) if (!BAD[j]){
			upd(dp[x^1][j], dp[x][j]+1);
			upd(dp[x^1][C[j][y]], dp[x][j]);
			dp[x][j]=inf;
		}
	}
	ans=n;
	for (int i=0; i<=ts; i++) if (!BAD[i]) ans=min(ans, dp[n&1][i]);
	cout<<ans<<"\n";
	
	return 0;
}