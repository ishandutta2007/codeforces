#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ct0 = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ct0 += a[i] == 0;
		}
		if(ct0 >= n / 2)
		{
			cout << ct0 << endl;
			for(int i = 1; i <= ct0; i++)
				cout << 0 << " ";
			cout << endl;
			continue;
		}
		int k = n - ct0;
		if(k % 2)
			k--;
		cout << k << endl;
		for(int i = 1; i <= k; i++)
			cout << 1 << " ";
		cout << endl;
	}
	return 0;
}