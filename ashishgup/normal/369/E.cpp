#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 3e5 + 5;
const int M = 1e6 + 5;

int n, m;
vector<int> fin[M];
vector<int> st[4 * M];

void build(int node, int L, int R)
{
	if(L == R)
	{
		st[node] = fin[L];
		sort(st[node].begin(), st[node].end());
		return;
	}
	int M = (L + R) / 2;
	build(node * 2, L, M);
	build(node * 2 + 1, M + 1, R);
	int i = 0, j = 0;
	int l = node * 2, r = node * 2 + 1;
	while(i < st[l].size() && j < st[r].size())
	{
		if(st[l][i] <= st[r][j])
			st[node].push_back(st[l][i++]);
		else
			st[node].push_back(st[r][j++]);
	}
	while(i < st[l].size())
		st[node].push_back(st[l][i++]);
	while(j < st[r].size())
		st[node].push_back(st[r][j++]);
}

int query(int node, int L, int R, int i, int j, int x)
{
	if(R < L)
		return 0;
	if(j < L || i > R)
		return 0;
	if(i <= L && R <= j)
	{
		if(!st[node].size())
			return 0;
		auto it = upper_bound(st[node].begin(), st[node].end(), x) - st[node].begin();
		return it;
	}
	int M = (L + R) / 2;
	int left = query(node * 2, L, M, i, j, x);
	int right = query(node * 2 + 1, M + 1, R, i, j, x);
	return left + right;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		fin[l].push_back(r);
	}
	build(1, 1, 1e6);
	for(int  i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		int prev = 0;
		for(int j = 1; j <= x; j++)
		{
			int cur;
			cin >> cur;
			cnt += query(1, 1, 1e6, prev + 1, cur - 1, cur - 1);
			prev = cur;
		}
		int cur = 1e6;
		cnt += query(1, 1, 1e6, prev + 1, cur, 1e6);
		int ans = n - cnt;
		cout << ans << endl;
	}
	return 0;
}