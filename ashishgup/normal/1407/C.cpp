#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int ans[N];

int query(int x, int y)
{
	cout << "? " << x << " " << y << endl;
	int ans;
	cin >> ans;
	return ans;
}

void report()
{
	cout << "! ";
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int32_t main()
{
	IOS;
	cin >> n;
	set<int> s, idx;
	for(int i = 1; i <= n; i++)
	{
		s.insert(i);
		idx.insert(i);
	}
	while(idx.size() >= 2)
	{
		int x = *idx.begin();
		idx.erase(x);
		int y = *idx.begin();
		idx.erase(y);
		int val1 = query(x, y);
		int val2 = query(y, x);
		if(val1 > val2)
		{
			ans[x] = val1;
			idx.insert(y);
			s.erase(val1);
		}
		else
		{
			ans[y] = val2;
			idx.insert(x);
			s.erase(val2);
		}
	}
	ans[*idx.begin()] = *s.begin();
	report();
	return 0;
}