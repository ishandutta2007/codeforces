#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], in[N], ans[N];

void work(vector<int> need)
{
	int i = 1;
	for(; i <= n && need.size() > 3;i++)
	{
		if(!a[i])
		{
			if(need.back() != i)
			{
				ans[i] = need.back();
				need.pop_back();
			}
			else
			{
				int temp = need.back();
				need.pop_back();
				ans[i] = need.back();
				need.pop_back();
				need.push_back(temp);
			}
		}
		else
			ans[i] = a[i];
	}
	sort(need.begin(), need.end());
	do
	{
		int j = i;
		vector<int> cur = need;
		bool flag = 0;
		for(; j <= n; j++)
		{
			if(!a[j])
			{
				if(cur.back() != j)
				{
					ans[j] = cur.back();
					cur.pop_back();
				}
				else
					break;
			}
			else
				ans[j] = a[j];
		}
		if(!cur.size())
		{
			for(int i = 1; i <= n; i++)
				cout << ans[i] << " ";
			return;
		}
	}while(next_permutation(need.begin(), need.end()));
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		in[a[i]]++;
	}
	vector<int> need;
	for(int i = 1; i <= n; i++)
		if(!in[i])
			need.push_back(i);
	work(need);
	return 0;
}