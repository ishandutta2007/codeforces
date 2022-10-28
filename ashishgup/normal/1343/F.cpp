#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 205;

struct data
{
	int sz;
	vector<int> v;
};

bool comp(data &d1, data &d2)
{
	return d1.sz < d2.sz;
}

int n;
data a[N];
int ans[N], store[N], f[N], idx[N];
bool vis[N], kept[N];
set<int> pos[N];

bool check()
{
	for(int i = 1; i <= n; i++)
		idx[ans[i]] = i;
	for(int i = 1; i <= n - 1; i++)
	{
		int last = 2;
		for(auto &it:a[i].v)
			last = max(last, idx[it]);
		int sz = a[i].sz;
		vector<int> temp;
		for(int j = last; j >= last - sz + 1; j--)
			temp.push_back(ans[j]);
		sort(temp.begin(), temp.end());
		if(temp != a[i].v)
			return 0;
	}
	return 1;
}

void update(int x)
{
	kept[x] = 1;
	for(auto &it:pos[x])
		store[it]--;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			f[i] = 0;
			pos[i].clear();
		}
		for(int i = 1; i <= n - 1; i++)
		{
			cin >> a[i].sz;
			a[i].v.clear();
			for(int j = 1; j <= a[i].sz; j++)
			{
				int x;
				cin >> x;
				f[x]++;
				a[i].v.push_back(x);
			}
		}
		sort(a + 1, a + n, comp);
		for(int i = 1; i < n; i++)
		{
			for(auto &x:a[i].v)
				pos[x].insert(i);
		}
		for(int i = 1; i < n; i++)
		{
			memset(vis, 0, sizeof(vis));
			memset(kept, 0, sizeof(kept));
			{
				for(int j = 1; j < n; j++)
					store[j] = a[j].sz;
				ans[1] = a[i].v[0];
				update(ans[1]);
				ans[2] = a[i].v[1];
				update(ans[2]);
				vis[i] = 1;
				for(int j = 3; j <= n; j++)
				{
					for(int k = 1; k < n; k++)
					{
						if(vis[k])
							continue;
						if(store[k] == 1)
						{
							vis[k] = 1;
							for(auto &it:a[k].v)
							{
								if(kept[it])
									continue;
								ans[j] = it;
								update(ans[j]);
							}
							break;
						}
					}
				}
				int flag = 1;
				for(int i = 1; i <= n - 1; i++)
					flag &= (vis[i] & kept[i]);
				if(flag && check())
					break;
				swap(ans[1], ans[2]);
				if(flag && check())
					break;
			}
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}