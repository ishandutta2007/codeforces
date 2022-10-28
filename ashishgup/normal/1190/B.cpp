#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> f;

//freq >= 3: Lose
//freq >= 2 for 2: Lose
//All 0: Lose
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	if(f.count(0) && f[0] >= 2)
	{
		cout << "cslnb";
		return 0;
	}
	int two = 0;
	for(auto &it:f)
	{
		if(f.find(it.first - 1) != f.end() && it.second >= 2)
		{
			cout << "cslnb";
			return 0;
		}
		if(it.second >= 3)
		{
			cout << "cslnb";
			return 0;
		}
		two += (it.second == 2);
	}
	if(two >= 2)
	{
		cout << "cslnb";
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < i - 1)
		{
			cout << "cslnb";
			return 0;
		}
	}
	int parity = 0;
	for(int i = 1; i <= n; i++)
		parity += (a[i] - (i - 1));
	if(parity % 2)
		cout << "sjfnb";
	else
		cout << "cslnb";
	return 0;
}