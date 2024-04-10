#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#define sqr(x) ((x) * (x))
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, sum = 0, i, x, y;
	string st;
	cin >> n;
	vector<string> d;
	for (i = 0; i < n; i++) {
		cin >> st;
		d.push_back(st);
		sum += st.size();
	}
	char cc;
	cin >> cc;
	x = 2 * sum / n;
	sort(d.begin(), d.end());
	vector<bool> used(n, false);
	int g;
	string s1, s2;
	vector<string> ans;
	for (i = 0; i < n; i++) {
		if (!used[i]) {
			//cout << d[i];
			y = d[i].size();
			for (g = i + 1; g < n; g++) {
				if (!used[g] && d[g].size() + y == x) {
					//cout << cc << d[g] << endl;
					s1 = d[i] + cc + d[g];
					s2 = d[g] + cc + d[i];
					//cout << min(s1, s2) << endl;
					ans.push_back(min(s1, s2));
					used[g] = true;
					break;
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (i = 0; i < n >> 1; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}//fpaafe