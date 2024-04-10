#include <bits/stdc++.h>
using namespace std;


const int N = 1005;

int a[N];
int b[N];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ansfor = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int min1 = a[i], min2 = a[i];
		long long s = a[i];
		
		for (int j = i - 1; j; j--) {
			min1 = min(min1, a[j]);
			s += min1;
		}
		for (int j = i + 1; j <= n; j++) {
			min2 = min(min2, a[j]);
			s += min2;
		}
		if (s > ans) {
			ansfor = i;
			ans = s;
		}
	}
	for (int i = ansfor; i <= ansfor; i++) {
		b[i] = a[i];
		int min1 = a[i], min2 = a[i];
		for (int j = i - 1; j; j--) {
			min1 = min(min1, a[j]);
			b[j] = min1;
		}
		for (int j = i + 1; j <= n; j++) {
			min2 = min(min2, a[j]);
			b[j] = min2;
		}		
	}
//	cout << ansfor << " " << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
	return 0;
}