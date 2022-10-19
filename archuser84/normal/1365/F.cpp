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

const int N = 510;
int a[N];
int b[N];
int n;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Loop(i, 0, n)
			cin >> a[i];
		Loop(i, 0, n)
			cin >> b[i];
		if (n & 1 && a[n / 2] != b[n / 2])
		{
			cout << "NO\n";
			continue;
		}
		map<pii, int> cnt;
		Loop(i, 0, n / 2)
		{
			cnt[{a[i], a[n - 1 - i]}]++;
			cnt[{a[n - 1 - i], a[i]}]++;
		}
		bool ans = 1;
		Loop(i, 0, n / 2)
		{
			cnt[{b[i], b[n - 1 - i]}]--;
			if (cnt[{b[i], b[n - 1 - i]}] < 0)
			{
				ans = 0;
				break;
			}
			cnt[{b[n - 1 - i], b[i]}]--;
			if (cnt[{b[n - 1 - i], b[i]}] < 0)
			{
				ans = 0;
				break;
			}
		}
		cout << YN(ans) << '\n';
	}
}