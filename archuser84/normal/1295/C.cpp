#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int bin(int* arr, int size, int x)
{
	int l = 0;
	int r = size - 1;
	while (r > l)
	{
		int y = (r + l) / 2;
		if (arr[y] >= x)
			r = y;
		else
			l = y + 1;
	}
	if (arr[l] >= x)
		return arr[l];
	else
		return -1;
}

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int a[26][100000];
		int size[26] = { 0 };
		char s[100002], t[100002];
		cin >> s >> t;
		int S1 = strlen(s), S2 = strlen(t);
		Loop(i, 0, S1)
		{
			a[s[i] - 'a'][size[s[i] - 'a']++] = i;
		}
		ll ans = 0;
		int count = 0;
		while (count < S2)
		{
			int p = 0;
			while (count < S2)
			{
				int ch = t[count] - 'a';
				if (size[ch] == 0)
				{
					ans = -1;
					goto end;
				}
				p = bin(a[ch], size[ch], p);
				if (p == -1)
					break;
				p++;
				count++;
			}
			ans++;
		}
	end:
		cout << ans << '\n';
	}
}