#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
char dig[N];
int a[N], col[N];
vector<int> g[15];

bool isSorted(vector<int> &v)
{
	if(!v.size())
		return 1;
	int cur = v[0];
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i] < cur)
			return 0;
		cur = v[i];
	}
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int mx = 0;
		for(int i = 0; i <= 9; i++)
			g[i].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> dig[i];
			a[i] = dig[i] - '0';
			col[i] = 0;
			g[a[i]].push_back(i);
		}
		for(int i = 0; i <= 9; i++)
			sort(g[i].rbegin(), g[i].rend());
		int color = 2, cur = n, changed = 0;
		for(int i = 9; i >= 0; i--)
		{
			bool flag = 0;
			for(auto &it:g[i])
			{
				if(it <= cur)
				{
					cur = it;
					col[it] = color;
				}
				else if(changed == 0)
				{
					changed++;
					for(auto &j:g[i])
					{
						if(j <= cur)
						{
							cur = j;
							col[j] = color;
						}
					}
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
		color = 1, cur = n;
		for(int i = 9; i >= 0; i--)
		{
			for(auto &it:g[i])
			{
				if((col[it] == 0) && it <= cur)
				{
					cur = it;
					col[it] = color;
				}
			}
		}
		bool check = 1;
		for(int i = 1; i <= n; i++)
			check &= (col[i] > 0);
		if(check)
		{
			for(int i = 1; i <= n; i++)
				cout << col[i];
			cout << endl;
		}
		else
			cout << "-" << endl;
	}
	return 0;
}