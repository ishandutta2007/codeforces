#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans = __gcd(a[i], ans);
	}
	int cnt = 0;
	for(int i = 1; i * i <= ans; i++)
	{
		if(ans % i == 0)
		{
			cnt++;
			if(ans / i != i)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}