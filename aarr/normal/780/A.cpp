#include <iostream>
using namespace std;


bool mark[100 * 1000 + 5];
int main() {
	int n, ans = 0, s = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		if (mark[x]) {
			s--;
		}
		else {
			s++;
		}
		mark[x] ^= 1;
		ans = max(ans, s);
	}
	cout << ans;
	
	return 0;
}