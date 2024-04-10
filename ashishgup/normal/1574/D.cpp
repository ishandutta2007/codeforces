#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;

int n, val = 0;
int c[N];
set<vector<int> > hashes;
vector<int> a[N];
vector<int> banned[N];
vector<int> cur, answer;

bool recurse(int idx, int sum)
{
	if(idx > n)
	{
		if(sum <= val)
			return hashes.find(cur) == hashes.end();
		if(hashes.find(cur) == hashes.end())
		{
			val = sum;
			answer = cur;
			return 1;
		}
		return 0;
	}
	bool ans = 1;
	for(int i = c[idx] - 1; i >= 0; i--)
	{
		cur.push_back(i + 1);
		bool store = recurse(idx + 1, sum + a[idx][i]);
		cur.pop_back();
		ans &= (i + 1 == c[idx]);
		ans &= store;
		if(store)
			break;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		vector<int> cur;
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			cur.push_back(x);
		}
		hashes.insert(cur);
	}
	recurse(1, 0);
	for(auto &it:answer)
		cout << it << " ";
	cout << endl;
	return 0;
}