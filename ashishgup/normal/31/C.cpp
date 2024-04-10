#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5005;

int n;
int l[N], r[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	map<int, int> m;
	for(int i = 1; i <= n; i++)
		m[l[i]]++, m[r[i]]--;
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		m[l[i]]--;
		m[r[i]]++;
		int cur = 0;
		bool check = 1;
		for(auto &it:m)
		{
			cur += it.second;
			if(cur > 1)
				check = 0;
		}
		m[l[i]]++;
		m[r[i]]--;
		if(check)
			v.push_back(i);
	}
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it << " ";
	return 0;
}