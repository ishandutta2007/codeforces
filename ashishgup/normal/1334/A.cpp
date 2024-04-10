#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int p[N], c[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int flag = 1;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i] >> c[i];
			flag &= (p[i] >= c[i]);
			flag &= (p[i] >= p[i - 1]);
			flag &= (p[i] - p[i - 1] >= c[i] - c[i - 1]);
			flag &= (c[i] >= c[i - 1]);
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}