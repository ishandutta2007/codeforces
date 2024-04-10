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

const ll infll = 1LL << 60;
const int N = 100010;
const int K = 10010;
ll h; int n, t, k;
ll p[N];
bool tag[N] = {};
ll E[30];
int m = 0;
ll d[K];

class Heap
{
	vector<int> tree;
	int track[N];
	int val[N];
	int size = 0;

	int par(int x) { return (x - 1) >> 1; }
	int lef(int x) { return (x << 1) + 1; }
	int rig(int x) { return (x << 1) + 2; }

	bool comp(int u, int d) { return val[tree[u]] > val[tree[d]] || (val[tree[u]] == val[tree[d]] && tree[u] < tree[d]); }
	void tswap(int i, int j)
	{
		swap(track[tree[i]], track[tree[j]]);
		swap(tree[i], tree[j]);
	}
	void heapify(int i)
	{
		int l = lef(i);
		int r = rig(i);
		int p = i;
		if (l < size && comp(l, p))
			p = l;
		if (r < size && comp(r, p))
			p = r;
		if (p != i)
		{
			tswap(i, p);
			heapify(p);
		}
	}
public:
	Heap()
	{
		memset(track, -1, sizeof(track));
	}
	void Create(int key, int v)
	{
		val[key] = v;
		track[key] = -1;
	}
	void Insert(int key)
	{
		track[key] = size;
		tree.push_back(key);
		int i = size;
		size++;
		while (i > 0 && comp(i, par(i)))
		{
			tswap(i, par(i));
			i = par(i);
		}
	}
	pii Extract()
	{
		pii ans = { tree[0], val[tree[0]] };
		tswap(0, --size);
		tree.pop_back();
		heapify(0);
		return ans;
	}
	void Decrease(int key, int v)
	{
		val[key] -= v;
		if (track[key] != -1)
			heapify(track[key]);
	}
	bool empty()
	{
		return !size;
	}
};
class Heap2
{
	vector<int> tree;
	int track[K];
	ll val[K];
	int size = 0;

	int par(int x) { return (x - 1) >> 1; }
	int lef(int x) { return (x << 1) + 1; }
	int rig(int x) { return (x << 1) + 2; }

	bool comp(int u, int d) { return val[tree[u]] < val[tree[d]]; }
	void tswap(int i, int j)
	{
		swap(track[tree[i]], track[tree[j]]);
		swap(tree[i], tree[j]);
	}
	void heapify(int i)
	{
		int l = lef(i);
		int r = rig(i);
		int p = i;
		if (l < size && comp(l, p))
			p = l;
		if (r < size && comp(r, p))
			p = r;
		if (p != i)
		{
			tswap(i, p);
			heapify(p);
		}
	}
public:
	Heap2()
	{
		memset(track, -1, sizeof(track));
	}
	void Insert(int key, ll v)
	{
		val[key] = v;
		track[key] = size;
		tree.push_back(key);
		int i = size;
		size++;
		while (i > 0 && comp(i, par(i)))
		{
			tswap(i, par(i));
			i = par(i);
		}
	}
	pair<int, ll> Extract()
	{
		pair<int, ll> ans = { tree[0], val[tree[0]] };
		tswap(0, --size);
		tree.pop_back();
		heapify(0);
		return ans;
	}
	bool empty()
	{
		return !size;
	}
	void DecreaseSet(int key, ll v)
	{
		val[key] = v;
		int i = track[key];
		while (i > 0 && comp(i, par(i)))
		{
			tswap(i, par(i));
			i = par(i);
		}
	}
	bool Exist(int key)
	{
		return !(track[key] == -1);
	}
	ll getVal(int key)
	{
		return val[key];
	}
};

void dij()
{
	memset(d, -1, sizeof(d));
	Heap2 H;
	H.Insert(0, 0);
	while (!H.empty())
	{
		pair<int, ll> vv = H.Extract();
		int v = vv.first;
		d[v] = vv.second;
		Loop(i, 0, m)
		{
			int u = (E[i] + v) % k;
			ll w = E[i] + d[v];
			if (d[u] > 0)
				continue;
			if (w > infll)
				continue;
			if (!H.Exist(u))
				H.Insert(u, w);
			else if (w < H.getVal(u))
				H.DecreaseSet(u, w);
		}
	}
}

int main()
{
	FAST;
	cin >> h >> n >> t >> k;
	Heap H;
	Loop(i, 0, n)
	{
		int y; ll x;
		cin >> x >> y; x--; p[i] = x;
		H.Create(i, y);
		if (x % k == 0)
		{
			H.Insert(i);
			tag[i] = true;
		}
	}
	while (t--)
	{
		int type; cin >> type;
		if (type == 3)
		{
			if (H.empty())
				cout << "0\n";
			else
				cout << H.Extract().second << '\n';
		}
		if (type == 2)
		{
			int x, y;
			cin >> x >> y; x--;
			H.Decrease(x, y);
		}
		if (type == 1)
		{
			cin >> E[m++];
			dij();
			Loop(i, 0, n)
			{
				if (tag[i])
					continue;
				if (d[p[i] % k] != -1 && d[p[i] % k] <= p[i])
				{
					tag[i] = true;
					H.Insert(i);
				}
			}
		}
	}
}