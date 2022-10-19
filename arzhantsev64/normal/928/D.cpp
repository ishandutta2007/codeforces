#include <bits/stdc++.h>

using namespace std;

vector<bool> f(1, false);
vector<vector<int>> g(1, vector<int> (26, -1));
vector<int> cnt(1, 0);

void add(const string & s) {
	int v = 0;
	for (int  i = 0; i < s.size(); ++i) {
		int u = g[v][s[i] - 'a'];
		cnt[v]++;
		if (u == -1) {
			f.push_back(false);
			cnt.push_back(0);
			g.push_back(vector<int> (26, -1));
			g[v][s[i] - 'a'] = g.size() - 1;
		}
		v = g[v][s[i] - 'a'];
	}
	cnt[v]++;
	f[v] = true;
}

bool in(const string & s) {
	int v = 0;
	for (int  i = 0; i < s.size(); ++i) {
		v = g[v][s[i] - 'a'];
		if (v == -1)
			return false;
	}
	return f[v];
}

int main() {
	string txt = "";
	string s;
	int ans = 0;
	while(getline(cin, s)) {
		//ans--;
		txt += s + " ";
	}
	//ans++;
	vector<string> words;
	s = "";
	for (auto c : txt)
		if ('a' <= c && c <= 'z')
			s += c;
		else {
			if (s.size() > 0)
				words.push_back(s);
			s = "";
			ans++;
		}
	if (s.size() > 0)
		words.push_back(s);
	set<string> was;
	for (auto w : words) {
		int v = 0;
		string s = "";
		string ss = "";
		for (auto c : w) {
			v = g[v][c - 'a'];
			s += c;
			ss += c;
			if (v == -1) {
				s = "_";
				break;
			}
			if (cnt[v] == 1) {
				while (!f[v])
					for (int i = 0; i < 26; ++i)
						if (g[v][i] != -1) {
							s += ('a' + i);
							v = g[v][i];
						}
				break;
			}
		}
		ans += w.size();
		bool can_use = true;
		for (int i = 0; i < s.size(); ++i)
			if (i >= w.size() || w[i] != s[i]) {
				can_use = false;
				break;
			}
		if (can_use && ss.size() < s.size())
			ans += (int)ss.size() - (int)s.size() + 1;
		if (!in(w))
			add(w);
	}
	cout << ans << endl;
}