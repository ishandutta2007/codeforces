#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn][3] , frst[maxn][3] , pt[maxn];

int mx[maxn * 4] , mn[maxn * 4] , ans[maxn * 4] , lazy[maxn * 4];

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		mx[v] = mn[v] = pt[s];
		ans[v] = pt[s] + s;

		return;
	}

	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
	ans[v] = min(ans[2 * v] , ans[2 * v + 1]);
}

void puttag(int v , int val)
{
	mn[v] += val;
	mx[v] += val;
	ans[v] += val;
	lazy[v] += val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		puttag(2 * v , lazy[v]);
		puttag(2 * v + 1 , lazy[v]);
	}

	lazy[v] = 0;
}

void update(int l , int r , int val , int s , int e , int v)
{
	if(mn[v] > val)
		return;

	if(l <= s && e <= r && mx[v] == mn[v])
	{
		puttag(v , val - mn[v]);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;

	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
	ans[v] = min(ans[2 * v] , ans[2 * v + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> comp;

	for(int j = 0; j < 3; j++)
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][j];
			comp.pb(a[i][j]);
		}

	sort(comp.begin() , comp.end());
	comp.resize(unique(comp.begin() , comp.end()) - comp.begin());

	int m = comp.size();

	memset(frst , 63 , sizeof frst);
	for(int j = 0; j < 3; j++)
		for(int i = n; i >= 1; i--)
		{
			a[i][j] = lower_bound(comp.begin() , comp.end() , a[i][j]) - comp.begin();
			frst[a[i][j]][j] = i;
		}

	int res = 3 * n;

	int tmp = 0;
	for(int i = 0; i < m; i++)
		if(min(frst[i][0] , frst[i][1]) > n)
			tmp = max(tmp , frst[i][2]);

	for(int i = n; i >= 0; i--)
	{
		pt[i] = tmp;

		int now = a[i][1];

		if(i > 0 && frst[now][0] > n && frst[now][1] == i)
			tmp = max(tmp , frst[now][2]);
	}

	build(0 , n + 1 , 1);

	for(int i = n; i >= 0; i--)
	{
		res = min(res , i + ans[1]);

		int now = a[i][0];

		if(i > 0 && frst[now][0] == i)
		{
			if(frst[now][1] > n && frst[now][2] > n)
				break;

			int pt = min(frst[now][1] , n + 1) , val = frst[now][2];

			update(0 , pt , val , 0 , n + 1 , 1);
		}
	}

	cout << res << endl;
}