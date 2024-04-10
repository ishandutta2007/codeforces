#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 1; i < (int)s.size(); i++)
	{
		if (i % n)
			continue;
		int k = 0;
		for (int j = 0; j < 3; j++)
			k += s[i] != s[i - j - 1];
		ans += k == 3 || k == 0;
	}
	cout << ans << endl;
	return 0;
}