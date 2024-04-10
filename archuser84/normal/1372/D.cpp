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
ll a[N];
int n;

int main()
{
	FAST;
	cin >> n;
	ll total = 0;
	Loop(i, 0, n)
		cin >> a[i], total += a[i];
	ll sum = 0;
	for (int i = 1; i < n; i += 2)
		sum += a[i];
	ll miin = sum;
	int s = 1;
	Loop(i, 1, n)
	{
		sum -= a[s];
		sum += a[(s + n - 1) % n];
		miin = min(miin, sum);
		s = (s + 2) % n;
	}
	cout << total - miin;
}