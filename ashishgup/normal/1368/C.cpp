#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	v.push_back({0, 0});
	for(int i = 1; i <= n + 1; i++)
	{
		int off = 2 * (i - 1);
		for(int j = 0; j <= 2; j++)
		{
			for(int k = 0; k <= 2; k++)
			{
				if(j + k == 0 || (j == 1 && k == 1))
					continue;
				v.push_back({off + j, off + k});
			}
		}
	}
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it.first << " " << it.second << endl;
	return 0;
}