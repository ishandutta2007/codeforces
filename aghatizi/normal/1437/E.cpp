#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

int a[maxn] , b[maxn] , dp[maxn] , mx[maxn * 4] , n;

vector<int> pos[maxn];

void update(int p , int val , int s = 0 , int e = n + 2 , int v = 1)
{
	if(e - s < 2)
	{
		mx[v] = val;
		return;
	}

	int m = (s + e) / 2;
	if(p < m)
		update(p , val , s , m , 2 * v);
	else
		update(p , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

int get(int l , int r , int s = 0 , int e = n + 2 , int v = 1)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return -1e9;

	int m = (s + e) / 2;

	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(mx , -63 , sizeof mx);

	int k;
	cin >> n >> k;

	vector<int> cmp;
	for(int i = 1; i <= n; i++)
		cin >> a[i] , a[i] -= i , cmp.pb(a[i]);
	a[0] = -1e9;
	a[n + 1] = 2e9;

	cmp.pb(a[0]);
	cmp.pb(a[n + 1]);

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i <= n + 1; i++)
		a[i] = lower_bound(cmp.begin() , cmp.end() , a[i]) - cmp.begin() , pos[a[i]].pb(i);

	for(int i = 1; i <= k; i++)
		cin >> b[i];
	b[0] = 0;
	b[k + 1] = n + 1;

	for(int i = 0; i < (int)cmp.size(); i++)
	{
		for(auto ind : pos[i])
		{
			int x = lower_bound(b , b + k + 2 , ind) - b - 1;
			if(x < 0)
				dp[ind] = 1;
			else
				dp[ind] = get(b[x] , ind) + 1;

			update(ind , dp[ind]);
		}
	}

	int res = n + 2 - dp[n + 1];
	if(res > n)
		res = -1;

	cout << res << endl;
}