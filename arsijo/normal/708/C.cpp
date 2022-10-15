#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
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
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
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

#ifdef LOCAL
//#define DEBUG
#endif

const int MAX = 4e5 + 1;
vector<ii> vec[MAX];
int n;
int a[MAX << 1], b[MAX << 1];
int res[MAX << 1];
vector<int> v[MAX];
int down[MAX];
int pr[MAX];
void dfs1(int pos, int prev = -1) {
	down[pos] = 1;
	pr[pos] = prev;
	//cout << "S " << pos << " " << vec[pos].size() << endl;
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		int to = vec[pos][i].first;
		//cout << ": " << pos << " "<< to << endl;
		if (prev != to) {
			dfs1(to, pos);
			down[pos] += down[to];
			//cout << "add " << pos << " " << to << endl;
		}
	}
}

int dfs2(int pos, int prev = -1) {
	int ans = 1;
	if (down[pos] <= n / 2) {
		ans = down[pos];
	}
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		int to = vec[pos][i].first;
		if (prev != to) {
			int res = dfs2(to, pos);
			::res[vec[pos][i].second] = res;
			if (res <= n / 2) {
				v[pos].push_back(res);
				ans = max(ans, res);
			}
		}
	}
	v[pos].push_back(1);
	sort(v[pos].begin(), v[pos].end());
	return ans;
}

void dfs3(int pos, int prev = -1, int val = 0) {
	if (n - down[pos] <= n / 2) {
		val = max(val, n - down[pos]);
	}
	//cout << "# " << pos << " " << v[pos].back() << endl;
	//cout << "! " << pos << " " << val << endl;
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		int to = vec[pos][i].first;
		if (to != prev) {
			int t = res[vec[pos][i].second];
			int ind = vec[pos][i].second ^ 1;
			res[ind] = val;
			if (t <= n / 2) {
				res[ind] = max(res[ind],
						v[pos].back() == t ?
								v[pos][v[pos].size() - 2] : v[pos].back());
			} else {
				res[ind] = max(res[ind], v[pos].back());
			}
			if(n - down[to] <= n / 2){
				res[ind] = max(res[ind], n - down[to]);
			}
			dfs3(to, pos, res[ind]);
		}
	}
}

int main() {
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	int size = 0;

	for (int i = 1; i < n; i++) {
		int c, d;
		cin >> c >> d;
		a[size] = c;
		b[size] = d;
		vec[c].push_back(make_pair(d, size));
		size++;
		a[size] = d;
		b[size] = c;
		vec[d].push_back(make_pair(c, size));
		size++;
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	if(0) {
		for(int i = 0; i < n + n; i++) {
			cout << a[i] << " " << b[i] << " " << res[i] << endl;
		}
		for(int i = 1; i <= n; i++)
		cout << down[i] << endl;
	}
	for (int pos = 1; pos <= n; pos++) {
		int t = -1;
		int ind;
		int r;
		for (int i = 0; i < (int) vec[pos].size(); i++) {
			int to = vec[pos][i].first;
			if (to == pr[pos]) {
				r = n - down[pos];
			} else {
				r = down[to];
			}
			if (r > n / 2) {
				t = to;
				ind = vec[pos][i].second;
				break;
			}
		}
		bool ans = true;
		if (t != -1) {
			if (r - res[ind] > n / 2)
				ans = false;
		}
		putchar(ans ? '1' : '0');
		if (pos != n)
			putchar(' ');
	}
	putchar('\n');

}