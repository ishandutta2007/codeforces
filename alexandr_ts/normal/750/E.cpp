#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

struct mat {
	vector<array<int, 5>> data;

	mat() {
		data.resize(5);
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				data[i][j] = INF;	
			}
			data[i][i] = 0;
		}	
	}

	mat(const mat& el) {
		data.resize(5);
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				data[i][j] = el.data[i][j];	
			}	
		}	
	}	

	void operator = (const mat& el) {	
		if (data.empty()) {
			data.resize(5);
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				data[i][j] = el.data[i][j];	
			}	
		}
	}
};

mat t[4 * N];
string s;

int nearest_left_7[N];
int cnt_6[N];

void prec(int n) {
	nearest_left_7[0] = -INF;	
	for (int i = 0; i < n; ++i) {
		if (s[i] == '7') {
			nearest_left_7[i] = i;	
		} else if (i) {
			nearest_left_7[i] = nearest_left_7[i - 1];
		}
		if (i) {
			cnt_6[i] += cnt_6[i - 1];	
		}
		if (s[i] == '6') {
			++cnt_6[i];	
		}
	}
}

void recalc(mat& m, const mat& m1, const mat& m2) {
	for (int i = 0; i <= 4; ++i) {
		for (int j = i; j <= 4; ++j) {
			m.data[i][j] = INF;
			for (int k = i; k <= j; ++k) {
				m.data[i][j] = min(m.data[i][j], m1.data[i][k] + m2.data[k][j]);	
			}		
		}	
	}
}


void build(int v, int tl, int tr) {
	if (tl == tr) {
		for (int i = 0; i <= 4; ++i) {
			t[v].data[i][i] = 0;
		}		
		if (s[tl] == '2') {
			t[v].data[0][0] = 1;
			t[v].data[0][1] = 0;	
		} else if (s[tl] == '0') {
			t[v].data[1][1] = 1;
			t[v].data[1][2] = 0;	
		} else if (s[tl] == '1') {
			t[v].data[2][2] = 1;
			t[v].data[2][3] = 0;	
		} else if (s[tl] == '6') {
			t[v].data[3][3] = 1;
			t[v].data[3][4] = 0;	
		}
		return;	
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm);
	build(2 * v + 1, tm + 1, tr);
	recalc(t[v], t[2 * v], t[2 * v + 1]);
}

mat get(int v, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r) {
		return mat(t[v]);	
	}
	mat ret;
	if (l > tr || tl > r) {
		return ret;	
	}	
	int tm = (tl + tr) / 2;
	auto res1 = get(2 * v, tl, tm, l, r);
	auto res2 = get(2 * v + 1, tm + 1, tr, l, r);
	recalc(ret, res1, res2);
	return ret;
}

void solve() {
	int n, q;
	cin >> n >> q;
	cin >> s;

	prec(n);
	build(1, 0, n - 1);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int new_r = nearest_left_7[r];
		if (new_r <= l) {
			cout << -1 << "\n";
			continue;	
		}
		int answer = cnt_6[r] - cnt_6[new_r];
		r = new_r - 1;
		auto matr = get(1, 0, n - 1, l, r);
		int ans = matr.data[0][3];
		if (ans >= INF) {
			cout << -1 << "\n";	
		} else {
			cout << ans + answer << "\n";	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}