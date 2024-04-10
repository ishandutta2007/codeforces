#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int from[maxn] , to[maxn] , w[maxn] , par[maxn] , sz[maxn] , ind[maxn];

int x[maxn];

bool cmp(int a , int b)
{
	return w[a] < w[b];
}

int fn(int v)
{
	return (par[v] < 0? v : par[v] = fn(par[v]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < k; i++)
	{
		cin >> x[i];
		x[i]--;

		sz[x[i]] = 1;
	}

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		from[i] = a , to[i] = b , ind[i] = i;
	}

	sort(ind , ind + m , cmp);

	int ans = -1;
	for(int i = 0; i < m; i++)
	{
		int x = ind[i];

		int a = fn(from[x]) , b = fn(to[x]);
		if(a == b)
			continue;

		if(sz[a] + sz[b] == k && sz[a] && sz[b])
			ans = w[x];

		sz[a] += sz[b];
		par[b] = a;
	}

	for(int i = 0; i < k; i++)
		cout << ans << " ";
	cout << endl;
}