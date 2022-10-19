#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];
vector <string> v;
bool has[30];
vector <pii> E[30];
int pos[30];
bool bio[30];
string comp;

void bye() {
	puts("NO");
	exit(0);
}

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s);
		bool bio[30] = {0};
		for (int j = 0; s[j]; j++)
			if (bio[s[j] - 'a']) 
				bye();
			else
				bio[s[j] - 'a'] = true;
		v.push_back(s);
	}
}

void add_edge(int x, int y) {
	E[x].push_back({y, +1});
	E[y].push_back({x, -1});
}

void build(string t) {
	for (int i = 0; i < t.size(); i++)
		has[t[i] - 'a'] = true;
	for (int i = 1; i < t.size(); i++)
		add_edge(t[i - 1] - 'a', t[i] - 'a');
}

void dfs(int x, int y) {
	if (bio[x]) {
		if (pos[x] != y)
			bye();
		return;
	}
	bio[x] = true;
	pos[x] = y;
	comp += 'a' + x;
	for (auto it : E[x])
		dfs(it.first, y + it.second); 
}

bool cmp(char a, char b) {
	return pos[a - 'a'] < pos[b - 'a'];
}

void solve() {
	for (auto it : v)
		build(it);
	
	vector <string> sol;
	for (int i = 0; i < 26; i++)
		if (has[i] && !bio[i]) {
			comp.clear();
			dfs(i, 0);
			sort(comp.begin(), comp.end(), cmp);
			for (int j = 1; j < comp.size(); j++)
				if (pos[comp[j] - 'a'] == pos[comp[j - 1] - 'a'])
					bye();
			sol.push_back(comp);
		}
	
	sort(sol.begin(), sol.end());
	for (auto it : sol)
		printf("%s", it.c_str());
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}