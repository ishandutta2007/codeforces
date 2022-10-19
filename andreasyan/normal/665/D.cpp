#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;

int n, m;
int a[1002];
vector<int> ans;
bool stg(int x)
{
	int i, j, k;
	if (x == 0) return false;
	if (x == 1) return false;
	if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (i = 3; i*i <= x; i+=2)
	{
		if (x%i==0)
			return false;
	}
	return true;
}
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] == 1)
			++m;
	}
	ans.push_back(a[0]);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (j == i)
				continue;
			if (stg(a[i] + a[j]))
			{
				ans.clear();
				ans.push_back(a[i]);
				ans.push_back(a[j]);
				goto verj;
			}
		}
	}
verj:
	if (m > ans.size())
	{
		ans.clear();
		for (i = 0; i < m; ++i)
		{
			ans.push_back(1);
		}
	}
	for (i = 0; i < n; ++i)
	{
		if (a[i] == 1)
			continue;
		if (stg(a[i] + 1))
		{
			if (m + 1 > ans.size())
			{
				ans.clear();
				ans.push_back(a[i]);
				for (i = 0; i < m; ++i)
				{
					ans.push_back(1);
				}
				goto kov;
			}
		}
	}
kov:
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << endl;
//	system("pause");
	return 0;
}