#include <bits/stdc++.h>
#include <string>
using namespace std;

const int N = 200 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1000 * 1000 + 7;
int n;

int a[N];
string t[5];
long long seg1[N * 4];
long long seg2[N * 4];



void update(int l, int r, int v, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
	//	cout << "73 " << id << " " << s << " " << e << " " << v << endl;
		seg1[id] += v;
		seg2[id] += v;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, v, id * 2, s, md);
	update(l, r, v, id * 2 + 1, md, e);
	seg1[id] = min(seg1[id * 2], seg1[id * 2 + 1]) + seg2[id];
}
long long get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return inf;
	}
	if (l <= s && e <= r) {
		return seg1[id];
	}
	int md = (s + e) / 2;
	long long ans = get(l, r, id * 2, s, md) + seg2[id];
	ans = min(ans, get(l, r, id * 2 + 1, md, e) + seg2[id]);
//	cout << "48 " << id << " " << s << " " << e << " " << ans << endl;
	return ans;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(i, i + 1, a[i]);
	}
//	for (int i = 1; i <= 7; i++) {
	//	cout << i << " " << seg1[i] << " " << seg2[i] << endl;
//	}
	int m;
	cin >> m;
	string ashghal;
	getline(cin, ashghal);
	for (int i = 0; i < m; i++) {
		string s;
		getline(cin, s);
		int k = 0;
		t[0].clear(), t[1].clear(), t[2].clear();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				t[k] += s[i];
			}
			else {
				k++;
			}
		}
	//	cout << t[0] << " " << t[1] << endl;
		int l, r, v;
		l = stoi(t[0]), r = stoi(t[1]);
	//	cout << l << " " << r << endl;
		if (t[2].size()) {
			v = stoi(t[2]);
			if (l <= r) {
				update(l, r + 1, v);
			}
			else {
				update(0, r + 1, v);
				update(l, n, v);
			}
		}
		else {
			long long ans;
			if (l <= r) {
				ans = get(l, r + 1);
			}
			else {
				ans = get(0, r + 1);
				ans = min(ans, get(l, n));
			}
			cout << ans << endl;
		}
	}
	return 0;
}