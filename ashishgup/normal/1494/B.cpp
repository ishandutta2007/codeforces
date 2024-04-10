#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, u, r, d, l;
		cin >> n >> u >> r >> d >> l;
		vector<int> v = {u, r, d, l};
		int ans = 0;
		for(int mask = 0; mask < (1 << 4); mask++)
		{
			vector<int> nv = v;
			for(int i = 0; i < 4; i++)
			{
				if(mask >> i & 1)
				{
					nv[i]--;
					nv[(i + 1) % 4]--;
				}
			}
			int flag = 1;
			for(auto &it:nv)
			{
				if(it < 0 || it > n - 2)
					flag = 0;
			}
			if(!flag)
				continue;
			ans = 1;
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}