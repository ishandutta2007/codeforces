#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1010;

ll n, m, a, ans, k, tmp;
ll A[6][MAXN];
ll B[6][MAXN];
ll dp[MAXN];

bool check(int x, int y){  // true if all B[x]<B[y]
	for (int i=0; i<k; i++) if (B[i][x]>=B[i][y]) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=0; i<k; i++){
		for (int j=1; j<=n; j++){
			cin>>A[i][j];
			B[i][A[i][j]]=j;
		}
	}
	
	for (int x=1; x<=n; x++){
		int i=A[0][x];
		dp[i]=1;
		for (int j=1; j<=n; j++){
			if (j==i) continue ;
			if (check(j, i)) dp[i]=max(dp[i], dp[j]+1);
		}
	}
	//for (int i=1; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	cout<<*max_element(dp, dp+n+1)<<endl;
	return 0;
}