#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e2 + 20;

int a[maxn];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int s = 0 , mx = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];

		mx = max(mx , a[i]);
	}

	for(int i = mx; ; i++)
		if(n * i - s > s)
			return cout << i << endl , 0;
}