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
#define upd(x, y) x=min(x, y)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int N=80;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], cnt[N][3];
int dp[N][N][N][3];
vector<int> vec[3];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		char ch;
		cin>>ch;
		if (ch=='V') A[i]=1;
		if (ch=='K') A[i]=2;
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][2]=cnt[i-1][2];
		cnt[i][A[i]]++;
		vec[A[i]].pb(i);
	}
	memset(dp, 31, sizeof(dp));
	for (int i:{0, 1, 2}) dp[0][0][0][i]=0;
	for (int a=0; a<=cnt[n][0]; a++){
		for (int b=0; b<=cnt[n][1]; b++){
			for (int c=0; c<=cnt[n][2]; c++){
				if (a){
					int pos=vec[0][a-1], cost=max(cnt[pos][1]-b, 0)+max(cnt[pos][2]-c, 0);
					upd(dp[a][b][c][0], dp[a-1][b][c][0]+cost);
					upd(dp[a][b][c][0], dp[a-1][b][c][1]+cost);
					upd(dp[a][b][c][0], dp[a-1][b][c][2]+cost);
				}
				if (b){
					int pos=vec[1][b-1], cost=max(cnt[pos][0]-a, 0)+max(cnt[pos][2]-c, 0);
					upd(dp[a][b][c][1], dp[a][b-1][c][0]+cost);
					upd(dp[a][b][c][1], dp[a][b-1][c][1]+cost);
					upd(dp[a][b][c][1], dp[a][b-1][c][2]+cost);
				}
				if (c){
					int pos=vec[2][c-1], cost=max(cnt[pos][0]-a, 0)+max(cnt[pos][1]-b, 0);
					upd(dp[a][b][c][2], dp[a][b][c-1][0]+cost);
					//upd(dp[a][b][c][2], dp[a][b][c-1][1]+cost); // VK
					upd(dp[a][b][c][2], dp[a][b][c-1][2]+cost);
				}
			}
		}
	}
	ans=inf;
	for (int i:{0, 1, 2}) upd(ans, dp[cnt[n][0]][cnt[n][1]][cnt[n][2]][i]);
	cout<<ans<<'\n';
	
	return 0;
}
/*
2
VK

*/