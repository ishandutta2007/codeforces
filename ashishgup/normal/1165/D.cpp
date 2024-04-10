#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 305;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		set<int> reqd;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			reqd.insert(a[i]);
		}
		sort(a + 1, a + n + 1);
		int poss = -1;
		if(n == 1)
			poss = a[1] * a[1];
		else
			poss = a[1] * a[n];
		bool check = 1;
		n = poss;
		for(int i = 2; i * i <= n; i++)
		{
			if(n % i)
				continue;
			if(reqd.find(i) == reqd.end())
			{
				check = 0;
				break;
			}
			reqd.erase(i);
			if(n / i != i)
			{
				if(reqd.find(n / i) == reqd.end())
				{
					check = 0;
					break;
				}
				reqd.erase(n / i);
			}
		}
		check &= (reqd.size() == 0);
		if(check)
			cout << n << endl;
		else
			cout << -1 << endl;
	}	
	return 0;
}