#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int k;
vector<char> v = {'a', 'e', 'i', 'o', 'u'};

int32_t main()
{
	IOS;
	cin >> k;
	int r = -1, c = -1;
	for(int i = 5; i * i <= k; i++)
	{
		if(k % i == 0 && k / i >= 5)
		{
			r = i;
			c = k / i;
			break;
		}
	}
	if(r == -1)
	{
		cout << "-1";
		return 0;
	}
	for(int i = 0; i < r; i++)	
	{
		for(int j = 0; j < c; j++)
		{
			int cur = (i + j) % 5;
			cout << v[cur];
		}
	}
	return 0;
}