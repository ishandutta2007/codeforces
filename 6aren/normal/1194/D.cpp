#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sp ' '
#define fi first
#define se second

int n, k;

void lose() {
	cout << "Bob" << endl;
}

void win() {
	cout << "Alice" << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		if (k % 3 != 0) {
			if (n % 3 == 0) lose();
			else win();
			continue;
		}

		int tmp = (n / (k + 1)) % 3;
		if (n % 3 == tmp && n != (n / (k + 1) * (k + 1)) + k) {
			lose();
		} else {
			win();
		}
	}
	return 0;
}