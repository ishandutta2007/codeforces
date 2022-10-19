#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string c[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	string a[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
	string b[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
	cout << 6-n << endl;
	for (int i = 0; i < 6; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (a[i] == c[j]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			cout << b[i] << endl;
		}
	}
	return 0;
}