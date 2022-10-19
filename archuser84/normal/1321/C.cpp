#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200;
bool tag[N] = {};
int n;
char s[N];

int Re(char t)
{
	int ans = 0;
	if ((!tag[0]) && s[0] == t)
	{
		Loop(j, 1, n)
		{
			if ((!tag[j]) && s[j] == s[0] - 1)
			{
				tag[0] = true;
				ans++;
				break;
			}
			if(!tag[j])
				break;
		}
	}
	if ((!tag[n - 1]) && s[n - 1] == t)
	{
		LoopR(j, 0, n - 1)
		{
			if ((!tag[j]) && s[j] == s[n - 1] - 1)
			{
				tag[n - 1] = true;
				ans++;
				break;
			}
			if (!tag[j])
				break;
		}
	}
	Loop(i, 1, n - 1)
	{
		if (tag[i] || s[i] != t)
			continue;
		bool flag = false;
		Loop(j, i + 1, n)
		{
			if ((!tag[j]) && s[j] == s[i] - 1)
			{
				tag[i] = true;
				ans++;
				flag = true;
				break;
			}
			if (!tag[j])
				break;
		}
		if (flag)
			continue;
		LoopR(j, 0, i)
		{
			if ((!tag[j]) && s[j] == s[i] - 1)
			{
				tag[i] = true;
				ans++;
				break;
			}
			if (!tag[j])
				break;
		}
	}
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	cin >> s;
	if (n == 1)
		cout << 0;
	else
	{
		int ans = 0;
		while(true)
		{
			int cnt = 0;
			LoopR(i, 0, 26)
			{
				int x = Re('a' + i);
				if (x)
				{
					cnt += x;
					i = 26;
				}
			}
			if (!cnt)
				break;
			ans += cnt;
		}
		cout << ans;
	}
}