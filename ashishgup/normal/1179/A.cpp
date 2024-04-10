#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, q;
deque<int> d;
int a[N], b[N], ans[N];

int32_t main()
{
	IOS;
	cin >> n >> q;
	int mx = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mx = max(mx, x);
		d.push_back(x);
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = d.front();
		d.pop_front();
		b[i] = d.front();
		d.pop_front();
		d.push_front(max(a[i], b[i]));
		d.push_back(min(a[i], b[i]));
	}
	d.pop_front();
	for(int i = 0; i <= n - 2; i++)
	{
		ans[i] = d.front();
		d.pop_front();
	}
	while(q--)
	{
		int x;
		cin >> x;	
		if(x <= n)
			cout << a[x] << " " << b[x] << endl;
		else
		{
			int idx = x - n;
			idx--;
			idx %= (n - 1);
			cout << mx << " " << ans[idx] << endl;
		}
	}	
	return 0;
}