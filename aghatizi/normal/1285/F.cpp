#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))

const int maxn = 1e5 + 20;

int t[maxn] , a[maxn] , mul[1000] , bc[1000];

vector<int> pr[maxn] , d[maxn] , query[maxn];

int L[maxn] , R[maxn] , mid[maxn];

bool has[maxn];

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

ll res;

void solve(int n , int tmp)
{
	for(int i = 1; i <= n; i++)
		L[i] = 1 , R[i] = n + 1;

	bool stop = 0;
	for(int i = n; i >= 1; i--)
		if(has[i])
		{
			if(has[i - 1])
				res = max(res , 1LL * tmp * i * (i - 1)) , stop = 1;
			break;
		}

	if(stop)
		return;

	for(int _ = 0; ; _++)
	{
		bool f = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!has[i])
				continue;
			if(R[i] - L[i] <= 1)
				continue;

			f = 1;
			mid[i] = (L[i] + R[i]) / 2;
			query[mid[i]].pb(i);
		}

		if(!f)
			break;

		memset(t , 0 , sizeof t);
		for(int i = n; i >= 1; i--)
		{
			if(has[i])
				add(i);
			for(auto ind : query[i])
			{
				if(get(ind))
					L[ind] = mid[ind];
				else
					R[ind] = mid[ind];
			}
			query[i].clear();
		}
	}

	for(int i = 1; i <= n; i++)
		if(has[i] && has[L[i]])
			res = max(res , 1LL * i * L[i] * tmp);
}

vector<int> num[maxn];
bool where[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i < maxn; i++)
		if(!pr[i].size())
			for(int j = i; j < maxn; j += i)
				pr[j].pb(i);
	int n = 100000;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		//a[i] = (i + 1);
		cin >> a[i];
		where[a[i]] = 1;
	}

	memset(has , 0 , sizeof has);
	for(int i = 1; i < maxn; i++)
	{
		for(int j = i; j < maxn; j += i)
			if(where[j])
				has[j / i] = 1;

		solve((maxn - 5) / i , i);
		for(int j = i; j < maxn; j += i)
			has[j / i] = 0;
	}

	cout << res << endl;
}