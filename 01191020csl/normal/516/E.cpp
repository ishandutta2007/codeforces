#include<bits/stdc++.h>
#define pr pair<int, bool>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void exgcd(int a, int b, long long &x, long long &y) {
	if (!b) {x = 1, y = 0;return;}
	exgcd(b, a % b, y, x);
	y -= x*(a/b);
}
int inv(int a, int p) {
	long long x, y;
	exgcd(a, p, x, y);
	return (x%p+p)%p;
}
vector<int> b0[100001], g0[100001];
int main() {
	int n, m;
	cin >> n >> m;
	int d = gcd(n, m), m0 = inv(m/d, n/d), n0 = inv(n/d, m/d);
	int b, g;
	cin >> b;
	for (int i = 1; i <= b; i++) {
		int x;
		cin >> x;
		b0[x%d].push_back(1ll*m0*(x/d)%(n/d));
	}
	cin >> g;
	for (int i = 1; i <= g; i++) {
		int x;
		cin >> x;
		g0[x%d].push_back(1ll*n0*(x/d)%(m/d));
	}
	if (b + g < d) {
		puts("-1");
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i < d; i++) {
		if (b0[i].empty() && g0[i].empty()) {
			puts("-1");
			return 0;
		}
		sort(b0[i].begin(), b0[i].end()), sort(g0[i].begin(), g0[i].end());
		map<int, pr> mp;
		for (int j : b0[i]) mp[j] = make_pair(1ll*j*(m/d)%(n/d)*d+i, 1);
		for (int j : g0[i]) {
			int k = 1ll*j*(n/d)%(m/d), num = 1ll*k*m0%(n/d);
			if (mp.find(num) != mp.end()) mp[num].first = min(mp[num].first, k*d+i);
			else mp[num] = make_pair(k*d+i, 0);
		}
		int ed = mp.begin()->first - 1 + (n/d);
		long long now = -1;
		for (map<int, pr>::iterator j = mp.begin(); j != mp.end(); j++) {
			int nxt = j == prev(mp.end()) ? ed : next(j)->first-1;
			if (nxt == j->first && j->second.second) continue;
			now = max(now, j->second.first+1ll*m*(nxt-j->first));
		}
		ans = max(ans, now), mp.clear();
		for (int j : g0[i]) mp[j] = make_pair(1ll*j*(n/d)%(m/d)*d+i, 1);
		for (int j : b0[i]) {
			int k = 1ll*j*(m/d)%(n/d), num = 1ll*k*n0%(m/d);
			if (mp.find(num) != mp.end()) mp[num].first = min(mp[num].first, k*d+i);
			else mp[num] = make_pair(k*d+i, 0);
		}
		ed = mp.begin()->first - 1 + (m/d);
		now = -1;
		for (map<int, pr>::iterator j = mp.begin(); j != mp.end(); j++) {
			int nxt = j == prev(mp.end()) ? ed : next(j)->first-1;
			if (nxt == j->first && j->second.second) continue;
			now = max(now, j->second.first+1ll*n*(nxt-j->first));
		}
		ans = max(ans, now);
	}
	cout << ans << endl;
}