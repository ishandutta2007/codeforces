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

const int N = 100000;
int a[N];

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n; ll m;
		cin >> n >> m;
		Loop(i, 0, n)
			cin >> a[i];
		sort(a, a + n);
		ll sum = 0;
		int ans = 0;
		LoopR(i,0,n)
		{
			if (m - a[i] > sum)
				break;
			ans++;
			sum += (ll)a[i] - m;
		}
		cout << ans << '\n';
	}
}