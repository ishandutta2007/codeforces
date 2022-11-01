#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 100 * 1000 + 5;
int n;
long long k;

int a[N];
int seg1[N * 4];
int seg2[N * 4];
vector <int> vec;

void comp() {
	for (int i = 0; i < n; i++) {
		vec.push_back(a[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
	}
}
void update1(int p, int x, int id = 1, int s = 0, int e = n) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg1[id] += x;
		return;
	}
	int md = (s + e) / 2;
	update1(p, x, id * 2, s, md);
	update1(p, x, id * 2 + 1, md, e);
	seg1[id] = seg1[id * 2] + seg1[id * 2 + 1];
}
int get1(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg1[id];
	}
	int md = (s + e) / 2, ans = 0;
	ans += get1(l, r, id * 2, s, md);
	ans += get1(l, r, id * 2 + 1, md, e);
	return ans;
}
void update2(int p, int x, int id = 1, int s = 0, int e = n) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg2[id] += x;
		return;
	}
	int md = (s + e) / 2;
	update2(p, x, id * 2, s, md);
	update2(p, x, id * 2 + 1, md, e);
	seg2[id] = seg2[id * 2] + seg2[id * 2 + 1];
}
int get2(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg2[id];
	}
	int md = (s + e) / 2, ans = 0;
	ans += get2(l, r, id * 2, s, md);
	ans += get2(l, r, id * 2 + 1, md, e);
	return ans;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	comp();
	long long ans = 0, cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += get2(a[i] + 1, n + 1);
		update2(a[i], 1);
		//cout << "58 " << i << " " << a[i] << " " << get2(0, n + 1) << endl;
	}
	//cout << cnt << endl;
	int r = 1;
	
	for (int i = 0; i < n; i++) {
		cnt += get1(a[i] + 1, n + 1);
		cnt += get2(0, a[i]);
		update1(a[i], 1);
		if (i == 0 && r == 1 && cnt <= k) {
			cout << 1ll * n * (n - 1) / 2;
			return 0;
		}
		//cout << "73 " << i << " " << r << " " << cnt << endl;
		while (cnt > k && r < n) {
			cnt -= get1(a[r] + 1, n + 1);
			cnt -= get2(0, a[r]);
			update2(a[r], -1);
			r++;
		}
		if (r == n) {
			break;
		}
		ans += n - r;
	}
	cout << ans << endl;
	return 0;
}