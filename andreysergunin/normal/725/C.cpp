#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	
	string s;
	cin >> s;
	int n = 27;

	vector<int> l(26, -1), r(26, -1);
	for (int i = 0; i < n; ++i) {
		r[s[i] - 'A'] = i;

		if (l[s[i] - 'A'] == -1)
			l[s[i] - 'A'] = i;
		
	}



	for (int i = 0; i < 26; ++i) {
		if (r[i] != -1 && r[i] - l[i] > 1) {
			
			int len = (r[i] - l[i] + 1) / 2;
			s = s.substr(0, r[i]) + s.substr(r[i] + 1, 26 - r[i]);

			string res = s;

			for (int j = 0; j < 26; ++j)
				res[j] = s[(j + l[i] + len + 13) % 26];

			for (int j = 0; j < 13; ++j)
				cout << (char)res[j];
			cout << endl;
			for (int j = 0; j < 13; ++j)
				cout << (char)res[25 - j];
			cout << endl;
			return 0;
		}
	}

	cout << "Impossible" << endl;
	return 0;
}