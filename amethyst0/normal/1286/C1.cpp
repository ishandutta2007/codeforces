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

int main() {
	int n;

	cin >> n;

	multiset <string> a = ask(1, n);

	if (n == 1) {
		cout << "! " << (*a.begin()) << endl;
	}
	else {
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
}