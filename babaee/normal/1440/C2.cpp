#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<vector<pll>> ans;
int n, m;
char A[MAXN][MAXN];

void flip(int i, int j) {
	if (A[i][j] == '0') A[i][j] = '1';
	else A[i][j] = '0';
}

void DL(int x, int y) {
	ans.push_back({{x, y}, {x - 1, y}, {x, y + 1}});
	flip(x, y);
	flip(x - 1, y);
	flip(x, y + 1);
}

void UL(int x, int y) {
	ans.push_back({{x, y}, {x + 1, y}, {x, y + 1}});
	flip(x, y);
	flip(x + 1, y);
	flip(x, y + 1);
}

void UR(int x, int y) {
	ans.push_back({{x, y}, {x, y - 1}, {x + 1, y}});
	flip(x, y);
	flip(x, y - 1);
	flip(x + 1, y);
}

void DR(int x, int y) {
	ans.push_back({{x, y}, {x, y - 1}, {x - 1, y}});
	flip(x, y);
	flip(x, y - 1);
	flip(x - 1, y);
}

void make_ok(int i, int j) {
	if (i > 1 && j > 1) {
		DR(i, j);
		DL(i, j - 1);
		UR(i - 1, j);
	} else if (i > 1) {
		DL(i, j);
		UL(i - 1, j);
		DR(i, j + 1);
	} else if (j > 1) {
		UR(i, j);
		UL(i, j - 1);
		DR(i + 1, j);
	} else {
		UL(i, j);
		UR(i, j + 1);
		DL(i + 1, j);
	}
}

void ok22(int i, int j) {
	if (A[i][j] == '1' && A[i + 1][j] == '1' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '1') UL(i, j), UR(i, j + 1), DL(i + 1, j), DR(i + 1, j + 1);
	else if (A[i][j] == '1' && A[i + 1][j] == '1' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '0') UL(i, j);
	else if (A[i][j] == '1' && A[i + 1][j] == '1' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '1') DL(i + 1, j); 
	else if (A[i][j] == '1' && A[i + 1][j] == '1' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '0') UR(i, j + 1), DR(i + 1, j + 1);
	else if (A[i][j] == '1' && A[i + 1][j] == '0' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '1') UR(i, j + 1); 
	else if (A[i][j] == '1' && A[i + 1][j] == '0' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '0') DL(i + 1, j), DR(i + 1, j + 1);
	else if (A[i][j] == '1' && A[i + 1][j] == '0' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '1') UL(i, j), DR(i + 1, j + 1);
	else if (A[i][j] == '1' && A[i + 1][j] == '0' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '0') make_ok(i, j);
	else if (A[i][j] == '0' && A[i + 1][j] == '1' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '1') DR(i + 1, j + 1);
	else if (A[i][j] == '0' && A[i + 1][j] == '1' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '0') UR(i, j + 1), DL(i + 1, j);
	else if (A[i][j] == '0' && A[i + 1][j] == '1' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '1') UL(i, j), UR(i, j + 1);
	else if (A[i][j] == '0' && A[i + 1][j] == '1' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '0') make_ok(i + 1, j);
	else if (A[i][j] == '0' && A[i + 1][j] == '0' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '1') UL(i, j), DL(i + 1, j);
	else if (A[i][j] == '0' && A[i + 1][j] == '0' && A[i][j + 1] == '1' && A[i + 1][j + 1] == '0') make_ok(i, j + 1); 
	else if (A[i][j] == '0' && A[i + 1][j] == '0' && A[i][j + 1] == '0' && A[i + 1][j + 1] == '1') make_ok(i + 1, j + 1);
}

int solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];	
		}
	}

	if (n & 1) {
		int i = n;
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				if (A[i][j] == '1') DL(i, j);
			} else if (A[i][j] == '1') UR(i - 1, j);
		}	
		n--;
	}

	if (m & 1) {
		int j = m;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				if (A[i][j] == '1') UR(i, j);
			} else if (A[i][j] == '1') DL(i, j - 1);
		}

		m--;
	}

	for (int i = 1; i < n; i += 2) {
		for (int j = 1; j < m; j += 2) {
			ok22(i, j);
		}
	}

	cout << ans.size() << endl;
	for (vector<pll> e : ans) {
		cout << e[0].X << sep << e[0].Y << sep << e[1].X << sep << e[1].Y << sep << e[2].X << sep << e[2].Y << endl;
	}

	ans.clear();
	return 0;
}
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}