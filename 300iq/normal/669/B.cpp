#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	set <pair <int, int> > moves;
	string s;
	cin >> s;
	vector <int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	int j = 0;
	for (int it = 0; ; it++) {
		if (s[j] == '>') {
			if (j + d[j] >= n) {
				cout << "FINITE" << endl;
				return 0;;
			}
			if (moves.find(make_pair(j, 0)) != moves.end()) {
				cout << "INFINITE" << endl;
				return 0;
			} else {
				moves.insert(make_pair(j, 0));
			}
			j += d[j];
		} else {
			if (j - d[j] < 0) {
				cout << "FINITE" << endl;
				return 0;
			}
			if (moves.find(make_pair(j, 1)) != moves.end()) {
				cout << "INFINITE" << endl;
				return 0;
			} else {
				moves.insert(make_pair(j, 1));
			}
			j -= d[j];
		}
	}
}