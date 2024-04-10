#include <bits/stdc++.h>

using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string s;
	int cnt = 0;
	int lim = 100;
	for (int i = 2; i <= 50; i++) {
		if (prime(i)) {
			cout << i << endl;
			cin >> s;
			if (s == "yes") {
				cnt++;
				if (i * i <= 100) {
					cout << i * i << endl;
					cin >> s;
					if (s == "yes") {
						cout << "composite" << endl;
						return 0;
					}
				}
			}
		}
	}
	if (cnt <= 1) {
		cout << "prime" << endl;
	} else {
		cout << "composite" << endl;
	}
}