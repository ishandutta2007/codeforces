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
#define YN(flag) cout<<(flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1e5;

int n;
int a[N];

bool dig(int i, int k)
{
	return (a[i] >> k) & 1;
}

int Bin(int L, int R,int k)
{
	int l = L;
	int r = R + 1;
	while (r > l)
	{
		int m = (l + r) / 2;
		if (dig(m, k))
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int Solve(int k,int l,int r)
{
	int m = Bin(l, r, k);
	if (k == 0)
	{
		if (m == l || m > r)
			return 0;
		else
			return 1;
	}
	if (m == l || m > r)
		return Solve(k - 1, l, r);
	else
		return min(Solve(k - 1, l, m - 1), Solve(k - 1, m, r)) + (1 << k);
}

int main()
{
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	sort(a, a + n);
	cout << Solve(29, 0, n-1);
}