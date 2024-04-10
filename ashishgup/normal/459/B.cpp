#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n;
int a[N];
map<int, int> m;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if(m.size() == 1)
		cout << 0 << " " << n * (n - 1) / 2;
	else
	{
		int mx = m.rbegin() -> first;
		int mxF =  m.rbegin() -> second;
		int mn = m.begin() -> first;
		int mnF =  m.begin() -> second;
		cout << mx - mn << " ";
		cout << mnF * mxF;
	}
	return 0;
}