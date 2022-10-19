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
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 500000;

set<int> ent[N];
ll c[N];
int stpnt = 0;
int n;
map<set<int>, ll> x;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll Solve()
{
	ll ans = 0;
	for(auto t : x)
		ans = gcd(t.second, ans);
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> n >> m;
		Loop(i, stpnt, stpnt + n)
			cin >> c[i];
		Loop(i, 0, m)
		{
			int u, v;
			cin >> u >> v;
			u--; v--;
			ent[v + stpnt].insert(u);
		}
		x.clear();
		Loop(i, stpnt, stpnt + n)
			if (!ent[i].empty())
				x[ent[i]] += c[i];;
		cout << Solve() << '\n';
		stpnt += n;
	}
}