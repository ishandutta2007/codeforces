#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	srand(time(NULL));
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	int n;
	cin >> n;
	bool logic = false;
	for (ll p = 0; p * 1234567 <= n; p++) {
		for (ll t = 0; t * 123456 + p * 1234567 <= n; t++) {
			if ((n - p * 1234567 - t * 123456) % 1234 == 0) {
				logic = 1;
			}
		}
	}
	cout << (logic ? "YES" : "NO") << endl;
}