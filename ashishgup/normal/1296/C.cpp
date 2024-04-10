#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
char a[N];

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
		map<pair<int, int>, int> m;
		m[{0, 0}] = 0;
		int l = 0, u = 0;
		int flag = 0;
		int L = 0, R = 1e9;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 'L')
				l++;
			else if(a[i] == 'R')
				l--;
			else if(a[i] == 'U')
				u++;
			else
				u--;
			if(m.find({l, u}) != m.end())
			{
				int curR = i, curL = m[{l, u}];
				if(curR - curL < R - L)
				{
					L = curL + 1;
					R = curR;
					flag = 1;
				}
			}
			m[{l, u}] = i;
		}
		if(flag)
			cout << L << " " << R << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}