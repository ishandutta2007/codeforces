#include <iostream>
#include <algorithm>
using namespace std;


const int N = 200 * 1000 + 5;
const long long inf = 1ll * N * 1000 * 1000 * 1000;
int n, m;

int a[N];
long long ps[N];
pair < pair <int, int>, int> b[N];
long long seg[N * 4];
long long seg2[N * 4];
pair <int, int> kft[N * 4];
long long dp[N];

void update(int l, int r, long long p, int id = 1, int s = 0, int e = n + 1) {
//	cout << "47 " << id << " " << s << " " << e << endl;
	kft[id] = {s, e};
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		seg[id] += p;
		seg2[id] += p;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, p, id * 2, s, md);
	update(l, r, p, id * 2 + 1, md, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]) + seg2[id];
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first.second >> b[i].first.first >> b[i].second;
	}
	sort(b, b + m);
	int t = 0;
//	build();
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		update(0, i, -a[i]);
		while (t < m && b[t].first.first <= i) {
		//	cout << "8 " << t << endl;
			update(0, b[t].first.second, b[t].second);
			t++;
		}


		ans = max(ans, seg[1]);
		update(i, i + 1, ans);
		ans = max(ans, seg[1]);
	//	ans = max(ans, dp[i]);
	//	for (int j = 1; j < 20; j++) {
	//		cout << "37 " << j << " " << kft[j].first << " " << kft[j].second << " " << seg[j] << " " << seg2[j] << " " << endl;
	//	}
	//	cout << "73 " << i << " " << seg[1] << endl;	
	
	}
	
	cout << ans;
	return 0;
}