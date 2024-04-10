#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n * n];
	int used[n * n];
	memset(used, 0, sizeof(used));
	map<int, int> cnt;
	for(auto &it: a)
		cin >> it, cnt[it]++;
	sort(a, a + n * n, greater<int>());
	vector<int> ans(1, a[0]);
	cnt[a[0]]--;
	for(int i = 1; i < n * n; i++)
	{
		if(cnt[a[i]])
		{
			for(auto it: ans)
				cnt[__gcd(a[i], it)] -= 2;
			ans.push_back(a[i]);
			cnt[a[i]]--;
		}
	}
	for(auto it: ans)
		cout << it << ' ';
}