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
#define upd(x, y) x=max(x, y)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int N = 17;

int n, m, k, u, v, x, y, t, a, b, ans;
int good[1<<N];
int dp[2<<N][2][2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -31, sizeof(dp));
	cin>>n>>m;
	while (m--) cin>>x, good[x-1]=1;
	for (int i=(1<<(n-1)); i<(1<<n); i++){
		int tmp=good[2*i-(1<<n)]+good[2*i+1-(1<<n)];
		if (tmp==0) dp[i][0][0]=0;
		if (tmp==1) dp[i][0][1]=dp[i][1][0]=1;
		if (tmp==2) dp[i][1][1]=1;
	}
	for (int i=(1<<(n-1))-1; i; i--){
		int L=2*i, R=2*i+1;
		for (int lu=0; lu<2; lu++)
			for (int ld=0; ld<2; ld++)
				for (int ru=0; ru<2; ru++)
					for (int rd=0; rd<2; rd++){
						if (lu+ru==0){
							if (ld+rd==0) upd(dp[i][0][0], dp[L][lu][ld]+dp[R][ru][rd] + 0);
							else upd(dp[i][0][1], dp[L][lu][ld]+dp[R][ru][rd] + 2);
						}
						if (lu+ru==1){
							// 1 win
							if (ld+rd==0) upd(dp[i][1][0], dp[L][lu][ld]+dp[R][ru][rd] + 1);
							else upd(dp[i][1][1], dp[L][lu][ld]+dp[R][ru][rd] + 3);
							
							// 0 win
							if (ld+rd==0) upd(dp[i][0][1], dp[L][lu][ld]+dp[R][ru][rd] + 2);
							else upd(dp[i][0][1], dp[L][lu][ld]+dp[R][ru][rd] + 3);
						}
						if (lu+ru==2){
							if (ld+rd==0) upd(dp[i][1][1], dp[L][lu][ld]+dp[R][ru][rd] + 2);
							else upd(dp[i][1][1], dp[L][lu][ld]+dp[R][ru][rd] + 3);
						}
					}
	}
	
	for (int i=0; i<2; i++) for (int j=0; j<2; j++) ans=max(ans, dp[1][i][j] + (i+j>0));
	cout<<ans<<'\n';
	
	return 0;
}
/*
2 1
0

*/