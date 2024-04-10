#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

string solve(int al, string s, string a, string b) {
	int n = (int)s.size();
	vector<int> p(al, -1), k(al, -1);
	string nov;
	forn(i, n) nov += ' ';
	string ans = " ";
	forn(i, n) {
		if (p[s[i] - 'a'] != -1)
			nov[i] = char('a' + p[s[i] -'a']);
		if (a[i] == b[i]) {
			if (nov[i] != a[i] && nov[i] != ' ') return ans;
			if (nov[i] == ' ') {
				if (k[a[i] - 'a'] != -1) return ans;
				p[s[i] - 'a'] = a[i] - 'a';
				k[a[i] - 'a'] = s[i] - 'a';
				nov[i] = a[i];
			}
			continue;
		}
		if (nov[i] != ' ' && (nov[i] < a[i] || nov[i] > b[i])) return ans;
		if (nov[i] == ' ') {
			for (int j = a[i] - 'a' + 1; j != b[i] - 'a'; ++j) {
				if (k[j] == -1) {
					p[s[i] - 'a'] = j;
					k[j] = s[i] - 'a';
					int l = 0;
					forn(r, al) {
						if (p[r] >= 0) continue;
						while (k[l] != -1) l++;
						p[r] = l;
						k[l] = r;
					}
					ans = "";
					forn(r, al) {
						ans += char('a' + p[r]);
					}
					return ans;
				}
			}
		}
		else {
			if (nov[i] > a[i] && nov[i] < b[i]) {
				int l = 0;
				forn(r, al) {
					if (p[r] >= 0) continue;
					while (k[l] != -1) l++;
					p[r] = l;
					k[l] = r;
				}
				ans = "";
				forn(r, al) {
					ans += char('a' + p[r]);
				}
				return ans;
			}
		}
		vector<int> p1(al), k1(al);
		copy(all(p), p1.begin()); copy(all(k), k1.begin());
		bool good = 1;
		string nov1 = nov;
		if ((nov[i] == ' ' && k1[a[i] - 'a'] == -1) || nov[i] == a[i]) {
			p1[s[i] - 'a'] = a[i] - 'a';
			k1[a[i] - 'a'] = s[i] - 'a';
			for (int j = i + 1; j < n; ++j) {
				if (p1[s[j] - 'a'] != -1)
					nov1[j] = 'a' + p1[s[j] - 'a'];
				if (nov1[j] != ' ' && nov1[j] < a[j]) {
					good = 0;
					break;
				}
				if (nov1[j] != ' ') {
					if (nov1[j] > a[j]) break;
					continue;
				}
				bool qq = 0;
				for (int l = a[j] - 'a' + 1; l < al; ++l) {
					if (k1[l] == -1) {
						p1[s[j] - 'a'] = l;
						k1[l] = s[j] - 'a';
						qq = 1;
						break;
					}
				}
				if (qq) break;
				if (k1[a[j] - 'a'] != -1) {
					good = 0;
					break;
				}
				p1[s[j] - 'a'] = a[j] - 'a';
				k1[a[j] - 'a'] = s[j] - 'a';
			}
		}
		else good = 0;
		if (good) {
			int l = 0;
			forn(r, al) {
				if (p1[r] >= 0) continue;
				while (k1[l] != -1) l++;
				p1[r] = l;
				k1[l] = r;
			}
			ans = "";
			forn(r, al) {
				ans += char('a' + p1[r]);
			}
			return ans;
		}
		copy(all(p), p1.begin()); copy(all(k), k1.begin());
		good = 1;
		nov1 = nov;
		if ((nov[i] == ' ' && k1[b[i] - 'a'] == -1) || nov[i] == b[i]) {
			p1[s[i] - 'a'] = b[i] - 'a';
			k1[b[i] - 'a'] = s[i] - 'a';
			for (int j = i + 1; j < n; ++j) {
				if (p1[s[j] - 'a'] != -1)
					nov1[j] = 'a' + p1[s[j] - 'a'];
				if (nov1[j] != ' ' && nov1[j] > b[j]) {
					good = 0;
					break;
				}
				if (nov1[j] != ' ') {
					if (nov1[j] < b[j]) break;
					continue;
				}
				bool qq = 0;
				for (int l = b[j] - 'a' - 1; l >= 0; --l) {
					if (k1[l] == -1) {
						p1[s[j] - 'a'] = l;
						k1[l] = s[j] - 'a';
						qq = 1;
						break;
					}
				}
				if (qq) break;
				if (k1[b[j] - 'a'] != -1) {
					good = 0;
					break;
				}
				p1[s[j] - 'a'] = b[j] - 'a';
				k1[b[j] - 'a'] = s[j] - 'a';
			}
		}
		else good = 0;
		if (good) {
			int l = 0;
			forn(r, al) {
				if (p1[r] >= 0) continue;
				while (k1[l] != -1) l++;
				p1[r] = l;
				k1[l] = r;
			}
			ans = "";
			forn(r, al) {
				ans += char('a' + p1[r]);
			}
			return ans;
		}
		else return ans;
	}
	int l = 0;
	forn(r, al) {
		if (p[r] >= 0) continue;
		while (k[l] != -1) l++;
		p[r] = l;
		k[l] = r;
	}
	ans = "";
	forn(r, al) {
		ans += char('a' + p[r]);
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		string s, a, b;
		cin >> s >> a >> b;
		auto tmp = solve(k, s, a, b);
		if (tmp[0] == ' ') cout << "NO\n";
		else cout << "YES\n" << tmp << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}