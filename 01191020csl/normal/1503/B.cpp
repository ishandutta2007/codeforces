#include<bits/stdc++.h>
using namespace std;
int solveend(vector<pair<int, int> > v, int typ) {
	while (v.size()) {
		pair<int, int> p;
		p = *(v.end()-1), v.pop_back();
		int c = 1, a;
		cin >> a;
		while (c == a || c == typ) ++c;
		cout << c << ' ' << p.first << ' ' << p.second << endl;
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > v1, v2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if ((i+j) & 1) v1.push_back(make_pair(i, j));
			else v2.push_back(make_pair(i, j));
	for (int t = 1; t <= n * n; t++) {
		int a, c;
		pair<int, int> p;
		cin >> a;
		if (a == 1) c = 2, p = *(v2.end()-1), v2.pop_back();
		else c = 1, p = *(v1.end()-1), v1.pop_back();
		cout << c << ' ' << p.first << ' ' << p.second << endl;
		if (v1.empty()) return solveend(v2, 1);
		if (v2.empty()) return solveend(v1, 2);
	}
}