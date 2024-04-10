#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 300010;

char s[N];

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cin >> s;
		int cnt = 0;
		int imp = 0;
		int bs = 0;
		int B;
		for (int i = 0;; i++)
		{
			if (s[i] == '.')
			{
				cnt++;
				continue;
			}
			if (cnt < 2 * b && cnt >= a)
				imp++;
			else if (cnt >= b)
			{
				bs++;
				B = cnt;
			}
			cnt = 0;
			if (s[i] == '\0')
				break;
		}
		if (bs > 1)
			cout << "NO\n";
		else if (bs == 1)
		{
			if (B < a)
				cout << "NO\n";
			else
			{
				if ((B - a <= 3 * b - 2 && B - a >= a && imp % 2 == 1) || (B - a <= 4 * b - 2 && B - a >= 2 * a && imp % 2 == 0) || (B - a <= 2 * b - 2 && B - a >= 0 && imp % 2 == 0))
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
		else
			cout << YN(imp % 2);
	}
}