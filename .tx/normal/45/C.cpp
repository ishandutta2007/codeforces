#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> mn, all;
	map<int, set< pair<int, int> > > ma;
	int n, i, g, x, y;
	cin >> n;
	string st;
	cin >> st;
	vector<int> a(n), b(n);
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector< pair<int, int> > c;
	for (i = 0; i < n; i++) {
		all.insert(i);
		b[i] = st[i] == 'B' ? 1 : 0;
		if (i && b[i] + b[i-1] == 1) {
			x = abs(a[i] - a[i-1]);
			mn.insert(x);
			ma[x].insert(make_pair(i-1, i));
		}
	}
	int m, v;
	pair<int, int> t;
	set<int>::iterator i1, i2, i3, i4, sr;
	while (!mn.empty() && all.size() > 1) {
		m = *mn.begin();
		t = *ma[m].begin();
		ma[m].erase(t);
		x = t.first;
		y = t.second;
		sr = all.end();
		sr--;
		i1 = i3 = all.find(x);
		i3--;
		i2 = i4 = all.find(y);
		i4++;
		if (i1 != all.begin() && i1 != all.end() && i2 != sr && i2 != all.end()/*x > 0 && y < n-1*/ && b[*i3] + b[*i4] == 1) {
			v = abs(a[*i3] - a[*i4]);
			mn.insert(v);
			ma[v].insert(make_pair(*i3, *i4));
		}
		if (b[x] >= 0 && b[y] >= 0) {
			c.push_back(t);
			b[x] = b[y] = -1;
			all.erase(x);
			all.erase(y);
		}
		if (ma[m].empty()) {
			mn.erase(m);
		}
	}
	cout << c.size() << endl;
	for (i = 0; i < c.size(); i++) {
		cout << c[i].first + 1 << " " << c[i].second + 1 << endl;
	}


	return 0;
}//tgemvm