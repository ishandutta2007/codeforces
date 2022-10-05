#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
const int C = 21;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<string> v;
bool viv = false;

int merge(vector<int> games) {
	int res = 0;
	for (auto lres : games)
		res ^= lres;
	return res;
}

int choose(vector<int> moves) {
	vector<bool> mex(moves.size() + 1, false);
	for (auto move: moves)
		if (move < mex.size())
			mex[move] = true;
	int res = 0;
	while (mex[res])
		res++;
	return res;
}

// unordered_map<vector<int>, int> mp;
// vector<int> h(vector<int> &v) {
// 	return v;
// }

vector<int> mp;
int h(vector<int> &v) {
	return C * (C * (C * (v[3]) + v[2]) + v[1]) + v[0];
}
void builder() {
	mp.assign(C * C * C * C, -1);
}


vector<vector<int>> get_games(int ly, int ry, int lx, int rx, int y, int x, char c) {
	vector<vector<int>> res;
	if (c == 'X') {
		res.push_back({ly, y, lx, x});
		res.push_back({ly, y, x + 1, rx});
		res.push_back({y + 1, ry, lx, x});
		res.push_back({y + 1, ry, x + 1, rx});
	}
	if (c == 'R') {
		res.push_back({ly, ry, lx, x});
		res.push_back({ly, ry, x + 1, rx});
	}
	if (c == 'L') {
		res.push_back({ly, y, lx, rx});
		res.push_back({y + 1, ry, lx, rx});
	}
	return res;
}

int solver(vector<string> &v, vector<int> &rec) {
	// int ly = rec[0];
	// int ry = rec[1];
	// int lx = rec[2];
	// int rx = rec[3];

	if (mp[h(rec)] != -1)
		return mp[h(rec)];

	vector<int> all;
	for (int i = rec[0]; i < rec[1]; i++) {
		for (int j = rec[2]; j < rec[3]; j++) {
			if (v[i][j] != '.') {
				int res = 0;
				vector<vector<int>> recs = get_games(rec[0], rec[1], rec[2], rec[3], i, j, v[i][j]);
				for (auto &rec : recs)
					res ^= solver(v, rec);
				all.push_back(res);
			}
		}
	}
	vector<bool> mex(all.size() + 1, false);
	for (auto val : all)
		mex[val] = true;
	int ans = 0;
	while (mex[ans])
		ans++;
	return mp[h(rec)] = ans;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &s : v)
		cin >> s;

	vector<string> f1, f2;
	f1.resize(n + m, string(n + m, '.'));
	f2 = f1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i + j;
			int y = i - j + m;
			if ((i + j) & 1)
				f1[x/2][y/2] = v[i][j];
			else
				f2[x/2][y/2] = v[i][j];
		}
	}

	if (viv) {
		for (auto s : f1)
			cout << s << endl;
		cout << endl;
		for (auto s : f2)
			cout << s << endl;
		cout << endl;
	}

	vector<int> rec = {0, (n + m + 1) / 2, 0, (n + m + 1) / 2};
	builder();
	int nimber_1 = solver(f1, rec);
	builder();
	int nimber_2 = solver(f2, rec);

	int nimber = merge({nimber_1, nimber_2});
	if (nimber)
		cout << "WIN\n";
	else
		cout << "LOSE\n";
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}