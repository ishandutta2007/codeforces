#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 7005;
 
int n, ans = 0;
int a[N], b[N], mark[N];
map<int, int> f;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
	{
		if(f[a[i]] > 1)
			mark[i] = 1;
		if(!mark[i])
			continue;
		for(int j = 1; j <= n; j++)
			if((a[i] & a[j]) == a[j])
				mark[j] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(mark[i])
			ans += b[i];
	cout << ans;
	return 0;
}