#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5, INF = 1e9;

int check(int a, int b) {
	vector<int> va, vb;
	while(a) { va.push_back(a % 10); a /= 10; }
	while(b) { vb.push_back(b % 10); b /= 10; }
	int ret = sz(vb) - sz(va);
	while(sz(va) && sz(vb)) {
		if(va.back() == vb.back()) va.pop_back();
		vb.pop_back();
	}
	return (!sz(va) ? ret : INF);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = INF;
	for(int i = 1; i * i <= n; i++) ans = min(ans, check(i * i, n));
	cout << (ans == INF ? -1 : ans);
}