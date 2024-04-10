#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int pw = 2; pw <= 2e9; pw *= 2)
		{
			if(m.count(pw - a[i]))
				ans += m[pw - a[i]];
		}
		m[a[i]]++;
	}
	cout << ans;
	return 0;
}