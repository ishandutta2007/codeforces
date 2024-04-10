#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int M = 35;
const int MOD = 998244353;

int n, m;
int a[N], b[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

struct Gauss 
{
	int bits;
	vector<int> table;
	
	Gauss(int bit) 
	{
		bits = bit;
		table = vector<int> (bits, 0);
	}

	int size() 
	{
		int ans = 0;
		for(int i = 0; i < bits; i++) 
		{
			if(table[i]) 
				ans++;
		}
		return ans;
	}

	bool can(int x) 
	{
		for(int i = bits-1; i >= 0; i--) 
			x = min(x, x ^ table[i]);
		return x == 0;
	}

	void add(int x) 
	{
		for(int i = bits-1; i >= 0 && x; i--) 
		{
			if(table[i] == 0) 
			{
				table[i] = x;
				x = 0;
			} 
			else 
				x = min(x, x ^ table[i]);
		}
	}

	int getBest() 
	{
		int x = 0;
		for(int i = bits-1; i >= 0; i--) 
			x = max(x, x ^ table[i]);
		return x;
	}

	void merge(Gauss &other)
	{
		for(int i = bits-1; i >= 0; i--)
			add(other.table[i]);
	}
};

int f2[1 << 15];
int ans[50];
int cnt[1 << 15];
int store[1 << 15][36], store2[1 << 15][36];

int32_t main()
{
	IOS;
	cin >> n >> m;
	Gauss g(m);
	for(int i = 1; i <= n; i++)	
	{
		cin >> a[i];
		g.add(a[i]);
	}
	vector<int> v;
	vector<int> table;
	set<int> s;
	for(int i = 0; i < m; i++)
		s.insert(g.table[i]);
	for(int msb = m - 1; msb >= 0; msb--)
	{
		int val = 0;
		for(auto &it:s)
		{
			if(it >> msb & 1)
				val = it;
		}
		s.erase(val);
		table.push_back(val);
	}
	for(int i = 0; i < m; i++)
		v.push_back(table[i]);
	int x = 2 * m / 3;
	int y = m - x;
	vector<int> v2;
	for(int i = 0; i < x; i++)
		v2.push_back(v[i]);
	for(int i = 0; i < (1 << x); i++)
	{
		int cur = 0;
		int flag = 1;
		for(int j = 0; j < x; j++)
		{
			if(i >> j & 1)
			{
				if(v2[j] == 0)
				{
					flag = 0;
					break;
				}
				cur ^= v2[j];
			}
		}
		if(flag)
		{
			int rhs = cur & ((1 << y) - 1);
			int lhs = cur >> y;
			store2[rhs][__builtin_popcount(lhs)]++;
		}
	}
	for(int i = 0; i < (1 << 15); i++)
		cnt[i] = __builtin_popcount(i);
	v2.clear();
	for(int i = x; i < m; i++)
	{
		int val = v[i];
		v2.push_back(val);
	}
	for(int i = 0; i < (1 << y); i++)
	{
		int cur = 0;
		int flag = 1;
		for(int j = 0; j < y; j++)
		{
			if(i >> j & 1)
			{
				if(v2[j] == 0)
					flag = 0;
				cur ^= v2[j];
			}
		}
		if(flag)
			f2[cur]++;
	}
	for(int i = 0; i < (1 << y); i++)
	{
		for(int j = 0; j < (1 << y); j++)
		{
			int x = i ^ j;
			store[i][cnt[x]] += f2[j];	
		}
	}
	for(int i = 0; i < (1 << y); i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= m; k++)
			{
				int setBits = j + k;
				int ways = store2[i][j] * store[i][k];
				ways %= MOD;
				ans[setBits] += ways;
				ans[setBits] %= MOD;	
			}
		}
	}
	for(int i = 0; i <= m; i++)
	{
		ans[i] *= pow(2LL, n - g.size(), MOD);
		ans[i] %= MOD;
		cout << ans[i] << " ";
	}
	return 0;
}