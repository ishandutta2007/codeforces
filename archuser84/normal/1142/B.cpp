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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 200010;
const int logN = 18;
int perm[N];
int a[N];
int n, m, q;

vector<int> A[N];
int lca[N][logN];

void dfs(int u, int p)
{
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	for (int v : A[u])
		dfs(v, u);
}

int LCA(int a, int k)
{
	for (int i = 0; k > 0; i++)
	{
		if (k & 1)
			a = lca[a][i];
		k >>= 1;
	}
	return a;
}

void Input()
{
	cin >> n >> m >> q;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		perm[x] = i;
	}
	Loop(i, 1, m+1)
	{
		cin >> a[i];
		a[i] = perm[a[i]];
	}
}

class segmentTree
{
private:
	const int nullValue = 0;
	struct node
	{
		int v;
		int l, r;
		node(int value, int left, int right)
		{
			v = value;
			l = left;
			r = right;
		}
		node()
		{
			v = -1;
			l = -1;
			r = -1;
		}
	};
	node tree[2*262144];
	int arr[2*100000];

	int parent(int n) { return (n - 1) / 2; }
	int left(int n) { return 2 * n + 1; }
	int right(int n) { return 2 * n + 2; }

	int merge(int a, int b)
	{
		return max(a, b);
	}
	int create(int n, int l, int r)
	{
		if (l == r)
			tree[n] = node(arr[l], l, r);
		else
		{
			tree[n] = node(
				merge(create(left(n), l, (l + r) / 2),
					create(right(n), (l + r) / 2 + 1, r))
				, l, r);
		}
		return tree[n].v;
	}
	int getValue(int n, int l, int r)
	{
		if (tree[n].r < l || tree[n].l > r)
			return nullValue;
		else if (tree[n].l >= l && tree[n].r <= r)
			return tree[n].v;
		else
			return merge(getValue(left(n), l, r),
				getValue(right(n), l, r));
	}
public:
	void Create(int* a, int size)
	{
		for (int i = 0; i < size; i++)
			arr[i] = a[i];
		create(0, 0, size - 1);
	}
	int GetValue(int l, int r)
	{
		return getValue(0, l, r);
	}
}S;

int last[N] = {};
int arr[N];
void DP()
{
	Loop(i, 1, m+1)
	{
		A[last[(a[i] + n - 1) % n]].push_back(i);
		last[a[i]] = i;
	}
	dfs(0, 0);
	arr[0] = 0;
	Loop(i, 1, m + 1)
		arr[i] = LCA(i, n - 1);
	S.Create(arr, m + 1);
}

int main()
{
	FAST;
	Input();
	DP();
	vector<bool> ans;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int k = S.GetValue(l, r);
		if (k >= l)
			ans.push_back(1);
		else
			ans.push_back(0);
	}
	for (bool k : ans)
		cout << k;
}