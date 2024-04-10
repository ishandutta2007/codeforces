#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 100000;

int main()
{
	FAST;
	int n;
	int m[N];
	ll maax = 0;
	int ans;
	cin >> n;
	Loop(i, 0, n)
		cin >> m[i];
	Loop(i, 0, n)
	{
		ll cnt = m[i];
		int miin = m[i];
		LoopR(j, 0, i)
		{
			int x = min(miin, m[j]);
			cnt += x;
			miin = x;
		}
		miin = m[i];
		Loop(j, i + 1, n)
		{
			int x = min(miin, m[j]);
			cnt += x;
			miin = x;
		}
		if (cnt > maax)
		{
			maax = cnt;
			ans = i;
		}
	}

	int i = ans;
	int a[N]; a[i] = m[i];
	int miin = m[i];
	LoopR(j, 0, i)
	{
		int x = min(miin, m[j]);
		a[j] = x;
		miin = x;
	}
	miin = m[i];
	Loop(j, i + 1, n)
	{
		int x = min(miin, m[j]);
		a[j] = x;
		miin = x;
	}

	Loop(x, 0, n)
		cout << a[x] << ' ';
}