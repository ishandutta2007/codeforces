#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

const int N = 200 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;
int q;

int a[N];
int b[N];
int c[N];
int d[N];
vector <int> vec;
set <pair <int, int> > fen[N];



void comp() {
	for (int i = 0; i < q; i++) {
		vec.push_back(b[i]);
	//	cout << b[i] << endl;
	}
	sort(vec.begin(), vec.end());
//	cout << vec.size() << endl;
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
//	for (int i = 0; i < q; i++) {
//		d[i] = 
//	}
}
void update(int p, int val, int x, int y) {
	for (p; p <= vec.size(); p += p & -p) {
		if (val == 1) {
			fen[p].insert({x, y});
		}
		else {
			fen[p].erase({x, y});
		}		
	}
}

pair <int, int> get(int p, int x, int y) {
//	cout << "74 " << id << " " << s << " " << e << endl;
	pair <int, int> ans = {inf , inf};
	for (p; p > 0; p -= p & -p) {
		ans = min(ans, *fen[p].upper_bound({x + 1, 0}));
	}
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s >> a[i] >> b[i];
	/*	if (s.size() == 3) {
			a[i].first = 1;
		}
		if (s.size() == 6) {
			a[i].first = 2;
		}
		if (s.size() == 4) {
			a[i].first = 3;
		}*/
		c[i] = s.size();
	}
	comp();
//	cout << 31 << " " << vec.size() << endl;
	for (int i = 0; i <= vec.size(); i++) {
		fen[i].insert({inf, inf});
	}
	for (int i = 0; i < q; i++) {
		int p = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
		p = vec.size() - p;
		if (c[i] == 3) {
			update(p, 1, a[i], b[i]);
		}
		if (c[i] == 6) {
			update(p, -1, a[i], b[i]);
		}
		if (c[i] == 4) {
			pair <int, int> ans = get(p - 1, a[i], b[i]);
			if (ans.first == inf) {
				cout << -1 << endl;
			}
			else {
				cout << ans.first << " " << ans.second << endl;
			}
		}
	//	cout << "48 " << i << " " << p << endl;
	}
	return 0;
}