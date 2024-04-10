#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define t first
#define b second

const int N = 1e6 + 5;

int n, k;
pair<int, int> a[N];

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.b != p2.b)
		return p1.b < p2.b;
	return p1.t < p2.t;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].t>>a[i].b;
	sort(a + 1, a + n + 1, comp);
	multiset<int> s;
	int len = 0;
	int ans = 0;
	for(int i=n;i>=1;i--)
	{	
		int beauty = a[i].b;
		int sum = len + a[i].t;
		ans = max(ans, beauty * sum);
		s.insert(a[i].t);
		len += a[i].t;
		if(s.size() >= k)
		{
			len -= *s.begin();
			s.erase(s.begin());
		}
	}
	cout<<ans;
	return 0;
}