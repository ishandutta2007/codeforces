#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n;
int a[N], l[N];

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
		multiset<int> s;
		for(int i = 1; i <= n; i++)
		{
			cin >> l[i];
			if(l[i] == 0)
				s.insert(a[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			if(l[i])
				cout << a[i] << " ";
			else
			{
				cout << *s.rbegin() << " ";
				s.erase(--s.end());
			}
		}
		cout << endl;
	}
	return 0;
}