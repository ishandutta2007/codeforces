#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int a, b;
 
int get(int x)
{
	int ans = (a - x + 1) * (a - x + 1) + x - 1;
	int val = b / (x + 1);
	int rem = b % (x + 1);
	ans -= ((val + 1) * (val + 1) * rem + val * val * ((x + 1) - rem));
	return ans;
}
 
int32_t main()
{
	IOS;
	cin >> a >> b;
	if(a == 0)
	{
		cout << -b * b << endl;
		for(int i = 1; i <= b; i++)
			cout << "x";
		cout << endl;
		return 0;
	}
	int best = 1, bval = -1e18;
	for(int i = 1; i <= min(a, b + 1); i++)
	{
		int cur = get(i);
		if(cur > bval)
		{
			bval = cur;
			best = i;
		}
	}
	cout << bval << endl;
	int x = best;
	int val = b / (x + 1);
	int rem = b % (x + 1);
	for(int i = 1; i <= x; i++)
	{
		for(int j = 1; j <= val + (rem > 0); j++)
			cout << "x";
		rem--;
		if(i == 1)
			for(int j = 1; j <= a - x + 1; j++)
				cout << "o";
		else
			cout << "o";
	}
	for(int j = 1; j <= val; j++)
		cout << "x";
	cout << endl;
	return 0;
}