#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, k, x;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	vector<int> v;
	int ans = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] - a[i - 1] > x)
		{
			int diff = (a[i] - a[i - 1] - x);
			int reqd = (diff + x - 1) / x;
			v.push_back(reqd);
			ans++;
		}
	}
	sort(v.begin(), v.end());
	for(auto &it:v)
	{
		if(it <= k)
		{
			k -= it;
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}