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
const int N=1002;
typedef array<int, N> Num;

int n, m, k, u, v, x, y, t, lena, ans;
Num A, B[N];
int P[N][N], cost[60];
int dp[N+1][N];
string S;

inline void input(Num &x){
	cin>>S;
	reverse(all(S));
	for (int i=0; i<S.size(); i++) x[i]=S[i]-'0';
	for (int i=S.size(); i<N; i++) x[i]=-(i>=lena);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S;
	lena=S.size();
	reverse(all(S));
	while (S.size()<N) S+='0';
	for (int i=0; i<N; i++) A[i]=(S[i]=='?'?-1:S[i]-'0');
	cin>>n;
	for (int i=0; i<n; i++) input(B[i]), P[0][i]=i;
	for (int i=0; i<10; i++) cin>>cost[i], cost[i+10]=cost[i];
	for (int i=1; i<10; i++) cost[20+i]=cost[i];
	
	for (int i=1; i<N; i++){
		vector<int> vec[10];
		for (int j=0; j<n; j++) vec[max(0, B[P[i-1][j]][i-1])].pb(P[i-1][j]);
		int cnt=0;
		for (int d=9; ~d; d--) for (int id:vec[d]) P[i][cnt++]=id;
	}
	
	for (int i=N-1; ~i; i--){
		int cnt[60];
		memset(cnt, 0, sizeof(cnt));
		for (int j=0; j<n; j++) if (B[j][i]!=-1) cnt[B[j][i]]++;
		for (int j=0; j<=n; j++){
			for (int a=0; a<10; a++) if (A[i]==-1 || A[i]==a){
				if (a==0 && i==lena-1) continue ;  // leading zero in A
				int tmp=0, carry=0;
				for (int b=0; b<=10; b++){
					carry+=(a+b>=10)*cnt[b];
					tmp+=cost[a+b]*cnt[b];
				}
				
				dp[i][j]=max(dp[i][j], tmp+dp[i+1][carry]);
			}
			if (j==n) continue ;
			int id=P[i][j];
			if (B[id][i]!=-1){
				cnt[B[id][i]]--;
				cnt[B[id][i]+1]++;
			}
			else cnt[1]++;
		}
	}
	cout<<dp[0][0]<<'\n';
	
	return 0;
}