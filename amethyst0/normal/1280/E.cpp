//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)5e6 + 10;
char s[maxn];
int n;
int m;

struct vt {
	int x;
	vector <int> g;

	vt() : x(-1) {
		g.clear();
	}
};

vt mas[maxn];
int posit = 0;

int my_new() {
	mas[posit] = vt();
	return posit++;
}

void skip(int &pos) {
	if (pos == n) {
		throw 1;
	}
	while (s[pos] == ' ') {
		if (pos == n) {
			throw 1;
		}
		pos++;
	}
}

int go(int &pos) {
	skip(pos);

	if (s[pos] == '(') {
		pos++;
		int tp = -1;
		vector <int> g;

		while (true) {
			skip(pos);
			if (s[pos] == ')') {
				break;
			}

			if (s[pos] == 'S') {
				tp = 0;
			}
			else if (s[pos] == 'P') {
				tp = 1;
			}
			else {
				g.push_back(go(pos));
			}

			pos++;
		}

		int ans = my_new();

		if (tp == 0) {
			for (int it : g) {
				if (mas[it].x != -1) {
					mas[ans].x = mas[it].x;
					break;
				}
			}

			if (mas[ans].x != -1) {
				return ans;
			}

			for (int it : g) {
				if (mas[ans].g.empty() || mas[ans].g.size() > mas[it].g.size()) {
					ans = it;
				}
			}

			return ans;
		}
		else {
			for (int it : g) {
				if (mas[it].x != -1) {
					mas[ans].g.push_back(mas[it].x);
				}
				else {
					if (mas[ans].g.size() < mas[it].g.size()) {
						swap(ans, it);
					}
					for (int y : mas[it].g) {
						mas[ans].g.push_back(y);
					}
				}
			}

			return ans;
		}
	}
	else if (s[pos] == '*') {
		int cur = m++;
		int ans = my_new();
		mas[ans].x = cur;
		return ans;
	}
	else {
		throw 1;
	}
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		posit = 0;
		int r;
		scanf("%d ", &r);
		gets(s);
		n = strlen(s);

		m = 0;

		int pos = 0;
		int res = go(pos);

		printf("REVOLTING");
		vector <ll> ans(m, 0);

		if (mas[res].x != -1) {
			ans[mas[res].x] = r;
		}
		else {
			for (int x : mas[res].g) {
				ans[x] = (ll)r * mas[res].g.size();
			}
		}

		for (int i = 0; i < m; i++) {
			printf(" %lld", ans[i]);
		}

		printf("\n");
	}

	//system("pause");
}