// vaziat meshki-ghermeze !
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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n;
int dp[N*N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int oo = 1e9;
	for(int i = 0; i < N*N; i++){
		fill(dp[i], dp[i] + N, -oo);
	}

	dp[0][0] = 0;
	int c, v;
	int smv = 0;
	for(int i = 0; i < n; i++){
		cin >> c >> v;
		smv += v;
		for(int sm = N*N - 1; sm >= c; sm --){
			for(int j = N - 1; j > 0; j--){
				dp[sm][j] = max(dp[sm][j], dp[sm - c][j - 1] + v);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		int ans = 0;
		for(int sm = 0; sm < N * N; sm ++){
			ans = max(ans, min(2 * sm, smv + dp[sm][i]));
		}
		cout << fixed << setprecision(12) << (ans)/((ld) 2) << ' ';

	}
	cout << '\n';
	return 0;
}