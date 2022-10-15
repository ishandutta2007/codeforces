/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;
#define input freopen("input.txt", "r", stdin);
#define sync ios_base::sync_with_stdio(0); cin.tie(0);

int ar[100];

void print() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < ar[i]; j++)
			cout << i + 1 << " ";
	}
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	memset(ar, 0, sizeof(ar));
	int a[n], c = INT_MAX, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c = min(a[i], c);
		b = max(b, a[i]);
		if (i != 0 && abs(a[i] - a[i - 1]) > k) {
			cout << "NO";
			return 0;
		}
	}
	if(b - c > k){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int last = a[0] % k;
	for (int i = 0; i < a[0]; i++) {
		ar[i % k]++;
	}
	print();
	for (int i = 1; i < n; i++) {
		int g = abs(a[i] - a[i - 1]);
		if (a[i] < a[i - 1]) {
			while (g--) {
				last = (k + last - 1) % k;
				ar[last]--;
			}
		} else {
			while (g--) {
				ar[last]++;
				last = (last + 1) % k;
			}
		}
		print();
	}
}