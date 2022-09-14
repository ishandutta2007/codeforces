#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)3e5 + 10;
string s;
string cur = "";

struct point {
	int ed[26];
	int cnt;
	bool end;
	bool fl;

	point() {
		end = false;
		fl = true;
		cnt = 0;
		memset(ed, -1, sizeof ed);
	}
};

point mas[maxn];
int posit = 0;

int my_new() {
	return posit++;
}

int add(int t, int pos) {
	if (cur.empty()) {
		return 0;
	}

	if (pos == (int)cur.size()) {
		int ret = 0;
		if (mas[t].end == false) {
			mas[t].end = true;
			mas[t].cnt++;
			ret = 1;
		}

		if (mas[t].cnt >= 2) {
			mas[t].fl = false;
		}

		return ret;
	}

	int c = cur[pos] - 'a';

	if (mas[t].ed[c] == -1) {
		mas[t].ed[c] = my_new();
	}

	int ret = add(mas[t].ed[c], pos + 1);
	mas[t].cnt += ret;

	if (mas[t].cnt >= 2) {
		mas[t].fl = false;
	}

	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ans = 0;

	int t = my_new();
	mas[t].fl = false;

	bool fir = true;

	while (getline(cin, s)) {
		int len = (int)s.size();
		int now = t;
		int pos = -1;

		if (fir) {
			fir = false;
		}
		else {
			ans++;
		}
		
		for (int i = 0; i < len; i++) {
			if ('a' <= s[i] && s[i] <= 'z') {
				int c = s[i] - 'a';
				cur.push_back(s[i]);
				ans++;

				if (now == -1) {
					continue;
				}

				if (mas[now].fl && pos == -1) {
					pos = i;
				}

				if (mas[now].ed[c] != -1) {
					now = mas[now].ed[c];
				}
				else {
					now = -1;
				}

				if (now == -1) {
					continue;
				}

				int num = 0;

				for (int j = 0; j < 26; j++) {
					if (mas[now].ed[j] != -1) {
						num++;
					}
				}

				if (num == 0 && pos != -1) {
					ans -= i - pos + 1;
					ans++;
				}
			}
			else {
				ans++;
				pos = -1;
				now = t;
				add(t, 0);
				cur.clear();
			}
		}

		if (!cur.empty()) {
			add(t, 0);
		}

		cur.clear();
	}

	cout << ans + 1 << endl;

	//system("pause");
}