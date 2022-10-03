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
const int N=1010, K=300010;

int n, m, k, u, v, x, y, t, a, b;
char A[N][N], E[K];
int X[K], Y[K], XX[K], YY[K];
ll cnt2[N][N];
ll S[K];
ll cnt[26][N][N], ans=INF, sbad;
ll bad[26][N][N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>A[i][j];
		for (int c=0; c<26; c++)
			bad[c][i][j]=bad[c][i-1][j] + bad[c][i][j-1] - bad[c][i-1][j-1] + abs(A[i][j]-'a'-c);
	}
	for (int i=1; i<=k; i++){
		cin>>X[i]>>Y[i]>>XX[i]>>YY[i]>>E[i];
		cnt[E[i]-'a'][X[i]][Y[i]]++;
		cnt[E[i]-'a'][XX[i]+1][Y[i]]--;
		cnt[E[i]-'a'][X[i]][YY[i]+1]--;
		cnt[E[i]-'a'][XX[i]+1][YY[i]+1]++;
		cnt2[X[i]][Y[i]]++;
		cnt2[XX[i]+1][Y[i]]--;
		cnt2[X[i]][YY[i]+1]--;
		cnt2[XX[i]+1][YY[i]+1]++;
		sbad+=bad[E[i]-'a'][XX[i]][YY[i]];
		sbad-=bad[E[i]-'a'][X[i]-1][YY[i]];
		sbad-=bad[E[i]-'a'][XX[i]][Y[i]-1];
		sbad+=bad[E[i]-'a'][X[i]-1][Y[i]-1];
	}
	// 1 2
	for (int i=1; i<=k; i++){
		int x=X[i], y=Y[i], xx=XX[i], yy=YY[i], c=E[i]-'a';
		ll badi=(bad[c][xx][yy]-bad[c][xx][y-1]-bad[c][x-1][yy]+bad[c][x-1][y-1]);
		S[i]=sbad + k*badi;
	}
	// ---
	
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
		cnt2[i][j]+=cnt2[i-1][j] + cnt2[i][j-1] - cnt2[i-1][j-1];
	for (int c=0; c<26; c++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
		cnt[c][i][j]+=cnt[c][i-1][j] + cnt[c][i][j-1] - cnt[c][i-1][j-1];
		
	for (int c=0; c<26; c++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		bad[c][i][j]=cnt2[i][j]*abs(A[i][j]-'a'-c);
		bad[c][i][j]+=bad[c][i-1][j] + bad[c][i][j-1] - bad[c][i-1][j-1];
	}
	
	// 4
	for (int i=1; i<=k; i++){
		int x=X[i], y=Y[i], xx=XX[i], yy=YY[i], c=E[i]-'a';
		S[i]-=(bad[c][xx][yy]-bad[c][xx][y-1]-bad[c][x-1][yy]+bad[c][x-1][y-1]);
	}
	// ---
	
	for (int c=0; c<26; c++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		bad[c][i][j]=cnt[c][i][j]*abs(A[i][j]-'a'-c);
		bad[c][i][j]+=bad[c][i-1][j] + bad[c][i][j-1] - bad[c][i-1][j-1];
	}
	
	// 5
	for (int i=1; i<=k; i++){
		int x=X[i], y=Y[i], xx=XX[i], yy=YY[i], c=E[i]-'a';
		for (int cc=0; cc<26; cc++){
			S[i]-=(bad[cc][xx][yy]-bad[cc][xx][y-1]-bad[cc][x-1][yy]+bad[cc][x-1][y-1]);
		}
	}
	// ---
//	debug(S[1])
	
	
	for (int c=0; c<26; c++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cnt[c][i][j]+=cnt[c][i-1][j] + cnt[c][i][j-1] - cnt[c][i-1][j-1];
	}
	// 3
	for (int i=1; i<=k; i++){
		int x=X[i], y=Y[i], xx=XX[i], yy=YY[i], c=E[i]-'a';
		for (int cc=0; cc<26; cc++){
			ll sz=(cnt[cc][xx][yy]-cnt[cc][xx][y-1]-cnt[cc][x-1][yy]+cnt[cc][x-1][y-1]);
			S[i]+=abs(c-cc)*sz;
		}
	}
	// ---
//	debug(S[1])
	for (int i=1; i<=k; i++) ans=min(ans, S[i]);
	cout<<ans<<'\n';
//	debug(S[2])
//	debug(sbad)
	
	return 0;
}