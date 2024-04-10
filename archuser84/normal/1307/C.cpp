#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
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
	char s[300000];
	cin >> s;
	int size = strlen(s);
	int al[26] = { 0 };
	ll coun[26][26] = { 0 };
	Loop(i, 0, size)
		al[s[i] - 'a']++;
	ll ans = 0;
	Loop(i, 0, 26)
		if (al[i] > ans)
			ans = al[i];
	Loop(i, 0, size)
	{
		int c = s[i] - 'a';
		al[c]--;
		Loop(i, 0, 26)
			coun[c][i] += al[i];
	}
	Loop(i, 0, 26)
		Loop(j, 0, 26)
			if (coun[i][j] > ans)
				ans = coun[i][j];
	cout << ans << '\n';
}