#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 42, logn = 2 * 30, inf = 1e9 + 42;
int L[maxn * logn], R[maxn * logn], mx[maxn * logn];
int sz = 2;

int make(int &v)
{
	if(!v)
		v = sz++;
	return v;
}

void upd(int p, int c, int v = 1, int l = 0, int r = inf)
{
	mx[v] = max(mx[v], c);
	if(r - l == 1)
		return;
	int m = (l + r) / 2;
	if(p < m)
		upd(p, c, make(L[v]), l, m);
	else
		upd(p, c, make(R[v]), m, r);
}

int get(int a, int b, int v = 1, int l = 0, int r = inf)
{
	if(a <= l && r <= b)
		return mx[v];
	if(r <= a || b <= l)
		return -1;
	int m = (l + r) / 2;
	return max(get(a, b, L[v], l, m), get(a, b, R[v], m, r));
}

int main() 
{
	memset(mx, -1, sizeof(mx));
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int r[n], a[n];
	for(auto &it: r)
		cin >> it;
	for(auto &it: a)
		cin >> it;
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int a, int b){return r[a] < r[b];});
	ordered_set me;
	int sz[n];
	for(int i = 0; i < n; i++)
	{
		me.insert({a[p[i]], i});
		sz[p[i]] = me.order_of_key({a[p[i]] + k + 1, 0}) - me.order_of_key({a[p[i]] - k, 0});
	}
	int q;
	cin >> q;
	int ans[q];
	int x[q], y[q];
	map<int, vector<int>> que;
	for(int i = 0; i < q; i++)
	{
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
		if(a[x[i]] > a[y[i]])
			swap(x[i], y[i]);
		que[max(r[x[i]], r[y[i]])].push_back(i);
	}
	reverse(p, p + n);
	for(auto it: p)
	{
		upd(a[it], sz[it]);
		for(auto jt: que[r[it]])
			ans[jt] = get(a[y[jt]] - k, a[x[jt]] + k + 1);
	}
	for(auto it: ans)
		cout << it << ' ';
	
}