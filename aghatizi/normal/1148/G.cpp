#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))

const int maxn = 1e5 + 20;
const int maxa = 1e7 + 20;

int p[maxa] , t[maxa] , a[maxn] , mul[1000] , bc[1000];

vector<int> pr[maxn] , query[maxn];

int L[maxn] , R[maxn] , mid[maxn];

bool is[maxn] , added[maxn];

int get(int ind)
{
	int m = pr[ind].size();

	for(int i = 0; i < m; i++)
		mul[1 << i] = pr[ind][i] , bc[1 << i] = 1;

	mul[0] = 1;

	int res = 0;
	for(int mask = 0; mask < (1 << m); mask++)
	{
		mul[mask] = mul[mask ^ lb(mask)] * mul[lb(mask)];
		bc[mask] = bc[mask ^ lb(mask)] + bc[lb(mask)];

		if(bc[mask] % 2 == 0)
			res += t[mul[mask]];
		else
			res -= t[mul[mask]];
	}

	return res;
}

void add(int ind)
{
	int m = pr[ind].size();

	for(int i = 0; i < m; i++)
		mul[1 << i] = pr[ind][i];

	mul[0] = 1;
	for(int mask = 0; mask < (1 << m); mask++)
	{
		mul[mask] = mul[mask ^ lb(mask)] * mul[lb(mask)];
		t[mul[mask]]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i < maxa; i++)
		if(!p[i])
		{
			p[i] = i;
			for(ll j = 1LL * i * i; j < maxa; j += i)
				p[j] = i;
		}

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		int val = a[i];
		while(a[i] > 1)
		{
			int k = p[a[i]];
			while(a[i] % k == 0)
				a[i] /= k;

			pr[i].pb(k);
		}
		a[i] = val;

		L[i] = -1 , R[i] = n - 1;
		add(i);
	}

	vector<int> shit;

	int later = -1;
	for(int i = 0; i < n; i++)
	{
		int val = get(i);
		if(val == 0)
		{
			is[i] = 1;
			shit.pb(i);
		}
		if(val >= 2)
			later = i;
	}

	if((int)shit.size() >= k)
	{
		for(int i = 0; i < k; i++)
			cout << shit[i] + 1 << " ";
		cout << endl;
		return 0;
	}

	for(int _ = 0; ; _++)
	{
		bool f = 0;
		for(int i = 0; i < n; i++)
		{
			if(is[i] || R[i] - L[i] <= 1)
				continue;

			f = 1;
			mid[i] = (L[i] + R[i]) / 2;
			query[mid[i]].pb(i);
		}

		if(!f)
			break;

		memset(t , 0 , sizeof t);
		for(int i = 0; i < n; i++)
		{
			if(!is[i])
				add(i);
			for(auto ind : query[i])
			{
				if(get(ind))
					R[ind] = mid[ind];
				else
					L[ind] = mid[ind];
			}
			query[i].clear();
		}
	}

	vector<int> ans;
	if(k % 2)
	{
		if(later == -1)
		{
			ans = shit;
			for(int i = 0; i < n; i++)
				if(!is[i] && !added[i] && !added[R[i]])
				{
					added[i] = 1;
					added[R[i]] = 1;
					ans.pb(i);
				}
		}
		else
		{
			vector<int> tmp;
			for(int i = 0; i < n; i++)
				if(__gcd(a[later] , a[i]) == 1)
					tmp.pb(i);

			ans.pb(later);
			ans.pb(tmp[0]);
			ans.pb(tmp[1]);
			added[later] = added[tmp[0]] = added[tmp[1]] = 1;
		}
	}

	for(int i = 0; i < n; i++)
		if(!is[i] && !added[i] && !added[R[i]])
		{
			ans.pb(R[i]);
			ans.pb(i);
			added[i] = added[R[i]] = 1;
		}

	for(int i = 0; i < n; i++)
		if(!is[i] && !added[i])
			ans.pb(i);

	for(int i = 0; i < k; i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
}