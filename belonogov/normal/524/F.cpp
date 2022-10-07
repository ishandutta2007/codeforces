#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = 1 << 21;
//const int maxn = 1000;
const int inf = 1e9;

int n;
char s[maxn];
int p[maxn], pn[maxn], cnt[maxn], c[maxn], cn[maxn];
int balance[maxn], mnbalance[maxn];

void getsuffarray() {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[s[i]]++;
	for (int i = 1; i < 255; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		p[--cnt[s[i]]] = i;
	}

	int cl = 1;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++) {
		cl += s[p[i]] != s[p[i - 1]];
		c[p[i]] = cl - 1;
	}

	for (int len = 1; len < n; len <<= 1) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			cnt[c[i]]++;
			pn[i] = (p[i] - len + n) % n;
		}
		for (int i = 1; i < cl; i++) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

		cl = 1;
		cn[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			cl += c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n];
			cn[p[i]] = cl - 1;
		}
		for (int i = 0; i < n; i++) {
			c[i] = cn[i];
		}
	}
	//for (int i = 0; i < n; i++) cout << p[i] << endl;
}

string solve() {
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		s[i + n] = s[i];
	}
	s[n + n] = 0;
	getsuffarray();
	memset(balance, 0, sizeof(balance));
	for (int i = 0; i < 2 * n; i++) {
		balance[i] = i ? balance[i - 1] : 0;
		balance[i] += (s[i] == '(') - (s[i] == ')');
	}
	memset(mnbalance, 63, sizeof(mnbalance));
		
	for (int i = n - 1; i >= 0; i--) {
		mnbalance[i] = i < n - 1 ? mnbalance[i + 1] : inf;
		mnbalance[i] = min(mnbalance[i], balance[i]);
	}
	for (int i = n; i < 2 * n; i++) {
		mnbalance[i] = i > n ? mnbalance[i - 1] : inf;
		mnbalance[i] = min(mnbalance[i], balance[i]);
	}

	int sumbalance = balance[n - 1];
	int start = -1;
	for (int i = 0; i < n; i++) {
		int cur = p[i];
		int minbalance = inf;
		minbalance = min(minbalance, mnbalance[cur]);
		if (cur) minbalance = min(minbalance, mnbalance[cur + n - 1]);

		if (minbalance + max(-sumbalance, 0) - (cur ? balance[cur - 1] : 0) >= 0) {
			start = cur;
			break;
		}
	}
	assert(start != -1);
	string res = "";
	if (sumbalance <= 0) for (int i = 0; i < -sumbalance; i++) res += "(";
	for (int i = 0; i < n; i++) res += s[start + i];
	if (sumbalance > 0) for (int i = 0; i < sumbalance; i++) res += ")";
	s[n] = 0;
	return res;
}

string slowsolve() {
	n = strlen(s);
	string best = "";
	for (int i = 0; i < 3 * n; i++) best += ")";
	for (int i = 0; i < n; i++) {
		int balance = 0;
		int minbalance = 0;
		string cur = "";
		for (int j = 0; j < n; j++) {
			cur += s[(i + j) % n];
			if (s[(i + j) % n] == '(') balance++;
			else balance--;
			minbalance = min(minbalance, balance);
		}
		for (int i = 0; i < -minbalance; i++) cur = "(" + cur;
		balance += -minbalance;
		for (int i = 0; i < balance; i++) cur = cur + ")";
		if (cur.length() < best.length() || cur.length() == best.length() && cur < best) best = cur;
	}
	return best;
}

void gen() {
	n = rand() % 300 + 1;
	for (int i = 0; i < n; i++) s[i] = "()"[rand() % 2];
	s[n] = 0;
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0;; it++) {
		cerr << it << endl;
		gen();
		string ans1 = solve();
		string ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << s << endl;
			solve();
			exit(0);
		}
	}
}

int main() {
/*#ifndef _ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif*/
	
	stress(0);

	while (scanf("%s\n", s) == 1) {
		printf("%s\n", solve().c_str());
	}

	return 0;
}