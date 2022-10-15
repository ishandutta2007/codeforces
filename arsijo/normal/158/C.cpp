/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	vector<string> way;
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s[0] == 'p') {
			cout << '/';
			for (int j = 0; j < way.size(); j++) {
				cout << way[j] << '/';
			}
			cout << endl;
		} else {
			string st = "";
			if(s[3] == '/')
				way.clear();
			for (int j = 3; j < s.length(); j++) {
				if (s[j] == '/') {
					if (st == "..") {
						way.erase(way.end() - 1);
					} else if (st != "") {
						way.insert(way.end(), st);
					}
					st = "";
				} else {
					st += s[j];
				}
			}
			if (st == "..") {
				way.erase(way.end() - 1);
			} else if (st != "") {
				way.insert(way.end(), st);
			}
		}
	}
}