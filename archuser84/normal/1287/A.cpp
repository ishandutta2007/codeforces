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
	int t;
	cin >> t;
	for (Loop)
	{
		int n;
		cin >> n;
		char s[302];
		cin >> s;
		int max = 0, c = 0;
		bool f = 0;
		for (LoopN)
		{
			if (s[i] == 'A')
			{
				f = true;
				if (max < c)
					max = c;
				c = 0;
			}
			else if(f)
				++c;
		}
		if (max < c)
			max = c;
		cout << max << '\n';
	}
}