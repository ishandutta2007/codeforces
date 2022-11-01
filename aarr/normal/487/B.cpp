#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100 * 1000 + 5, LG = 20;
int s;

int a[N];
int dp1[LG][N];
int dp2[LG][N];
int dp[N];
int go[N];
set <int> st;
bool isval(int l, int r) {
	int y = 31 - __builtin_clz(r - l + 1);
	int mn = min(dp1[y][l], dp1[y][r - (1 << y) + 1]);
	int mx = max(dp2[y][l], dp2[y][r - (1 << y) + 1]);
//	cout << "26 " << mn << " " << mx << endl;
	return mx - mn <= s;
}
int main() {
	int n, l;
	cin >> n >> s >> l;
	for (int i = 1; i <= n; i++) {
		cin >> dp1[0][i];
		dp2[0][i] = dp1[0][i];
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			dp1[j][i] = dp1[j - 1][i];
			dp2[j][i] = dp2[j - 1][i];
			if (i + (1 << (j - 1)) <= n) {
				dp1[j][i] = min(dp1[j][i], dp1[j - 1][i + (1 << (j - 1))]);
				dp2[j][i] = max(dp2[j][i], dp2[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
//	isval(4, 5);
	for (int i = 1; i <= n; i++) {
		int dw = i, up = n + 1;
		while (up - dw > 1) {
			int md = (dw + up) / 2;
			if (isval(i, md))
				dw = md;
			else
				up = md;
				
		}
//		cout << i << " " << dw << endl;
		go[i] = dw;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
	}
	st.insert(0);
	st.insert(n + 1);
	st.insert(n + 2);
//	int x = 1, ans = 0;
	for (int i = n; i; i--) {
		set <int> :: iterator it = st.upper_bound(go[i] + 1);
		it--;
		int y = *it;
		if (y - i >= l) {
			dp[i] = dp[y] + 1;
			st.insert(i);
		}
	}
	cout << dp[1] << endl;
	return 0;
}