#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

const int N = 2010;
char s[N];
int n, k;
int cnt[26];

bool can(int len)
{
	int x = gcd(k, len);
	int ans = 0;
	Loop(i, 0, 26)
		ans += cnt[i] / (len / x);
	return ans >= x;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> k >> s;
		Loop(i, 0, n)
			cnt[s[i] - 'a']++;
		int ans = 0;
		Loop(i, 1, n + 1)
			if (can(i))
				ans = i;
		printf("%i\n", ans);
	}
}