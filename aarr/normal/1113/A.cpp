#include <iostream>
using namespace std;



int main() {
	int n, v;
	cin >> n >> v;
	int x = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += min(v - x, n - i - x) * i;
		x += min(v - x, n - i - x);
		x--; 
	} 
	cout << ans;
	
	return 0;
}