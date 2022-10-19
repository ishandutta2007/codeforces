#include <iostream>
using namespace std;

int main()
{
	int k, n, s[50];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int ans;
	for (ans = 0; s[ans] >= s[k-1] && s[ans] > 0 && ans < n; ans++) {}

	cout << ans << endl;
}