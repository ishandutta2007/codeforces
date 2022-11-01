#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 205;

bool mark[N];
vector <string> adj[N];
map <string, int> match;
string mt[N];

int get(int x, int y) {
	return (x >> y) & 1;
}

bool dfs(int v) {
	mark[v] = true;
	for (auto s : adj[v]) {
		if (!match[s] || (!mark[match[s]] && dfs(match[s]))) {
			match[s] = v;
			mt[v] = s;
			return true;
		}
	}
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int mask = 1; mask < (1 << s.size()); mask++) {
			string t;
			if (__builtin_popcount(mask) <= 4) {
				for (int j = 0; j < s.size(); j++) {
					if (get(mask, j)) {
						t += s[j];
					}
				}
				adj[i].push_back(t);
			}
		}
	}
	while (true) {
		bool b = false;
		fill(mark, mark + n + 1, false);
		for (int i = 1; i <= n; i++) {
			if (!mark[i] && mt[i].size() == 0) {
				if (dfs(i))
					b = true;
			}
		}
	//	cout << 41 << endl;
		if (!b) {
			break;
		}
	}
	bool b = true;
	for (int i = 1; i <= n; i++) {
		if (mt[i].size() == 0) {
			b = false;
		}
	}
	if (b) {
		for (int i = 1; i <= n; i++) {
			cout << mt[i] << endl;
		}
	}
	else {
		cout << -1;
	}
	return 0;
}