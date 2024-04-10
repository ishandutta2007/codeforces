#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
#define double long double

const int N = sqrt(1e9) + 2;

int pow(int a, int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a);
		b/=2;
		a=(a*a);
	}
	return ans;
}

int query(int x)
{
	cout << "? " << x << endl;
	int inp;
	cin >> inp;
	return inp;
}

void report(int x)
{
	x = max(2 * x, x + 7);
	cout << "! " << x << endl;
}

bool sieve[N];
vector<int> primes;

void precompute()
{
	for(int i = 2; i < N; i++)
		sieve[i] = 1;

	for(int i = 2; i < N; i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
			for(int j = 2; i * j < N; j++)
				sieve[i * j] = 0;
		}
	}
}

vector<int> store;
vector<pair<int, int> > keep;
map<int, int> ans;

pair<int, int> work(int idx)
{
	store.clear();
	int cur = 1;
	double val = 1;
	for(auto &it:keep)
	{
		cur *= pow(it.first, it.second);
		val *= pow(it.first, it.second);
		store.push_back(it.first);
	}
	int i;
	for(i = idx; i < primes.size(); i++)
	{
		val *= primes[i];
		if(val > 1e18 + 1)
			break;
		cur *= primes[i];
		store.push_back(primes[i]);
	}
	return {cur, i};
}

void compute(int val)
{
	keep.clear();
	for(auto &it:store)
	{
		int cnt = 0;
		while(val % it == 0)
		{
			cnt++;
			val /= it;
		}
		if(cnt > 0)
		{
			if(cnt > ans[it])
			{
				ans[it] = cnt;
				keep.push_back({it, cnt + 1});
			}
		}
	}
}

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		ans.clear();
		int idx = 0;
		for(int i = 0; i < 22; i++)
		{
			pair<int, int> p = work(idx);
			idx = p.second;
			//cout << p.first << endl;
			int val = query(p.first);
			compute(val);
		}
		int divs = 1;
		for(auto &it:ans)
			divs *= (it.second + 1);
		report(divs);
	}
	return 0;
}