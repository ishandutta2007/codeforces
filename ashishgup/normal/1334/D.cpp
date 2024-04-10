#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, l, r;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> l >> r;
		if(l == r && r == (n * (n - 1) + 1))
		{
			cout << 1 << endl;
			continue;
		}
		int go = (r - l + 1);
		vector<int> ans;
		for(int i = 1; i <= n; i++)
		{
			int pairs = (n - i) * 2;
			if(l > pairs)
			{
				l -= pairs;
				continue;
			}
			else
			{
				int taken = max(0LL, (l - 1) / 2);
				int v = i + 1 + taken;
				l %= 2;
				vector<int> temp = {i, v};
				vector<int> store = {i, v};
				int idx;
				if(l % 2)
					idx = 0;
				else
					idx = 1;
				for(int i = 1; i <= go; i++)
				{
					cout << temp[idx] << " ";
					if(idx == 1)
					{
						temp[idx]++;
						if(temp[idx] > n)
						{
							temp[0]++;
							if(temp[0] == n)
								temp[0] = 1;
							temp[idx] = temp[0] + 1;
						}
					}
					idx ^= 1;
				}
				cout << endl;
				break;
			}
		}
	}	
	return 0;
}