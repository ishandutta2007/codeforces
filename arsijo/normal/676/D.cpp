#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 9;
const ld E = 1e-13;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

map<char, char> m;

#define left s[0]
#define right s[2]
#define up s[1]
#define down s[3]
int X[4] = { 0, -1, 0, 1 }, Y[4] = { -1, 0, 1, 0 };
set<char> s[4];

int main() {

	sync;
	srand(time(NULL));
	cout.precision(40);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	left.insert('+');
	left.insert('-');
	left.insert('<');
	left.insert('U');
	left.insert('R');
	left.insert('D');

	right.insert('+');
	right.insert('-');
	right.insert('>');
	right.insert('U');
	right.insert('L');
	right.insert('D');

	up.insert('+');
	up.insert('|');
	up.insert('^');
	up.insert('L');
	up.insert('R');
	up.insert('D');

	down.insert('+');
	down.insert('|');
	down.insert('v');
	down.insert('L');
	down.insert('R');
	down.insert('U');

	m['|'] = '-';
	m['-'] = '|';
	m['+'] = '+';
	m['^'] = '>';
	m['>'] = 'v';
	m['v'] = '<';
	m['<'] = '^';
	m['^'] = '>';
	m['L'] = 'U';
	m['U'] = 'R';
	m['R'] = 'D';
	m['D'] = 'L';
	m['*'] = '*';
	int n, m;
	cin >> n >> m;
	char ar[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	bool used[4][n][m];
	ms(used);
	int ans[4][n][m];
	ms(ans);
	x1--, y1--, x2--, y2--;
	used[0][x1][y1] = true;
	queue<pair<ii, int> > q;
	q.push(make_pair(make_pair(x1, y1), 0));
	while(!q.empty()) {
		int t = q.front().second;
		int x = q.front().first.first, y = q.front().first.second;
		q.pop();
		if(x == x2 && y == y2) {
			cout << ans[t][x][y] << endl;
			return 0;
		}
		char type = ar[x][y];
		for(int i = 0; i < t; i++) {
			type = ::m[type];
		}
		if(!used[(t + 1) % 4][x][y]) {
			used[(t + 1) % 4][x][y] = true;
			q.push(make_pair(make_pair(x, y), (t + 1) % 4));
			ans[(t + 1) % 4][x][y] = ans[t][x][y] + 1;
		}
		for(int i = 0; i < 4; i++) {
			int x1 = x + X[i];
			int y1 = y + Y[i];
			if(0 <= x1 && x1 < n && 0 <= y1 && y1 < m && s[i].find(type) != s[i].end() && !used[t][x1][y1]) {
				char c = ar[x1][y1];
				for(int w = 0; w < t; w++)
				c = ::m[c];
				if(s[(i + 2) % 4].find(c) != s[(i + 2) % 4].end()) {
					used[t][x1][y1] = true;
					q.push(make_pair(make_pair(x1, y1), t));
					ans[t][x1][y1] = ans[t][x][y] + 1;
				}
			}
		}
	}

	cout << -1 << endl;

}