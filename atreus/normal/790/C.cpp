#include <set>
#include <cstring>
#include <stack>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 12157;
const int maxn = 5e5 + 50;
const int infint = (ll)1e9;
int dp[80][80][80][4];
vector <int> v[5];
int A, B, C;

int find (int x, int y, int a, int b) {
	x --;
	a --;
	int l = -1, r = a + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (v[b][mid] > v[y][x])
			r = mid;
		else
			l = mid;
	}
	return max (0, a - r + 1);
}

int main () {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V')
			v[0].PB (i);
		else if (s[i] == 'K')
			v[1].PB (i);
		else
			v[2].PB (i);
	}
	memset (dp, 63, sizeof dp);
	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	dp[0][0][0][2] = 0;
	A = v[0].size(), B = v[1].size(), C = v[2].size();
	for (int i = 1; i <= n; i++) {
		for (int a = 0; a <= min (A, i); a++) {
			for (int b = 0; b <= min (B, i - a); b++) {
				for (int k = 0; k <= 2; k++) {
					int c = i - a - b;
					if (c > C) 
						break;
					if ((k == 0 and a == 0) or (k == 1 and b == 0) or (k == 2 and c == 0))
						continue;
					int dis, newa, newb;
					if (k == 0) {
						dis = v[0][a - 1] + find (a, 0, b, 1) + find (a, 0, c, 2) - (i - 1);
						newa = a - 1;
						newb = b;
					}
					else if (k == 1) {
						dis = v[1][b - 1] + find (b, 1, a, 0) + find (b, 1, c, 2) - (i - 1); 
						newa = a;
						newb = b - 1;
					}
					else {
						dis = v[2][c - 1] + find (c, 2, a, 0) + find (c, 2, b, 1) - (i - 1);
						newa = a;
						newb = b;
					}
					if (k != 1)
						dp[i][a][b][k] = min (dp[i][a][b][k], dp[i - 1][newa][newb][0] + dis);
					dp[i][a][b][k] = min (dp[i][a][b][k], dp[i - 1][newa][newb][1] + dis);
					dp[i][a][b][k] = min (dp[i][a][b][k], dp[i - 1][newa][newb][2] + dis);
//					cout << i << " " << a << " " << b << " " << k << " = " << dp[i][a][b][k] << " - " << dis << endl;
				}
			}
		}
	}
	int ans = infint;
	ans = min (dp[n][A][B][0], dp[n][A][B][1]);
	ans = min (ans, dp[n][A][B][2]);
	cout << ans << endl;
}