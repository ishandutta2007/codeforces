#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}
#ifdef LOCAL
#define DEBUG
#endif
#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;

int check(string s) {
	if ((int) s.size() > 6) {
		return 0;
	}
	if (s[0] < '1' || s[0] > '9')
		return 0;
	int ans = 0;
	for (char c : s) {
		if (c < '0' || c > '9') {
			return 0;
		}
		ans = ans * 10 + (c - '0');
	}
	if (ans > n)
		return 0;
	return ans;
}

string _to_string(int n) {
	string ans = "";
	while (n) {
		ans = char(n % 10 + '0') + ans;
		n /= 10;
	}
	return ans;
}

vector<string> vec[2][2];

const int MAX = 1e5 + 10;

bool used[MAX];

vector<int> available[2];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	int h = 0;
	vector<pair<string, int> > v;
	for(int i = 0; i < n; i++) {
		string s;
		int t;
		cin >> s >> t;
		h += t;
		v.push_back(make_pair(s, t));
	}
	int ok = 0;
	for(int i = 0; i < (int) v.size(); i++) {
		int res = check(v[i].first);
		if(!res) {
			vec[0][v[i].second].push_back(v[i].first);
			continue;
		}
		used[res] = true;
		if(res <= h) {
			if(v[i].second == 0) {
				vec[1][v[i].second].push_back(v[i].first);
			} else {
				ok++;
			}
		} else {
			if(v[i].second == 1) {
				vec[1][v[i].second].push_back(v[i].first);
			} else {
				ok++;
			}
		}
	}

	if(ok == n) {
		cout << 0 << endl;
		return 0;
	}

	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			available[i > h].push_back(i);
		}
	}

	vector<pair<string, string> > out;

	if(available[0].empty() && available[1].empty()) {
		string t = vec[1][0].back();
		vec[1][0].pop_back();
		available[0].push_back(check(t));
		out.push_back(make_pair(t, "q"));
		vec[0][0].push_back("q");
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			if(!available[j].empty()) {
				int pos = available[j].back();
				if(!vec[1][j ^ 1].empty()) {
					string name = vec[1][j ^ 1].back();
					vec[1][j ^ 1].pop_back();
					out.push_back(make_pair(name, _to_string(pos)));
					available[j ^ 1].push_back(check(name));
					available[j].pop_back();
				} else if(!vec[0][j ^ 1].empty()) {
					string name = vec[0][j ^ 1].back();
					vec[0][j ^ 1].pop_back();
					out.push_back(make_pair(name, _to_string(pos)));
					available[j].pop_back();
				}
			}
		}
	}

	for(int i = 0; i < 2; i++){
		assert(vec[0][i].size() == available[i].size());
		while(!available[i].empty()){
			int pos = available[i].back();
			available[i].pop_back();
			out.push_back(make_pair(vec[0][i].back(), _to_string(pos)));
			vec[0][i].pop_back();
		}
	}

	cout << out.size() << endl;

	for(pair<string, string> a : out) {
		cout << "move " << a.first << " " << a.second << endl;
	}

}