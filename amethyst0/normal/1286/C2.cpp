#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

multiset <string> ask(int l, int r) {
	cout << "? " << l << ' ' << r << endl;

	int cnt = r - l + 1;
	cnt = cnt * (cnt + 1) / 2;

	multiset <string> s;

	for (int i = 0; i < cnt; i++) {
		string x;

		cin >> x;
		sort(x.begin(), x.end());

		s.insert(x);
	}

	return s;
}

int cnt[26];

void add(string &s, int tp) {
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (tp == 1) {
			cnt[c - 'a']++;
		}
		else {
			cnt[c - 'a']--;
		}
	}
}

bool cmp(const string &a, const string &b) {
	return a.size() < b.size();
}

int num[26][1000];

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		multiset <string> a = ask(1, n);
		cout << "! " << (*a.begin()) << endl;
	}
	else if (n <= 3) {
		multiset <string> a = ask(1, n);
		multiset <string> b = ask(2, n);

		for (auto x : b) {
			a.erase(a.find(x));
		}

		string cur;

		vector <string> f(a.begin(), a.end());

		sort(f.begin(), f.end(), cmp);

		for (auto s : f) {
			memset(cnt, 0, sizeof cnt);
			add(cur, -1);
			add(s, 1);

			for (int i = 0; i < 26; i++) {
				if (cnt[i] != 0) {
					cur.push_back('a' + i);
				}
			}
		}

		cout << "! " << cur << endl;
	}
	else {
		int m = 2 * n / 3;

		multiset <string> a = ask(1, m);
		multiset <string> b = ask(2, m);

		for (auto x : b) {
			a.erase(a.find(x));
		}

		string cur;

		vector <string> f(a.begin(), a.end());

		sort(f.begin(), f.end(), cmp);

		for (auto s : f) {
			memset(cnt, 0, sizeof cnt);
			add(cur, -1);
			add(s, 1);

			for (int i = 0; i < 26; i++) {
				if (cnt[i] != 0) {
					cur.push_back('a' + i);
				}
			}
		}

		cur.resize(n);

		int d = n - m;
		d *= 2;

		auto c = ask(n - d + 1, n);

		for (auto x : c) {
			for (char f : x) {
				num[f - 'a'][x.size()]++;
			}
		}

		int l = n - d + 1;
		int pos = n - d + 1;

		while (pos <= m) {
			int len = pos - l + 2;

			multiset <char> g;

			for (int c = 0; c < 26; c++) {
				int h = num[c][len] - num[c][len - 1];
				h = num[c][d] - h;
				for (int i = 0; i < pos - l; i++) {
					if (cur[l - 1 + i] == 'a' + c) {
						h--;
					}

					if (cur[n - 1 - i] == 'a' + c) {
						h--;
					}
				}

				while (h > 0) {
					g.insert('a' + c);
					h--;
				}
			}

			g.erase(g.find(cur[pos - 1]));
			cur[n - 1 - (pos - l)] = (*g.begin());
			pos++;
		}

		cout << "! " << cur << endl;
	}
}