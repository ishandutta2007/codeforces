#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 105, A = 26;

pair <string, int> s[N];
bool mark[N][N];
bool c[A][A];
vector <pair <int, int> > v;

bool cmp(pair <string, int> p1, pair <string, int> p2) {
	string s1 = p1.first, s2 = p2.first;
	if (s1.size() == 0 || s2.size() == 0)
		return false;
	for (int i = 0; i < s1.size() && i < s2.size(); i++) {
		int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
		if (c[c1][c2])
			return true;
		if (c[c2][c1])
			return false;
	}
	if (s1.size() < s2.size())
		return true;
	if (p1.second < p2.second)
		return true;
	return false;
}
int main() {
	bool b = true;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].first;
		s[i].second = i;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (!mark[i][j] && k < s[i].first.size() && k < s[j].first.size()) {
					if (s[i].first[k] != s[j].first[k]) {
						c[s[j].first[k] - 'a'][s[i].first[k] - 'a'] = true;
						mark[i][j] = true;
						mark[j][i] = true;
					}
				}
			}
		}
	}
	for (int ii = 0; ii < A; ii++) {
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < A; j++) {
				for (int k = 0; k < A; k++) {
					if (c[i][k] && c[k][j]) {
						c[i][j] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (c[i][j] && c[j][i]) {
			//	cout << "Impossible" << endl;
			//	return 0;
				b = false;
			}
		}
	}
//	cout << 48 << endl;
	sort(s + 1, s + n + 1, cmp);
//	if (n == 100) {
//		cout << 58 << endl;
//		return 0;
//	}
	for (int i = 1; i <= n; i++) {
	//	cout << s[i].first << endl;
		if (s[i].second != i) {
		//	cout << "Impossible" << endl;
		//	return 0;
			b = false;
		}
	}
	for (int i = 0; i < A; i++) {
		int x = 0;
		for (int j = 0; j < A; j++) {
			if (c[j][i])
				x++;
		}
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());
	if (b) {
		for (int i = 0; i < A; i++) {
			cout << (char) ('a' + v[i].second);
 		}
	}
	else {
		cout << "Impossible" << endl;
	}

//	cout << "dsd" << endl;
	return 0;
}