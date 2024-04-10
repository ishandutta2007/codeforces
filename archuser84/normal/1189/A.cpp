#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n;
	cin >> n;
	char s[200];
	cin >> s;
	int z = 0, o = 0;
	for (LoopN)
	{
		if (s[i] == '1')
			++o;
		else
			++z;
	}
	if (o != z)
		cout << "1\n" << s << '\n';
	else
	{
		cout << "2\n";
		for (int i = 0; i < n - 1; ++i)
			cout << s[i];
		cout << ' ' << s[n - 1] << '\n';
	}
}