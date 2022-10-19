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

const int N = 1000010;

char a[N];

const ll my_mod = 1000000000100011LL;
const ll base = 26;
int longestL(int l, int r)
{
	int ans = 0;
	ll h1 = 0;
	ll h2 = 0;
	ll k = 1;
	Loop(i, l, r + 1)
	{
		h1 = (h1 + k * (a[i] - 'a')) % my_mod;
		h2 = (h2 * base + (a[i] - 'a')) % my_mod;
		k = (k * base) % my_mod;
		if (h1 == h2)
			ans = i - l + 1;
	}
	return ans;
}
int longestR(int l, int r)
{
	int ans = 0;
	ll h1 = 0;
	ll h2 = 0;
	ll k = 1;
	LoopR(i, l, r + 1)
	{
		h1 = (h1 + k * (a[i] - 'a')) % my_mod;
		h2 = (h2 * base + (a[i] - 'a')) % my_mod;
		k = (k * base) % my_mod;
		if (h1 == h2)
			ans = r - i + 1;
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a;
		int size = strlen(a);
		int k = 0;
		bool flag = false;
		while (a[k] == a[size - 1 - k])
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
			cout << a << '\n';
			continue;
		}
		int maxl = longestL(k, size - k - 1);
		int maxr = longestR(k, size - k - 1);
		if (maxl > maxr)
		{
			Loop(i, 0, k + maxl)
				cout << a[i];
			Loop(i, size - k, size)
				cout << a[i];
		}
		else
		{
			Loop(i, 0, k)
				cout << a[i];
			Loop(i, size - k - maxr, size)
				cout << a[i];
		}
		cout << '\n';
	}
}