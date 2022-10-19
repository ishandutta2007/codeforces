#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

const int MAXINT = 1073741823;

int a[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, answer = 0, counter, counter2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x] = i;
	}
	if (a[1] != 0) {
		counter = 2;
		while (a[counter] == a[1] + counter - 1)
			counter++;
		if (a[counter - 1] == n) {
			counter2 = counter;
			while (counter2 <= n && a[counter2] <= counter2 - counter)
				counter2++;
			if (counter2 > n) {
				cout << n - counter + 1;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		answer = max(answer, a[i] - i + 1 + n);
	cout << answer;
	return 0;
}