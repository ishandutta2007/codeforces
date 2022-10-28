#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[1] == a[n])
	{
		cout << 0;
		return 0;
	}
	set<int> ans;
	for(int mid = 1; mid <= 100; mid++)
	{
		set<int> s;
		for(int i = 1; i <= n; i++)
			s.insert(abs(a[i] - mid));
		if(s.find(0) != s.end())
			s.erase(0);
		if(s.size() == 1)
			ans.insert(*s.begin());
	}
	if(!ans.size())
	{
		cout << "-1";
		return 0;
	}
	cout << *ans.begin();
	return 0;
}