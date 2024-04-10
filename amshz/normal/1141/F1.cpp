# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e1+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const int inf = 1e9+10;


int n, A[xn], PS[xn], dp[xn], Par[xn], ans[xn][xn], mx;
bool par[xn];

int Solve(int sum){
	memset(dp, 0, sizeof dp);
	memset(Par, 0, sizeof Par);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) if (PS[i] - PS[j - 1] == sum) Par[i] = j;
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		if (Par[i]) dp[i] = max(dp[i], dp[Par[i] - 1] + 1);
	}
	return dp[n];
}
void Output(int sum){
	memset(dp, 0, sizeof dp);
	memset(Par, 0, sizeof Par);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) if (PS[i] - PS[j - 1] == sum) Par[i] = j;
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		if (Par[i] && dp[Par[i] - 1] + 1 > dp[i]) dp[i] = dp[Par[i] - 1] + 1, par[i] = true;
	}
	cout << dp[n] << endl;
	int x = n;
	while (x){
		if (par[x]) cout << Par[x] << sep << x << endl, x = Par[x] - 1;
		else x--;
	}
	return;
}


int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], PS[i] = PS[i - 1] + A[i];
	
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) ans[i][j] = Solve(PS[j] - PS[i - 1]), mx = max(mx, ans[i][j]);
	
			
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (ans[i][j] == mx){
				Output(PS[j] - PS[i - 1]);
				return 0;
			}
		}
	}

	
	return 0;
}