#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];
set<int> have, reqd;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		reqd.insert(a[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		have.insert(a[i]);
		if(have.size() == reqd.size())
		{
			cout << a[i];
			return 0;
		}
	}
	return 0;
}