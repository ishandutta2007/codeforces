#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	
	string r = s;
	reverse(r.begin(), r.end());
	
	bool fail = false;
	if (r != s)
		fail = true;
	
	string ok = "AHIMOTUVWXY";
	
	for (char c: s)
	{
		bool normal = false;
		for (char x: ok)
			if (c == x)
				normal = true;
		
		if (!normal) fail = true;
	}
	
	printf("%s\n", fail ? "NO" : "YES");
}

int main()
{
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	int nTests;
	scanf("%d", &nTests);
	for (int i = 0; i < nTests; i++)
	{
		solve();
		printf("\n");
	}
	#else
	solve();
	#endif
	
	return 0;
}