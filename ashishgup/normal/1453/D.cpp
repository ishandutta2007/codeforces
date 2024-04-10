#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		if(k % 2)
		{
			cout << -1 << endl;
			continue;
		}
		vector<int> v;
		while(k > 0)
		{
			int cur = 2, add = 4, len = 1;
			while(cur + add <= k)
			{
				cur += add;
				add *= 2;
				len++;
			}
			v.push_back(1);
			for(int i = 2; i <= len; i++)
				v.push_back(0);
			k -= cur;
		}
		cout << v.size() << endl;
		for(auto &it:v)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}