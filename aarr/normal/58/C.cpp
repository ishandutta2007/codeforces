#include <iostream>
using namespace std;


const int N = 100 * 1000 + 5;

int a[N];
int hasdif[2 * N]; 
int main() {
	int n;
	cin >> n;
	int ans = n;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n / 2; i++) {
		if (k <= a[i]) {
			hasdif[a[i] - k]++;
			ans = min(ans, n - hasdif[a[i] - k]);
		}
		
	//	cout << i << " " << k << endl;
		k++;
		
	}
//	cout << 73 << endl;
	if (n % 2 == 0)
		k--;
	for (int i = n / 2 + 1; i <= n; i++) {
		if (k <= a[i]) {
			hasdif[a[i] - k]++;
			ans = min(ans, n - hasdif[a[i] - k]);
		}
		
	//	cout << i << " " << k << endl;
		k--;
	}
	cout << ans << endl;
	return 0;
}