#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], b[N];

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
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		if(a[1] != b[1])
		{
			cout << "NO" << endl;
			continue;
		}
		int pos = 0, neg = 0, flag = 1;
		pos |= (a[1] > 0);
		neg |= (a[1] < 0);
		for(int i = 2; i <= n; i++)
		{
			if(a[i] != b[i])
			{
				if(b[i] - a[i] > 0 && !pos)
					flag = 0;
				if(a[i] - b[i] > 0 && !neg)
					flag = 0;
			}
			pos |= (a[i] > 0);
			neg |= (a[i] < 0);
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}