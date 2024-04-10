#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e4 + 5;
const int M = (1 << 24) + 5;

int n;
string a[N];
int f[M];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		int curmask = 0;
		set<int> s;
		for(auto &it:a[i])
			s.insert(it - 'a');
		vector<int> v;
		for(auto &it:s)
			v.push_back(it);
		int sz = v.size();
		for(int i = 1; i < (1 << sz); i++)
		{
			int curm = 0;
			int sign = -1;
			for(int j = 0; j < sz; j++)
			{
				if(i >> j & 1)
				{
					curm |= (1 << v[j]);
					sign *= -1;
				}
			}
			f[curm] += sign;
		}
	}
	int ans = 0;
	for(int i = 0; i < 24; i++)
	{
		for(int j = 0; j < (1 << 24); j++)
		{
			if(j >> i & 1)
				f[j] += f[j ^ (1 << i)]; 
		}
	}
	for(int i = 0; i < (1 << 24); i++)
		ans ^= (f[i] * f[i]);
	cout << ans;
	return 0;
}