#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int maxs = 1e6;
	int used[maxs];
	memset(used, 0, sizeof(used));
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		used[x - 1] = 1;
	}
	vector<int> free;
	vector<int> ans;
	int cnt = 0;
	for(int i = 0; 2 * i < maxs; i++)
	{
		if(used[i] == 0 && used[maxs - i - 1] == 0)
			free.push_back(i);
		if(used[i] == 0 && used[maxs - i - 1] == 1)
			ans.push_back(i + 1);
		if(used[i] == 1 && used[maxs - i - 1] == 0)
			ans.push_back(maxs - i);
		if(used[i] == 1 && used[maxs - i - 1] == 1)
			cnt++;
	}
	for(int i = 0; i < cnt; i++)
	{
		ans.push_back(free[i] + 1);
		ans.push_back(maxs - free[i]);
	}
	cout << ans.size() << "\n";
	for(auto it: ans)
		cout << it << ' ';
}