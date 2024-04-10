#include <iostream>
using namespace std;


const int N = 55;

int a[N];
int b[N];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}