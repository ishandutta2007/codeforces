#include <bits/stdc++.h>

using namespace std;

void fail()
{
	cout << "NO\n";
	exit(0);
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string name[n], city[n];
	map<string, int> used;
	for(int i = 0; i < n; i++)
	{
		cin >> name[i] >> city[i];
		used[name[i].substr(0, 3)]++;
	}
	string ans[n];
	map<string, int> used2;
	for(int i = 0; i < n; i++)
	{
		string n1 = name[i].substr(0, 3);
		string n2 = string(1, name[i][0]) + name[i][1] + city[i][0];
		if(used[n1] > 1)
		{
			if(used2[n2])
				fail();
			used2[n2] = true;
			ans[i] = n2;
		}
	}
	for(int z = 0; z < n; z++)
	for(int i = 0; i < n; i++)
	{
		if(!ans[i].empty())
			continue;
		string n1 = name[i].substr(0, 3);
		string n2 = string(1, name[i][0]) + name[i][1] + city[i][0];
		if(used2[n1])
		{
			if(used2[n2])
				fail();
			used2[n2] = true;
			ans[i] = n2;
		}
	}
	for(int i = 0; i < n; i++)
		if(ans[i].empty())
			ans[i] = name[i].substr(0, 3);
	cout << "YES\n";
	for(auto it: ans)
		cout << it << endl;
}