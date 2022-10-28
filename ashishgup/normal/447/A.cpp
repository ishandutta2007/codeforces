#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 305;
 
int p, n;
int a[N];
 
int32_t main()
{
	IOS;
	cin >> p >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x % p]++;
		if(a[x % p] > 1)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}