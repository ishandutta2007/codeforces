#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;
const int SQ = 450;
struct Q
{
	int l, r;
	int i;
	ll ans;
}q[N];
int cnt[1000010] = {};
int a[N];
int n, t;

bool cmp(Q a, Q b)
{
	if (a.l / SQ < b.l / SQ)
		return true;
	if (a.l / SQ > b.l / SQ)
		return false;
	if ((a.l / SQ) & 1)
		return a.r > b.r;
	return a.r < b.r;
}

int main()
{
	FAST;
	cin >> n >> t;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(_, 0, t)
	{
		cin >> q[_].l >> q[_].r;
		q[_].l--;
		q[_].i = _;
	}
	sort(q, q + t, cmp);
	ll ans = 0;
	int l = 0, r = 0;
	Loop(i, 0, t)
	{
		while (r < q[i].r)
		{
			ans -= (ll)cnt[a[r]] * cnt[a[r]] * a[r];
			cnt[a[r]]++;
			ans += (ll)cnt[a[r]] * cnt[a[r]] * a[r];
			r++;
		}
		while (l < q[i].l)
		{
			ans -= (ll)cnt[a[l]] * cnt[a[l]] * a[l];
			cnt[a[l]]--;
			ans += (ll)cnt[a[l]] * cnt[a[l]] * a[l];
			l++;
		}
		
		while (r > q[i].r)
		{
			r--;
			ans -= (ll)cnt[a[r]] * cnt[a[r]] * a[r];
			cnt[a[r]]--;
			ans += (ll)cnt[a[r]] * cnt[a[r]] * a[r];
		}
		while (l > q[i].l)
		{
			l--;
			ans -= (ll)cnt[a[l]] * cnt[a[l]] * a[l];
			cnt[a[l]]++;
			ans += (ll)cnt[a[l]] * cnt[a[l]] * a[l];
		}

		q[i].ans = ans;
	}
	sort(q, q + t, [](Q a, Q b) { return a.i < b.i; });
	Loop(i, 0, t)
		cout << q[i].ans << '\n';
}