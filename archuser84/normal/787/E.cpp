///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC target("arch=skylake")

const int N = 100'010;
int ans[N];
int a[N];
int n;

int solve_for(int k)
{
	static int foo[N], time=1;
	int ans = 1, l = 0, r = 0, cnt = 0;
	for (; r<n; ++r) {
		cnt += foo[a[r]] != time;
		if (cnt > k) {
			++ans;
			++time;
			cnt = 1;
		}
		foo[a[r]] = time;
	}
	++time;
	return ans;
}

void solve(int l, int r, int b, int e)
{
	if (e-b == 1) {
		Loop (i,l,r)
			ans[i] = b;
	} else if (r-l) {
		int mid = (l+r)/2;
		int x = solve_for(mid);
		ans[mid] = x;
		solve(l, mid, x, e);
		solve(mid+1, r, b, x+1);
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n)
		cin >> a[i];
	solve(1, n+1, 1, n+1);
	Loop (i,1,n+1)
		cout << ans[i] << ' ';
	cout << '\n';
}