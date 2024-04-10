#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ui MOD = 1e9 + 7;
const ld E = 1e-7;
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
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
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

const int MAX = 456976;
const int MAX2 = 17576;
const int MAX3 = 26 * 26;
const int MAX4 = 26;
const int MAX_SIZE = MAX + MAX2 + MAX3 + MAX4;
int p[MAX_SIZE];
vector<int> vec[200];
int ans = 0;

string get(char c) {
	return string(1, c);
}

int get_ind(string s) {
	int n = (int) s.size();
	int ans = 0;
	if (n < 4) {
		ans += MAX;
	}
	if (n < 3) {
		ans += MAX2;
	}
	if (n < 2) {
		ans += MAX3;
	}
	int t = 1;
	//cout << "| " << n << " " << ans << endl;
	for (int i = 0; i < n; i++, t *= 26) {
		ans += (s[i] - 'a') * t;
	}
	return ans;
}

void add(int q, string s) {
	set<string> ss;
	int n = (int) s.size();
	for (int a = 0; a < n; a++) {
		ss.insert(get(s[a]));
		for (int b = a + 1; b < n; b++) {
			ss.insert(get(s[a]) + get(s[b]));
			for (int c = b + 1; c < n; c++) {
				ss.insert(get(s[a]) + get(s[b]) + get(s[c]));
				for (int d = c + 1; d < n; d++) {
					ss.insert(get(s[a]) + get(s[b]) + get(s[c]) + get(s[d]));
				}
			}
		}
	}
	for (set<string>::iterator it = ss.begin(); it != ss.end(); it++) {
		vec[q].push_back(get_ind(*it));
	}
}

bool used[200];

bool find(int pos) {
	//cout << "$ " << pos << " " << vec[pos].size() << endl;
	if (used[pos])
		return false;
	used[pos] = true;
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		int to = vec[pos][i];
		//cout << "! " << pos << " " << to << " " << p[to] << endl;
		if (p[to] == -1 || (find(p[to]))) {
			p[to] = pos;
			//cout << "Find" << endl;
			return true;
		}
	}
	//cout << "-" << endl;
	return false;
}

string get_string(int res) {
	int size = 4;
	if (res >= MAX) {
		res -= MAX;
		size--;
		if (res >= MAX2) {
			res -= MAX2;
			size--;
			if (res >= MAX3) {
				res -= MAX3;
				size--;
			}
		}
	}
	string ans = "";
	for (int i = 0; i < size; i++) {
		ans += char(res % 26 + 'a');
		res /= 26;
	}
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(30);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else
	input;
	output;
#endif

	for(int i = 0; i < MAX_SIZE; i++)
	p[i] = -1;

	int n;
	cin >> n;
	string st[n];
	string res[n];
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st[i] = s;
		add(i, s);
	}
	for(int i = 0; i < n; i++) {
		//cout << "@ " << i << endl;
		ms(used);
		ans += find(i);
	}
	dbg
	for(int i = 0; i < MAX_SIZE; i++) {
		if(p[i] != -1) {
			cout << i << " " << p[i] << endl;
		}
	}
	//cout << "@ " << ans << endl;
	if(ans != n) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < MAX_SIZE; i++) {
		if(p[i] != -1) {
			//cout << i << endl;
			res[p[i]] = get_string(i);
		}
	}

	for(int i = 0; i < n; i++)
	cout << res[i] << endl;

}