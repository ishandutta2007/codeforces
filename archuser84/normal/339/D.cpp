#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 1 << 17;

int a[N];
class seg
{
private:
	int n;
	int tree[2 * N - 1];
	int par(int x) { return (x - 1) >> 1; }
	int lef(int x) { return (x << 1) + 1; }
	int rig(int x) { return (x << 1) + 2; }

	int update(int i,int h)
	{
		if (h < 0)
			return tree[0];
		if ((n + h) & 1)
			tree[i] = tree[lef(i)] | tree[rig(i)];
		else
			tree[i] = tree[lef(i)] ^ tree[rig(i)];
		return update(par(i), h - 1);
	}
public:
	seg(int x) { n = x; }
	int Set(int* a, int h, int i)
	{
		if (h == n)
		{
			tree[i] = a[i + 1 - (1 << n)];
			return tree[i];
		}
		if ((n + h) & 1)
			tree[i] = Set(a, h + 1, lef(i)) | Set(a, h + 1, rig(i));
		else
			tree[i] = Set(a, h + 1, lef(i)) ^ Set(a, h + 1, rig(i));
		return tree[i];
	}
	int Update(int i,int v)
	{
		i = i + (1 << n) - 1;
		tree[i] = v;
		return update(par(i), n - 1);
	}
};

int main()
{
	FAST;
	int n, t;
	cin >> n >> t;
	Loop(i, 0, 1<<n)
		cin >> a[i];
	seg T(n);
	T.Set(a, 0, 0);
	while (t--)
	{
		int i, v;
		cin >> i >> v; i--;
		cout << T.Update(i, v) << '\n';
	}
}