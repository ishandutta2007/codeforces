#include <bits/stdc++.h>
#define int long long
#define m_p make_pair
using namespace std;

main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s;
	while (cin >> n) {
		cin >> s;
		for (int jump = 1; jump <= n; jump++) {
			for (int start = 0; start < n; start++) {
				int t = 0;
				int cur = start;
				if (s[cur] == '*') {
					t++;
					while (1) {
						if (cur + jump < n && s[cur + jump] == '*') {
							cur += jump;
							t++;
						}
						else {
							break;
						}
					}
				}
				if (t >= 5) {
					cout << "yes";
					return 0;
				}
			}
		}
		cout << "no";
		return 0;
	}

}