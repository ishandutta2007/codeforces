#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;
 
int n, m;
int a[N], b[N];
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
		if(a[i] > b[i])
			swap(a[i], b[i]);
	}
	map<int, int> f;
	int reqd = 0;
	for(int i = 2; i <= m; i++)
	{
		int x = a[1];
		if(a[i] == x || b[i] == x)
			continue;
		reqd++;
		f[a[i]]++;
		f[b[i]]++;
	}
	if(reqd == 0)
	{
		cout << "YES";
		return 0;
	}
	for(auto &it:f)
	{
		if(it.second == reqd)
		{
			cout << "YES";
			return 0;
		}
	}
	f.clear();
	reqd = 0;
	for(int i = 2; i <= m; i++)
	{
		int x = b[1];
		if(a[i] == x || b[i] == x)
			continue;
		reqd++;
		f[a[i]]++;
		f[b[i]]++;
	}
	if(reqd == 0)
	{
		cout << "YES";
		return 0;
	}
	for(auto &it:f)
	{
		if(it.second == reqd)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}