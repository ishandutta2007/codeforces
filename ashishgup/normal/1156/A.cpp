#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - 1; i++)
	{
		int inside = a[i + 1];
		int outside = a[i];
		if(inside == 1 && outside == 2)
			ans += 3;
		if(inside == 1 && outside == 3)
			ans += 4;
		if(inside == 2 && outside == 1)
			ans += 3;
		if(inside == 2 && outside == 3)
		{
			cout << "Infinite";
			return 0;
		}	
		if(inside == 3 && outside == 1)
			ans += 4;
		if(inside == 3 && outside == 2)
		{
			cout << "Infinite";
			return 0;
		}
	}
	for(int i = 1; i + 2 <= n; i++)
		if(a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2)
			ans--;
	cout << "Finite" << endl;
	cout << ans;
	return 0;
}