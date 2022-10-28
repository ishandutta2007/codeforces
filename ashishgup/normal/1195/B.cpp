#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, k;

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int x = 1;; x++)
	{
		int moves = x;
		int rem = n - x;
		if(rem < 0)
			break;
		int have = x * (x + 1) / 2 - rem;
		if(have == k)
		{
			cout << rem << endl;
			return 0;
		}
	}
	return 0;
}