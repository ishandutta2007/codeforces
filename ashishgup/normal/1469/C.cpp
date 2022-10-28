#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, k;
int l[N], r[N], store[N];
pair<int, int> a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
			store[i] = a[i].first;
			l[i] = -1;
			r[i] = -1;
		}
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		bool flag = 1;
		for(int i = 1; i <= n; i++)
		{
			int idx = a[i].second;
			int lo = a[i].first;
			if(idx - 1 >= 1 && l[idx - 1] != -1)
				lo = max(lo, l[idx - 1] + 1 - k);
			if(idx + 1 <= n && l[idx + 1] != -1)
				lo = max(lo, l[idx + 1] + 1 - k);
			l[idx] = lo, r[idx] = lo + k;
		}
		for(int i = 1; i + 1 <= n; i++)
		{
			int mxL = max(l[i], l[i + 1]);
			int mnR = min(r[i], r[i + 1]);
			if(mnR - mxL < 1)
				flag = 0;
		}
		if(l[1] != store[1] || l[n] != store[n])
			flag = 0;
		for(int i = 2; i <= n - 1; i++)
		{
			if(l[i] > store[i] + k - 1)
				flag = 0;
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}