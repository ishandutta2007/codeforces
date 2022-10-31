#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	ll a, b, c;
	cin >> a >> b >> c;
	
	vector < ll > ans;
	for (ll i = 1; i <= 85; i++)
	{
		ll d = 1;
		for (int j = 0; j < a; j++)
			d *= i;
		ll x = d * b + c;
		ll xx = x;
		if (x < 0)
			continue;
		ll sum = 0;
		while (xx)
		{
			sum += xx % 10;
			xx /= 10;
		}
		if (i == sum && x < 1000000000LL && x > 0)
			ans.pb(x);
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	
	return 0;
}