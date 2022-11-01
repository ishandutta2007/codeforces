#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5;

int n, a, b, ans, cur;
vector<int> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) {
		char ch; cin >> ch;
		if(ch == '*') {
			if(cur) v.push_back(cur);
			cur = 0;
		} else cur++;
	}
	if(cur) v.push_back(cur);
	for(int x : v) {
		int p = (x + 1) / 2, q = x / 2;
		if(a < b) swap(p, q);
		int A = min(a, p), B = min(b, q);
		a -= A; b -= B; ans += A + B;
	}
	cout << ans;
}