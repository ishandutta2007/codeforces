#include <bits/stdc++.h>

using namespace std;

int n, k;
int sz = 1;
vector<map<int, int>> go(1);
vector<bool> win, loose;

void dfs(int v) {
	win[v] = false;
	loose[v] = false;
	if(go[v].empty()) {
		loose[v] = true;
		return;
	}
	for(int c = 0; c < 26; c++) {
		if(go[v].count(c) == 0)
			continue;
		int to = go[v][c];
		dfs(to);
		if(win[to] == false)
			win[v] = true;
		if(loose[to] == false)
			loose[v] = true;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int v = 0;
		for(char ch : s) {
			if(go[v].count(ch - 'a') == 0) {
				go[v][ch - 'a'] = sz++;
				go.push_back(map<int, int>());
			}
			v = go[v][ch - 'a'];
		}
	}
	win.resize(sz);
	loose.resize(sz);
	dfs(0);
	if(win[0] == false) {
		cout << "Second";
		return 0;
	}
	if(loose[0]) {
		cout << "First";
		return 0;
	}
	if(k & 1) {
		cout << "First";
		return 0;
	}
	cout << "Second";
}