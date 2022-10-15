#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define y1 ngsdf
#define ld long double
#define sqr(a) ( (a) * (a) )
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> ii;
const ld E = 1e-9;
const int MAX = 1e9;

int main() {

	int r, s, p;
	cin >> r >> s >> p;

	ld dp[r + 1][s + 1][p + 1];
	ms(dp);
	dp[r][s][p] = 1;

	for(int a = r; a >= 0; a--)
		for(int b = s; b >= 0; b--)
			for(int c = p; c >= 0; c--)
				if(dp[a][b][c] >= 1e-20){
					ld d = a * b + b * c + a * c;
					if(a > 0 && b > 0)
						dp[a][b - 1][c] += (ld) a * b * dp[a][b][c] / d;
					if(b > 0 && c > 0)
						dp[a][b][c - 1] += (ld) b * c * dp[a][b][c] / d;
					if(c > 0 && a > 0)
						dp[a - 1][b][c] += (ld) a * c * dp[a][b][c] / d;
				}

	ld ans1 = 0, ans2 = 0, ans3 = 0;

	for(int i = 1; i <= r; i++)
		ans1 += dp[i][0][0];
	for(int i = 1; i <= s; i++)
		ans2 += dp[0][i][0];
	for(int i = 1; i <= p; i++)
		ans3 += dp[0][0][i];

	cout.precision(20);
	cout << fixed << ans1 << " " << ans2 << " " << ans3;


}