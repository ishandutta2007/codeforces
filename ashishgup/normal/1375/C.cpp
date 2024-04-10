#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n;
int a[N], pref[N], suf[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> v;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		v.push_back(a[1]);
		for(int i = 2; i <= n; i++)
		{
			if(a[i] < v.back())
			{
				v.push_back(a[i]);
				continue;
			}
			if(v.size() == 1)
				continue;
			v.pop_back();
			v.push_back(a[i]);
			while(v.size() >= 3 && v[v.size() - 1] >= v[v.size() - 2])
			{
				int x = v.back();
				v.pop_back();
				v.pop_back();
				v.push_back(x);
			}
			if(v.size() == 2 && v[v.size() - 1] >= v[v.size() - 2])
				v.pop_back();
		}
		if(v.size() == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}