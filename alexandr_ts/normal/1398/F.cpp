#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 21;

int d[2][N];
int len[N];
int jump[M][N];
string s;

void prec(int n) {
	d[0][n - 1] = d[1][n - 1] = -1;
	len[n - 1] = 1;
	if (s.back() == '0' || s.back() == '?') d[0][n - 1] = n - 1;
	if (s.back() == '1' || s.back() == '?') d[1][n - 1] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		d[0][i] = -1;
		d[1][i] = -1;
		if (s[i] == '0' || s[i] == '?') {
			d[0][i] = max(i, d[0][i + 1]);
			len[i] = max(len[i], d[0][i] - i + 1);
		}
		if (s[i] == '1' || s[i] == '?') {
			d[1][i] = max(i, d[1][i + 1]);
			len[i] = max(len[i], d[1][i] - i + 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		jump[0][i] = len[i];
		jump[1][i] = max(len[i], len[i + 1]);
	}
	for (int j = 2; j < M; ++j) {
		for (int i = 0; i < n; ++i) {
			jump[j][i] = jump[j - 1][i];
			if (i + (1 << (j - 1)) < n) {
				jump[j][i] = max(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
}

int getnext(int i, int x, int n) {
	if (len[i] >= x) return i;
	if (jump[M - 1][i] < x) return n;
	int ans = i;
	for (int j = M - 1; j >= 0; --j) {
		if (jump[j][ans] < x) {
			ans += (1 << j);	
		}	
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	cin >> s;
	prec(n);

	for (int x = 1; x <= n; ++x) {
		int ans = 0;
		int i = 0;
		while (i < n) {
			i = getnext(i, x, n);	
			if (i < n) {
				ans++;
				i += x;
			}
		}
		cout << ans << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}