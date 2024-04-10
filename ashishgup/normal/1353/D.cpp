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
		set<pair<int, pair<int, int> > > s;
		s.insert({-n, {1, n}});
		int cur = 0;
		while(s.size())
		{
			++cur;
			auto p = *s.begin();
			s.erase(p);
			int l = p.second.first, r = p.second.second;
			if((r - l + 1) % 2)
			{
				int m = (l + r) / 2;
				a[(l + r) / 2] = cur;
				if(l != r)
				{
					s.insert({-(m - l), {l, m - 1}});
					s.insert({-(r - m), {m + 1, r}});
				}
			}
			else
			{
				int m = (l + r - 1) / 2;
				a[m] = cur;
				if(l < m)
					s.insert({-(m - l), {l, m - 1}});
				s.insert({-(r - m), {m + 1, r}});
			}
		}
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}	
	return 0;
}