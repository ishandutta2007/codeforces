#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define PII pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

int main()
{
	int t;
	cin >> t;
	char s[100010];
	while (t--)
	{
		map<pair<PII, PII>, bool> vis;
		int ans = 0;
		cin >> s;
		int n = strlen(s);
		PII A = { 0,0 };
		Loop(i, 0, n)
		{
			PII New = A;
			switch (s[i])
			{
			case 'S': New.second--; break;
			case 'N': New.second++; break;
			case 'E': New.first++; break;
			case 'W': New.first--; break;
			}
			if (vis[{A, New}])
				ans += 1;
			else
			{
				ans += 5;
				vis[{A, New}] = true;
				vis[{New, A}] = true;
			}
			A = New;
		}
		cout << ans << '\n';
	}
}