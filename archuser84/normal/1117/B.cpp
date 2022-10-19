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
using namespace std;

const int N = 200010;
ll a[N];
ll n, m, k;

int main()
{
	cin >> n >> m >> k; k++;
	Loop(i, 0, n)
		cin >> a[i];
	sort(a, a + n, greater<ll>());
	ll ans = 0;
	ans += (m / k) * ((k - 1) * a[0] + a[1]);
	ans += (m % k) * a[0];
	cout << ans;
}