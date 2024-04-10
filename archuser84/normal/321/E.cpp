///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 4010;
const int inf = 1e9+10;
int sum0[N][N];
int sum[N][N];
int dp[N][N];
int a[N][N];
int n, k;

void up(int i, int l=0, int r=n+1, int b=0, int e=n+1)
{
	if(l>=r) return;
	int m = (l+r)/2;
	int ans=inf,ansi=b;
	Loop(j,b,min(e,m)){
		if(sum[j][m]+dp[i][j] < ans)
			ans = sum[j][m]+dp[i][j], ansi=j;
	}
	dp[i+1][m] = ans;
	up(i,l,m,b,ansi+1);
	up(i,m+1,r,ansi,e);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,0,n) Loop(j,0,n) cin >> a[i][j];
	Loop(i,0,n) Loop(j,i,n) sum0[i][j+1] = sum0[i][j]+a[i][j];
	LoopR(i,0,n-1) Loop(j,i,n) sum[i][j+1] = sum[i+1][j+1]+sum0[i][j+1];
	Loop(i,1,N) dp[0][i]=inf;
	Loop(i,0,k) up(i);
	//Loop(i,0,n+1){
	//	Loop(j,0,n+1) cout << sum[i][j] << ' ';
	//	cout << '\n';
	//}
	cout << dp[k][n] << '\n';
}