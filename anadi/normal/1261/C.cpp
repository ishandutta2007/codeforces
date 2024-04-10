#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

const int DX[] = {-1, -1, 1, 1};
const int DY[] = {-1, 1, -1, 1};

int n, m;
string input[N];
vector <int> pref[N];
vector <int> tmp_pref[N];

bool check(int r, int c, int T) {
	if(input[r][c] != 'X' || r < T + 1 || c < T + 1 || r + T > n || c + T > m)
		return false;
	return pref[r + T][c + T] - pref[r - T - 1][c + T] - pref[r + T][c - T - 1] + pref[r - T - 1][c - T - 1] == (2 * T + 1) * (2 * T + 1);
}

bool ask(int T) {
	for(int i = 0; i <= n; ++i) {
		tmp_pref[i].resize(m + 1);
		for(auto &c: tmp_pref[i])
			c = 0;
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(check(i, j, T)) {
				tmp_pref[i + T][j + T] += 1;
				tmp_pref[i - T - 1][j - T - 1] += 1;

				tmp_pref[i + T][j - T - 1] -= 1;
				tmp_pref[i - T - 1][j + T] -= 1;
			}
	
	for(int i = n; i >= 1; --i)
		for(int j = m; j >= 1; --j) {
			if(i < n) tmp_pref[i][j] += tmp_pref[i + 1][j];
			if(j < m) tmp_pref[i][j] += tmp_pref[i][j + 1];
			if(i < n && j < m)	tmp_pref[i][j] -= tmp_pref[i + 1][j + 1];
			if(tmp_pref[i][j] == 0 && input[i][j] == 'X')
				return false;
		}
	
	return true;
}

int solve() {
	int s = 0, e = min(n - 1, m - 1) / 2;
	while(s < e) {
		int mid = (s + e + 1) >> 1;
		if(ask(mid))
			s = mid;
		else
			e = mid - 1;
	}
	
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> input[i];
		input[i] = "." + input[i];
		pref[i].resize(m + 1);
	}
	
	pref[0].resize(m + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (input[i][j] == 'X');
	
	int T = solve();
	printf("%d\n", T);

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			printf(check(i, j, T) ? "X" : ".");
		puts("");
	}

	return 0;
}