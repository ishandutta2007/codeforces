#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int sum = 0;
		vector<int> v;
		for(int i = 1; i <= n; i++)
		{
			sum += a[i];
			if(sum % 2 && k > 1 && i < n)
			{	
				v.push_back(i);
				k--;
				sum = 0;
			}
		}
		v.push_back(n);
		if(sum % 2 == 0 || k > 1)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for(auto &it: v)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}