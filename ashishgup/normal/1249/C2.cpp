#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v;
		while(n > 0)
		{
			v.push_back(n % 3);
			n /= 3;
		}
		reverse(v.begin(), v.end());
		n = v.size();
		bool done = 0;
		for(int i = 0; i < n; i++)
		{
			if(v[i] == 2)
			{
				done = 1;
				bool flag = 0;
				for(int j = i - 1; j >= 0; j--)
				{
					if(v[j] == 1)
						continue;
					v[j]++;
					flag = 1;
					for(int k = j + 1; k < n; k++)
						v[k] = 0;
					break;
				}
				if(!flag)
				{
					reverse(v.begin(), v.end());
					v.push_back(1);
					reverse(v.begin(), v.end());
					for(int i = 1; i < v.size(); i++)
						v[i] = 0;
					break;
				}
				break;
			}
		}
		int ans = 0;
		for(auto &it:v)
			ans = ans * 3 + it;
		cout << ans << endl;
	}
	return 0;
}