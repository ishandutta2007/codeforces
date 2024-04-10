#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
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
using namespace std;

const int N = 200010;
bool mask[N];
char s[N];
int n;
int cnt[N];
bool table[N];

bool can(int k)
{
	table[k] = 0;
	memset(cnt, 0, 4 * k);
	Loop(i, 0, n)
		cnt[i % k] += mask[i];
	Loop(i, 0, k)
		if (cnt[i] & 1)
			return 0;
	table[k] = 1;
	return 1;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	FAST;
	cin >> n;
	cin >> s;
	Loop(i, 0, n)
		mask[i] = s[i] - '0';
	int ans = 0;
	for (int d = 1; d <= n; d++)
	{
		if (n % d)
			ans += table[gcd(n, d)];
		else
			ans += can(d);
	}
	cout << ans;
}