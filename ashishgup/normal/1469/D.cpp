#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> v, pw2;
		for(int i = 2; i <= n; i++)
		{
			if((i & (i - 1)) == 0)
			{
				pw2.push_back(i);
				continue;
			}
			v.push_back(i);
		}
		vector<pair<int, int> > ans;
		for(int i = 0; i + 1 < v.size(); i++)
			ans.push_back({v[i], v[i + 1]});
		int idx = v.back();
		while(v.back() > 1)
		{
			ans.push_back({idx, pw2.back()});
			v[v.size() - 1] = (v.back() + pw2.back() - 1) / pw2.back();
		}
		assert(ans.size() <= n + 5);
		int sz = pw2.size();
		for(int i = sz - 1; i >= 1; i--)
		{
			int j = i - 1;
			while(j - 1 >= 0 && pw2[j - 1] * pw2[j - 1] >= pw2[i])
				j--;
			for(int k = j + 1; k < i; k++)
				ans.push_back({pw2[k], pw2[k + 1]});
			int idx = pw2[i];
			while(pw2[i] > 1)
			{
				ans.push_back({idx, pw2[j]});
				pw2[i] = (pw2[i] + pw2[j] - 1) / pw2[j];
			}
			i = j + 1;
		}
		cout << ans.size() << endl;
		for(auto &it:ans)
			cout << it.first << " " << it.second << endl;
	}
	return 0;
}