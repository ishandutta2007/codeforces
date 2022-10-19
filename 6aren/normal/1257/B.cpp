#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair
#define x first
#define y second


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			cout << "YES\n";
			continue; 
		}
		if (x == 1) {
			cout << "NO\n";
			continue;
		}
		if (x > y) {
			cout << "YES\n";
			continue;
		}
		if (x == 2) {
			if (y == 3) {
				cout << "YES\n";
				continue;
			} else {
				cout << "NO\n";
				continue;
			}
		}
		if (x > y) {
			cout << "YES\n";
			continue;
		}
		if (x == 3) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}