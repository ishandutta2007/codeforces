#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 5010;

char s[N];

bool isPol(int l, int r)
{
	Loop(i, 0, (r - l + 1) / 2)
	{
		if (s[l + i] != s[r - i])
			return false;
	}
	return true;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		int size = strlen(s);
		int k = 0;
		bool flag = false;
		while (s[k] == s[size - 1 - k])
		{
			k++;
			if (k > size / 2)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			cout << s << '\n';
			continue;
		}
		int maxl = 0;
		LoopR(i, k, size - k)
		{
			if (isPol(k, i))
			{
				maxl = i - k + 1;
				break;
			}
		}
		int maxr = 0;
		Loop(i, k, size - k)
		{
			if (isPol(i, size - k - 1))
			{
				maxr = size - k - i;
				break;
			}
		}
		if (maxl > maxr)
		{
			Loop(i, 0, k + maxl)
				cout << s[i];
			Loop(i, size - k, size)
				cout << s[i];
		}
		else
		{
			Loop(i, 0, k)
				cout << s[i];
			Loop(i, size - k - maxr, size)
				cout << s[i];
		}
		cout << '\n';
	}
}