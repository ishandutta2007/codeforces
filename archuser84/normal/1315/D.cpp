#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200000;

int main()
{
	struct ele
	{
		int c;
		int t;
	}a[N];
	int n;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i].c;
	Loop(i, 0, n)
		cin >> a[i].t;
	sort(a, a + n, [&](ele a, ele b)
		{
			return a.c < b.c;
		});
	pair<int, int> baze[N];
	baze[0].first = 0; int bs = 0;
	Loop(i,1,n)
		if (a[i].c != a[i - 1].c)
		{
			baze[bs++].second = i;
			baze[bs].first = i;
		}
	baze[bs++].second = n;
	int p = 0;
	int c;
	multiset<int, greater<int> > S;
	ll ans = 0;
	ll sum = 0;
	for (p = 0; p < bs; p++)
	{
		c = a[baze[p].first].c;
		Loop(i, baze[p].first, baze[p].second)
		{
			S.insert(a[i].t);
			sum += a[i].t;
		}
		while (!S.empty())
		{
			sum -= *S.begin();
			S.erase(S.begin());
			ans += sum;
			c++;
			if (p + 1 < bs && c == a[baze[p + 1].first].c)
				break;
		}
	}
	cout << ans;
}