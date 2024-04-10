#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n;
pair<int, int> store[N];

void work()
{
	for(int i = 1; i <= n; i++)
	{
		store[i].second = i;
		for(int j = 2; i * j <= n; j++)
			store[i * j].first = i;
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	work();
	sort(store + 1, store + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, store[i].first);
		if(i >= 2)
			cout << ans << " ";
	}
	return 0;
}