// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 84;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int dp[N][N][N * N];

vector<int> A;

int C2(int x){
	return x * (x - 1) / 2;
}

int ans[N*N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	A.pb(0);
	int n;
	cin >> n;
	int v, cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> v;
		if(v == 1)
			A.pb(i);
		else
			cnt ++;
	}
	A.pb(n + 1);
	int m = A.size();

	memset(dp, 31, sizeof dp);	
	dp[0][0][0] = 0;
	int mv;
	int mx = n * (n - 1) / 2;
	for(int i = 1; i < m; i++){
		for(int j = 1; j <= n + 1; j++){
			mv = abs(A[i] - j);
			for(int k = mv; k <= mx; k++){
				for(int la = 0; la < j; la ++){
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][la][k - mv] + C2(j - la - 1));
				}
			}
		}
	}
	for(int c = 0; c <= mx; c++){
		ans[c] = C2(cnt) - dp[m - 1][n + 1][c];
		if(c) 
			ans[c] = max(ans[c], ans[c - 1]);
		cout << ans[c] << " \n"[c == mx];
	}

	return 0;
}