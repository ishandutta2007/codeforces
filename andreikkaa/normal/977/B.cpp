#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void t1() 
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < k; ++i)
	{
		if(n % 10 == 0)
		{
			n /= 10;
		}
		else
		{
			--n;
		}
	}
	
	cout << n << endl;
}

void t2()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	map<string, int> mp;
	for(int i = 0; i + 1 < n; ++i)
	{
		mp[s.substr(i, 2)]++;
	}
	
	int val = 0;
	for(auto i : mp)
	{
		val = max(val, i.second);
	}
	
	for(auto i : mp)
	{
		if(i.second == val)
		{
			cout << i.first << endl;
			return;
		}
	}
}

void t3()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	if(k == n)
	{
		cout << a.back() << endl;
		return;
	}
	
	if(a[k - 1] == a[k])
	{
		cout << -1 << endl;
		return;
	}
	
	cout << a[k - 1] << endl;
}

void t4()
{
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	auto p = [](ll x, int p)
	{
		int ans = 0;
		for(; x % p == 0; x /= p)
		{
			++ans;
		}
		return ans;
	};
	
	sort(a.begin(), a.end(), [&](ll a, ll b)
	{
		if(p(a, 2) != p(b, 2))
		{
			return p(a, 2) < p(b, 2);
		}
		
		return p(a, 3) > p(b, 3);
	});
	
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void t5()
{
	int n, m;
	cin >> n >> m;
	
	vector<multiset<int>> g(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		g[a].insert(b);
		g[b].insert(a);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(g[i].size() == 2)
		{
			if(*g[i].begin() == *g[i].rbegin())
			{
				++ans;
				g[*g[i].begin()].clear();
				g[i].clear();
			}
			else
			{
				g[*g[i].begin()].erase(i);
				g[*g[i].rbegin()].erase(i);
				g[*g[i].begin()].insert(*g[i].rbegin());
				g[*g[i].rbegin()].insert(*g[i].begin());
				g[i].clear();
			}
		}
	}
	cout << ans << endl;
}

void t6()
{
	int n;
	cin >> n;
	
	vector<int> ans(n);
	vector<int> prv(n);
	
	map<int, int> pos;
	
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		
		pos[x] = i;
		ans[i] = 1;
		prv[i] = -1;
		if(pos.count(x - 1))
		{
			ans[i] = ans[pos[x - 1]] + 1;
			prv[i] = pos[x - 1];
		}
	}
	
	int p = max_element(ans.begin(), ans.end()) - ans.begin();
	cout << ans[p] << endl;
	
	vector<int> a;
	for(; p != -1; p = prv[p])
	{
		a.push_back(p + 1); 
	}
	reverse(a.begin(), a.end());
	
	for(int i : a)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	t2();
}