#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.second < p2.second;
}

int n;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++) //{minBuy, discountBuy}
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1, comp);
	int price = 0, have = 0;
	int l = 1, r = n;
	while(l <= r)
	{
		int reqd = a[l].second - have;
		reqd = max(0LL, reqd);
		int take = min(a[r].first, reqd);
		a[r].first -= take;
		price += 2 * take;
		have += take;
		if(a[r].first == 0)
			r--;
		else
		{
			have += a[l].first;
			price += a[l].first;
			l++;
		}
	}
	cout << price;
	return 0;
}