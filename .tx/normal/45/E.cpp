#pragma comment(linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define input_file "input.txt"
#define output_file "output.txt"

#include <cassert>

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long int64;
const int INF = (int)2e9;
const int64 INF64 = (int64)1e18;
const double EPS = 1e-6;
const double PI = 3.1415926545;

typedef struct {
	int x, y;
} point;

#define sqr(x) ((x)*(x))
#define dist(a, b) sqrt((double)sqr(a.x - b.x) +sqr(a.y - b.y))
#define dist2(x1, y1, x2, y2) sqrt((double)(sqr(x1 - x2)) +sqr(y1 - y2))
#define bound(x, y, n, m) ((x) >= 0 && (y) >= 0 && (x) < (n) && (y) < (m))
#define all(c) c.begin(), c.end()

/* my functions ans structs */
typedef pair< string, string> pss;

bool cmp(pss &a, pss &b) {
	return a.first + a.second < b.first + b.second;
}


int ff(string &s) {
	return s[0] - 'A';
}

string nexts() {
	string s = "";
	char c = getchar();
	while (!(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')) c = getchar();
	while (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
		s += c;
		c = getchar();
	}
	return s;
}

/* main function */
int main() {
#ifndef ONLINE_JUDGE
	freopen(input_file, "r", stdin);
	freopen(output_file, "w", stdout);
#endif
	/* code begin */

	int n;
	cin >> n;
	vector<string> a(n);
	vector<string> b(n);
	vector<bool> ua(n, false);
	vector<bool> ub(n, false);

	vector<int> ka(26, 0), kb(26, 0), kmin(26), kfam(26, 0);



	string s;
	
	for (int i = 0; i < n; i++) {
		s = nexts();
		a[i] = s;
		ka[ff(s)]++;
	}

	for (int i = 0; i < n; i++) {
		s = nexts();
		b[i] = s;
		kb[ff(s)]++;
	}

	for (int i = 0; i < 26; i++) {
		kmin[i] = min(ka[i], kb[i]);
		kfam[i] = kb[i] - kmin[i];
	}

	sort(all(a));
	sort(all(b));

	int pa;
	int pb;
	pss t;
	vector< pss > ans;
	int m;
	
	for (int f = 0; f < 26; f++) {
		if (ka[f] == 0)
			continue;
		m = kmin[f];

		vector<string> temp;
		
		pb = 0;
		for (int i = 0; i < m; i++) {
			while (ub[pb] || ff(b[pb]) != f)
				pb++;
			temp.push_back(b[pb]);
			ub[pb] = true;
		}

		int r = ka[f] - m;
		pb = 0;
		for (int i = 0; i < r; i++) {
			while (ub[pb] || kfam[ff(b[pb])] <= 0)
				pb++;
			temp.push_back(b[pb]);
			ub[pb] = true;
			kfam[ff(b[pb])]--;
		}

		sort(all(temp));
		pa = 0;
		for (int i = 0; i < ka[f]; i++) {
			while (ua[pa] || ff(a[pa]) != f)
				pa++;
			ua[pa] = true;
			t.first = a[pa];
			t.second = temp[i];
			ans.push_back(t);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		cout << ans[i].first << " " << ans[i].second << ", ";
	}
	cout << ans[n - 1].first << " " << ans[n - 1].second;

	/* code end */
	return 0;
}//ruxohx