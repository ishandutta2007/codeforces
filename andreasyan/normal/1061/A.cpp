#include <bits/stdc++.h>
using namespace std;

int n, s;

int main()
{
	cin >> n >> s;
	int ans = 0;
	for (int i = n; i >= 1; --i)
	{
		ans += (s / i);
		s %= i;
	}
	cout << ans << endl;
	return 0;
}