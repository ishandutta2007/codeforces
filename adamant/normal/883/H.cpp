#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 2e5 + 42;
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> cnt;
	for(auto it:  s) {
		cnt[it]++;
	}
	vector<string> ans;
	string free;
	for(auto &it: cnt) {
		if(it.second % 2) {
			ans.push_back(string(1, it.first));
			it.second--;
		}
	}
	int res = max<int>(1, ans.size());
	while(n % res != 0 || ((n / res) % 2 == 0 && ans.size() > 0)) {
		res++;
	}
	int cur = 0;
	int sz = n / res;
	for(auto &it: cnt) {
		while(it.second) {
			if((int)ans.size() < res) {
				if(sz % 2) {
					ans.push_back(string(1, it.first));
					ans.push_back(string(1, it.first));
				} else {
					ans.push_back(string(2, it.first));
				}
				it.second -= 2;
			} else {
				while((int)ans[cur].size() == sz) {
					cur++;
				}
				int t = min<int>(it.second, sz - ans[cur].size());
				ans[cur] = string(t / 2, it.first) + ans[cur] + string(t / 2, it.first);
				it.second -= t;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto it: ans) {
		cout << it << ' ';
	}
	return 0;
}