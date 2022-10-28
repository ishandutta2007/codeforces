#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n;
int a[N], cnt[N], prv[N];
vector<int> v = {0, 4, 8, 15, 16, 23, 42};

int32_t main()
{
	IOS;
	for(int i = 1; i < v.size(); i++)
		prv[v[i]] = v[i - 1];
	cnt[0] = 5e5;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(cnt[prv[a[i]]] > 0)
		{
			cnt[prv[a[i]]]--;
			cnt[a[i]]++;
		}
		else
			ans++;
	}	
	for(int i = 1; i + 1 < v.size(); i++)
		ans += i * cnt[v[i]];
	cout << ans;
	return 0;
}