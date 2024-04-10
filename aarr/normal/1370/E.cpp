#include <iostream>
using namespace std;



int main() {
	int n, x = 0, ans = 0, mini = 0, maxi = 0;
	string s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		x += s[i] - '0';
		x -= t[i] - '0';
		ans = max(ans, abs(x - mini));
		ans = max(ans, abs(x - maxi));
		mini = min(mini, x);
		maxi = max(maxi, x);
	}
	if (x != 0)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}