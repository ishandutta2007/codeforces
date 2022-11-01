#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		vector<int> c(26, 0);
		for(char x : a[i])
			if(++c[x - 'a'] == 2)
				return cout << "NO", 0;
	}
	for(int ch = 0; ch < 26; ch++) {
		vector<int> p(26, INT_MAX);
		p[ch] = 0;
		vector<bool> del(a.size(), false);
		bool any = false;
		for(int i = 0; i < a.size(); i++)
			for(int j = 0; j < a[i].size(); j++)
				if(a[i][j] - 'a' == ch) {
					del[i] = any = true;
					for(int k = 1; k <= j; k++) {
						if(p[a[i][j - k] - 'a'] != INT_MAX && p[a[i][j - k] - 'a'] != -k) return cout << "NO", 0;
						else p[a[i][j - k] - 'a'] = -k;
					}
					for(int k = 1; k <= a[i].size() - j - 1; k++) {
						if(p[a[i][j + k] - 'a'] != INT_MAX && p[a[i][j + k] - 'a'] != k) return cout << "NO", 0;
						else p[a[i][j + k] - 'a'] = k;
					}
					break;
				}
		if(!any) continue;
		vector<string> aa;
		for(int i = 0; i < del.size(); i++)
			if(!del[i])
				aa.push_back(a[i]);
		vector<pair<int, int>> vec;
		for(int i = 0; i < 26; i++)
			if(p[i] != INT_MAX)
				vec.push_back({p[i], i});
		sort(vec.begin(), vec.end());
		for(int i = 1; i < vec.size(); i++)
			if(vec[i - 1].first == vec[i].first)
				return cout << "NO", 0;
		string s;
		for(pair<int, int> z : vec)
			s.push_back(char('a' + z.second));
		aa.push_back(s);
		a = aa;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++) cout << a[i];
}