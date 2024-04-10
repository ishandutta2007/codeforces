#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, m, p;
const int MAX = 300;

int ar[MAX][MAX];

void add(vector<pair<ii, int> > &v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ar[i][j] = 1e9;
		}
	}
	for (int q = 0; q < (int) v.size(); q++) {
		int x = v[q].first.first, y = v[q].first.second;
		int val = v[q].second;
		ar[x][y] = min(ar[x][y], val);
	}
	int inf = 1e9;
	for (int q = 0; q < 2; q++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ar[i][j] = min(ar[i][j],
						min(i ? ar[i - 1][j] + 1 : inf,
								j ? ar[i][j - 1] + 1 : inf));
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				ar[i][j] = min(ar[i][j],
						min(i != n - 1 ? ar[i + 1][j] + 1 : inf,
								j != m - 1 ? ar[i][j + 1] + 1 : inf));
			}
		}
	}
}

void test() {
	int n = 300;
	ofstream cout("input.txt");
	cout << n << " " << n << " 300" << endl;
	int q = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << i + 1 << " ";
		}
		cout << endl;
	}
	cout.close();
}

vector<pair<ii, int> > res[90000 + 1];

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

	//test();

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n >> m >> p;

	vector<ii> colors[p + 1];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int a;
			cin >> a;
			colors[a].push_back(make_pair(i, j));
		}
	}

	res[0].push_back(make_pair(make_pair(0, 0), 0));
	int q = 300;
	for(int i = 0; i < p; i++) {
		if((int) res[i].size() >= q) {
			add(res[i]);
			for(int j = 0; j < (int) colors[i + 1].size(); j++) {
				res[i + 1].push_back(make_pair(colors[i + 1][j], ar[colors[i + 1][j].first][colors[i + 1][j].second]));
			}
		} else {
			for(int j = 0; j < (int) colors[i + 1].size(); j++) {
				int x = colors[i + 1][j].first;
				int y = colors[i + 1][j].second;
				int ans = 1e9;
				for(int z = 0; z < (int) res[i].size(); z++)
				ans = min(ans, abs(res[i][z].first.first - x) + abs(res[i][z].first.second - y) + res[i][z].second);
				res[i + 1].push_back(make_pair(colors[i + 1][j], ans));
			}
		}

	}

	int ans = 1e9;

	for(int i = 0; i < (int) res[p].size(); i++)
	ans = min(ans, res[p][i].second);

	cout << ans << endl;

}