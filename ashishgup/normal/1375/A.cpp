#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

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
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(i % 2 && a[i] < 0)
				a[i] *= -1;
			if(i % 2 == 0 && a[i] > 0)
				a[i] *= -1;
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}