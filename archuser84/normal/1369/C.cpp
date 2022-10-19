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

const int N = 200010;
int w[N];
ll a[N];
int n, k;

ll Solve()
{
	sort(w, w + k);
	sort(a, a + n);
	ll ans = 0;
	int p1 = 0, p2 = n - 1;
	Loop(i, 0, k)
	{
		if (w[i] > 1)
			break;
		ans += 2 * a[p2];
		p2--;
	}
	LoopR(i, 0, k)
	{
		if (w[i] == 1)
			break;
		ans += a[p1] + a[p2];
		p1 += w[i] - 1;
		p2--;
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
		Loop(i, 0, n)
			cin >> a[i];
		Loop(i, 0, k)
			cin >> w[i];
		cout << Solve() << '\n';
	}
}