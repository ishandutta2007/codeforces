#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define int long long
using namespace std;
 
const int N = 400 * 1000 + 5;
const int SQ = 1000;
int n;
 
int a[N];
int cnt[N];
map <int, int> real;
vector <int> vec;
set <pair <int, int> > s;
vector <pair <int, int> > v;
vector <int> ans[N];
int b[N];
 
void comp() {
	for (int i = 0; i < n; i++) {
		vec.push_back(a[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 0; i < n; i++) {
		int x = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		real[x] = a[i];
		a[i] = x;
		cnt[x]++;
	}
}
 
int32_t main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	comp();
	for (int i = 0; i < vec.size(); i++) {
		s.insert({-cnt[i], i});
	}
//	cout << 41 << endl;
	int m = n;
	while (s.size()) {
		pair <int, int> p = *s.begin();
		int c = p.first, x = p.second;
		if (1ll * c * c > (long long) m) {
			m--;
			s.erase(s.begin());
			cnt[x]--;
			s.insert({-cnt[x], x});
		}
		else {
			break;
		}
	}
	for (auto p : s) {
		int c = p.first, x = p.second;
		for (int i = 1; i <= -c; i++) {
			b[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + b[i];
	}
//	cout << 42 << endl;
	int rad = 1;
	while (1ll * rad * rad <= m) {
		rad++;
	}
	rad--;
	pair <int, int> p = *s.begin();
	int maxc = -p.first;
	int ansfor = maxc;
	for (int j = 1; j <= rad; j++) {
		if (j * (b[j] / j) >= ansfor * (b[ansfor] / ansfor)) {
			ansfor = j;
		}
	}
	int x = ansfor;
	int y = b[x] / ansfor;
	for (auto p : s) {
		for (int i = 0; i < min(-p.first, x); i++) {
			v.push_back(p);
		}
	}
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			ans[i].push_back(0);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < x * y; i++) {
		int c = i % x;
		int d = (c + (i / x)) % y;
		ans[c][d] = v[i].second;
	}
	cout << x * y << '\n';
	cout << x << " " << y << '\n';
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << real[ans[i][j]] << " ";
		}
		cout << '\n';
	}
	return 0;
}