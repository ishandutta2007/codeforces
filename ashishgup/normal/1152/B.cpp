#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int check(int x)
{
	if(__builtin_popcountll(x + 1) == 1)
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	int x;
	cin >> x;
	vector<int> v;
	int reqd = 0;
	while(!check(x))
	{
		for(int i = 20; i >= 0; i--)
		{
			if(((x >> i) & 1))
			{
				reqd++;
				v.push_back(i + 1);
				x ^= ((1LL << (i + 1)) - 1);
				break;
			}
		}
		if(!check(x))
		{
			reqd++;
			x++;
		}
	}
	cout << reqd << endl;
	for(auto &it:v)
		cout << it << " ";
	return 0;
}