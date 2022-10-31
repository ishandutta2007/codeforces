#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
bool f(char a) {
	return a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o';
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	vector<int> res;
	cin >> s;
	int N = s.size();
	int c = 0;
	int b = 0;
	int ca[26];
	for (int i = 0; i < 26; i++) {
		ca[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		if (f(s[i])) {
			c = 0;
			b = 0;
			for (int j = 0; j < 26; j++) {
				ca[j] = 0;
			}
		}
		else {
			c++;
			ca[(int)(s[i] - 'a')]++;
			if (ca[(int)(s[i] - 'a')] == 1) {
				b++;
			}
		}
		if (c >= 3 && (b >= 2)) {
			res.push_back(i);
			c = 1;
			b = 1;
			for (int j = 0; j < 26; j++) {
				ca[j] = 0;
			}
			ca[(int)(s[i] - 'a')]++;
		}
	}
	int pos=0;
	for (int i = 0; i < N; i++) {
		if ((int)res.size() > pos && i == res[pos]) {
			pos++;
			cout << " ";
		}
		cout << s[i];
	}
	cout << endl;
}