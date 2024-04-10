#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5, A = 1000 * 1000 + 5, SQ = 517;
long long s;

int a[N];
int b[A];
long long ans[N];
pair < pair <int, int>, int> t[N];
bool cmp(pair < pair <int, int>, int> p1, pair < pair <int, int>, int> p2) {
	int l1 = p1.first.first, r1 = p1.first.second, l2 = p2.first.first, r2 = p2.first.second;
	if (l1 / SQ != l2 / SQ) {
		return l1 < l2;
	}
	else {
		return r1 < r2;
	}
}
void add(int x) {
	int y = a[x];
	s -= 1ll * b[y] * b[y] * y;
	b[y]++;
	s += 1ll * b[y] * b[y] * y;;
}
void del(int x) {
	int y = a[x];
	s -= 1ll * b[y] * b[y] * y;
	b[y]--;
	s += 1ll * b[y] * b[y] * y;;
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n + 1; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i].first.first >> t[i].first.second;
		t[i].first.first++;
		t[i].first.second++;
		t[i].second = i;
	}
	sort(t + 1, t + q + 1, cmp);
//	for (int i = 1; i <= q; i++) {
//		cout << t[i].first.first << " " << t[i].first.second << " " << t[i].second << endl;
//	}
	int l = 0, r = 1;
	for (int i = 1; i <= q; i++) {
		int l2 = t[i].first.first, r2 = t[i].first.second;
//		cout << l << " " << r << " " << l2 << " " << r2 << endl;
		while (r2 > r) {
			r++;
			add(r);
		}
		while (l2 < l) {
			l--;
			add(l);
		}
		while (r2 < r) {
			del(r);
			r--;
		}
		while (l2 > l) {
			del(l);
			l++;
		}
		ans[t[i].second] = s;
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}