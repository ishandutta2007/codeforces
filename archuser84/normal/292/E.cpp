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

const int N = 262144;

int a[N];
int b[N];
class seg
{
private:
	int n;
	struct node
	{
		int v = -1;
		int l, r;
	};
	node tree[2 * N];
	int par(int x) { return (x - 1) >> 1; }
	int lef(int x) { return (x << 1) + 1; }
	int rig(int x) { return (x << 1) + 2; }

	void set(int i, int l, int r)
	{
		tree[i].v = 0;
		tree[i].l = l;
		tree[i].r = r;
		if (l == r)
			return;
		int m = (r + l) >> 1;
		set(lef(i), l, m);
		set(rig(i), m + 1, r);
	}

	void down(int i)
	{
		if (!tree[i].v)
			return;
		tree[lef(i)].v = tree[i].v;
		tree[rig(i)].v = tree[i].v + tree[lef(i)].r - tree[i].l + 1;
		tree[i].v = 0;
	}

public:
	seg(int x)
	{
		int n = x;
		set(0, 0, n - 1);
	}
	void Update(int i,int l,int r,int s)
	{
		if (l <= tree[i].l && tree[i].r <= r)
			tree[i].v = s + tree[i].l - l;
		else if (l > tree[i].r || r < tree[i].l)
			return;
		else
		{
			down(i);
			Update(lef(i), l, r, s);
			Update(rig(i), l, r, s);
		}
	}
	int Get(int s, int d)
	{
		if (s >= 2 * N-1 || tree[s].v == -1)
			return 0;
		if (tree[s].v)
			return tree[s].v + d - tree[s].l;
		else
		{
			int m = tree[lef(s)].r;
			if (d <= m)
				return Get(lef(s), d);
			else
				return Get(rig(s), d);
		}
	}
};

int main()
{
	FAST;
	int n, t;
	cin >> n >> t;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, n)
		cin >> b[i];
	seg T(n);
	while (t--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			T.Update(0, y - 1, y + k - 2, x);
		}
		else
		{
			int x;
			cin >> x; x--;
			int u = T.Get(0, x);
			if (u == 0)
				cout << b[x] << '\n';
			else
				cout << a[u - 1] << '\n';
		}
	}
}