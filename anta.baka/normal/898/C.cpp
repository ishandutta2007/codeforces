#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline bool suff(string a, string b) {
	if(a.size() > b.size()) return false;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	map<string, vector<string>> a;
	for(int i = 0; i < n; i++) {
		string name; cin >> name;
		int m; cin >> m;
		while(m--) {
			string s; cin >> s;
			bool medel = false;
			for(string t : a[name])
				medel |= suff(s, t);
			if(medel) continue;
			if(!a[name].empty()) {
				int sz = a[name].size();
				vector<string> vec;
				for(int j = 0; j < sz; j++)
					if(!suff(a[name][j], s))
						vec.push_back(a[name][j]);
				a[name] = vec;
			}
			a[name].push_back(s);
		}
	}
	cout << a.size() << endl;
	for(auto it = a.begin(); it != a.end(); it++) {
		cout << it->first << ' ' << it->second.size() << ' ';
		for(string s : it->second) cout << s << ' ';
		cout << endl;
	}
}