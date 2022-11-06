#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5

string s, t;

int main()
{
	cin >> s;
	t = s;
	sort(t.begin(), t.end());
	if (s != t) puts("NO");
	else
	{
		int c_a = 0, c_b = 0, c_c = 0;
		bool ok = 1;
		for (char c : s)
		{
			if (c == 'a') c_a ++;
			else if (c == 'b') c_b ++;
			else if (c == 'c') c_c ++;
			else ok = 0;
		}
		if (!ok || (c_c != c_a && c_c != c_b) || !c_a || !c_b) puts("NO");
		else puts("YES");
	}
	return 0;
}