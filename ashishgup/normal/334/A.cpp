#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int val = j * n + (j + i) % n;
			cout << val + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}