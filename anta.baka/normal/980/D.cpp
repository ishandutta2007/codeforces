#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	map<vector<int>, int> re;
	int ren = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
		vector<int> d;
		if(x < 0) d.push_back(1), x = -x;
		else d.push_back(0);
		for(int j = 2; j * j <= x; j++)
			while(x % j == 0) {
				if(!d.empty() && d.back() == j) d.pop_back();
				else d.push_back(j);
				x /= j;
			}
		if(x != 1) d.push_back(x);
		if(!re.count(d)) re[d] = ren++;
		b[i] = re[d];
	}
	vector<int> ans(n, 0);
	for(int i = 0; i < n; i++) {
		vector<int> is(ren, 0);
		int cur = 0;
		for(int j = i; j < n; j++) {
			if(!is[b[j]]) {
				is[b[j]] = 1;
				if(a[j]) cur++;
			}
			ans[max(0, cur - 1)]++;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}