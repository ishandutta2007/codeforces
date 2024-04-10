#include <iostream>
using namespace std;

string s[100 * 1000 + 5];
int main() {
	int n;
	cin >> n;
	int ans = n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (i > 0 && s[i] == s[i - 1])
			ans--;
	}
	cout << ans << endl;
}