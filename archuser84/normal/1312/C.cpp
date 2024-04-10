#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) cout << (flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 50;
ll a[N];
const int s = 64;

bool getAns(ll n, ll k)
{
	Loop(i, 0, s)
	{
		ll cnt = 0;
		Loop(j, 0, n)
		{
			cnt += a[j] % k;
			a[j] /= k;
		}
		if (cnt > 1)
			return false;
	}
	return true;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		Loop(i, 0, n)
			cin >> a[i];
		YN(getAns(n, k));
	}
}