#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5, C = 273;

vector <pair <int, int> > adj[C][C];
int indeg[C][C];
string s[N];
string ans;

void ts(int x, int y) {
//	cout << "73 " << x << " " << y << endl;
	while (adj[x][y].size()) {
		pair <int, int> p = adj[x][y].back();
		adj[x][y].pop_back();
		ts(p.first, p.second);
	//	ans.push_back(y);
	}
	ans.push_back(y);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		adj[s[i][0]][s[i][1]].push_back({s[i][1], s[i][2]});
		indeg[s[i][1]][s[i][2]]++;
	}
	int s1 = s[0][0], s2 = s[0][1];
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (adj[s[i][0]][s[i][1]].size() > indeg[s[i][0]][s[i][1]]) {
			s1 = s[i][0];
			s2 = s[i][1];
		}
		if (abs((int) adj[s[i][0]][s[i][1]].size() - indeg[s[i][0]][s[i][1]]) > 1) {
			cout << "NO";
			return 0;
		}
		if (abs((int) adj[s[i][1]][s[i][2]].size() - indeg[s[i][1]][s[i][2]]) > 1) {
			cout << "NO";
			return 0;
		}
	//	if (adj[s[i][0]][s[i][1]].size() != indeg[s[i][0]][s[i][1]]) {
	//		x++;
	//	}
	//	if (adj[s[i][1]][s[i][2]].size() != indeg[s[i][1]][s[i][2]]) {
	//		x++;
	//	}
	}
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (adj[i][j].size() != indeg[i][j]) {
				x++;
			}
		}
	}
//	cout << s1 << " " << s2 << endl;
	ts(s1, s2);
//	cout << ans << endl;
	reverse(ans.begin(), ans.end());
	if (ans.size() == n + 1 && x <= 2)
		cout << "YES" << endl << (char) s1 << ans;
	else
		cout << "NO";
	return 0;
}