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
		vector<int> ct(2, 0);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(a[i] % 2 != i % 2)
				ct[i % 2]++;
		}
		if(ct[0] != ct[1])
			cout << -1 << endl;
		else
			cout << ct[0] << endl;
	}
	return 0;
}