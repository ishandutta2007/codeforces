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
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 6000;
int n;
char s[N];
int Get(int a,int i)
{
	if (a + i < n)
		return a + i;
	else if ((a + n) % 2 == 0)
		return (a + i) % n;
	else
		return a - ((a + i) % n) - 1;
}
bool ch(int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		if (s[Get(b, i)] < s[Get(a, i) % n])
			return true;
		if (s[Get(b, i) % n] > s[Get(a, i) % n])
			break;
	}
	return false;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s;
		int ans = 0;
		Loop(i, 1, n)
			if (s[i] < s[ans])
				ans = i;
		Loop(i, ans + 1, n)
		{
			if (ch(ans, i))
				ans = i;
		}
		Loop(i, 0, n)
			cout << s[Get(ans, i)];
		cout << '\n';
		cout << ans + 1 << '\n';
	}
}