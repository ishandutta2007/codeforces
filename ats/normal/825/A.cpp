#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			res *= 10;
		}
		else {
			res++;
		}
	}
	cout << res << endl;
	return 0;
	
}