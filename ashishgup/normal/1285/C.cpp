#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans;

int32_t main()
{
	IOS;
	cin >> n;
	ans = n;
	int a = 1, b = n;
	vector<int> v;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i)
			continue;
		int ct = 0, val = 1;
		while(n % i == 0)
		{
			ct++;
			n /= i;
			val *= i;
		}
		v.push_back(val);
	}
	if(n > 1)
		v.push_back(n);
	int sz = v.size();
	for(int i = 0; i < (1 << sz); i++)
	{
		int curA = 1, curB = 1;
		for(int j = 0; j < sz; j++)
		{
			if(i >> j & 1)
				curA *= v[j];
			else
				curB *= v[j];
		}
		if(curA > curB)
			swap(curA, curB);
		if(curB < b)
			a = curA, b = curB;
	}
	cout << a << " " << b;
	return 0;
}