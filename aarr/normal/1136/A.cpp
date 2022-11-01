#include <iostream>
using namespace std;


int a[105];
int b[105];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	int k, ans = 0;
	cin >> k;
	for (int i = 0; i < n; i++) {
		if (b[i] >= k)	
			ans++;
	}
	cout << ans << endl;
	return 0;
}