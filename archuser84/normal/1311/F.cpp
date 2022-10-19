#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200000;

template <typename T>
class Fenwick
{
	vector<T> arr;
	unsigned int n;
public:
	Fenwick(unsigned int size) { n = size; arr.resize(n + 1); }
	void Add(int k, T v)
	{
		k++;
		while (k <= n)
		{
			arr[k] += v;
			k += k & (-k);
		}
	}
	void Replace(int k, T v)
	{
		add(k, v - arr[k]);
	}
	T Get(int k)
	{
		k++;
		T ans = 0;
		while (k > 0)
		{
			ans += arr[k];
			k -= k & (-k);
		}
		return ans;
	}
};

struct point
{
	int x;
	int v;
};

int main()
{
	int n;
	cin >> n;
	point P[N];
	Loop(i, 0, n)
		cin >> P[i].x;
	Loop(i, 0, n)
		cin >> P[i].v;
	sort(P, P + n, [&](point a, point b)
		{
			return a.v < b.v;
		});
	int k = P[0].v;
	int l = 0;
	Loop(i, 0, n)
	{
		if (P[i].v == k)
			P[i].v = l;
		else
		{
			k = P[i].v;
			P[i].v = ++l;
		}
	}
	sort(P, P + n, [&](point a, point b)
		{
			return a.x < b.x;
		});
	Fenwick<int> cnt(n);
	Fenwick<ll> sum(n);
	ll ans = 0;
	ll O = P[0].x;
	Loop(i, 0, n)
	{
		ans += (P[i].x - O) * cnt.Get(P[i].v) - sum.Get(P[i].v);
		cnt.Add(P[i].v, 1);
		sum.Add(P[i].v, P[i].x - O);
	}
	cout << ans << '\n';
}