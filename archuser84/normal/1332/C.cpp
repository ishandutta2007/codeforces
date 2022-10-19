#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200010;
char s[N];
int n, k;

bool vis[N];
int Solve()
{
	memset(vis, 0, n);
	int cnt[26] = {};
	int all = 0;
	int ans = 0;
	Loop(i, 0, k)
	{
		if (vis[i])
			continue;
		memset(cnt, 0, sizeof(cnt));
		all = 0;
		for (int j = i; j < n; j += k)
		{
			if (vis[j])
				break;
			vis[j] = true;
			all++;
			cnt[s[j] - 'a']++;
		}
		for (int j = n - i - 1; j >= 0; j -= k)
		{
			if (vis[j])
				break;
			vis[j] = true;
			all++;
			cnt[s[j] - 'a']++;
		}
		int maax = 0;
		for (int x : cnt)
			maax = max(x, maax);
		ans += all - maax;
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
		cin >> n >> k;
		cin >> s;
		cout << Solve() << '\n';
	}
}