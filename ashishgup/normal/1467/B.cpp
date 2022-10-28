//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int n, sum = 0;
int a[N];

bool check(int i, int val)
{
	if(i <= 1 || i >= n)
		return 0;
	if(val > max(a[i - 1], a[i + 1]))
		return 1;
	if(val < min(a[i - 1], a[i + 1]))
		return 1;
	return 0;
}

int work(int idx, int val)
{
	int store = a[idx];
	int initialContrib = 0;
	for(int i = idx - 1; i <= idx + 1; i++)
		initialContrib += check(i, a[i]);
	a[idx] = val;
	int curVal = sum - initialContrib;
	for(int i = idx - 1; i <= idx + 1; i++)
		curVal += check(i, a[i]);
	a[idx] = store;
	return curVal;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(n <= 3)
		{
			cout << 0 << endl;
			continue;
		}
		sum = 0;
		for(int i = 2; i <= n - 1; i++)
			sum += check(i, a[i]);
		int ans = sum;
		for(int i = 1; i <= n; i++)
		{
			ans = min(ans, work(i, a[i + 1]));
			ans = min(ans, work(i, a[i - 1]));
			ans = min(ans, work(i, 0));
			ans = min(ans, work(i, 2e9));
		}
		cout << ans << endl;
	}
	return 0;
}