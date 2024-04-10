#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s[1000];
		cin >> s;
		int n = strlen(s);
		int ans = 0;
		int count = 0;
		bool flag = 0;
		Loop(i, 0, n)
		{
			if (s[i] == '1')
			{
				ans += count * flag;
				count = 0;
				flag = true;
			}
			else
				count++;
		}
		cout << ans << '\n';
	}
}