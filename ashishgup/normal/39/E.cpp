#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
const int M = sqrt(1e9) + 5;
 
int a, b, n;
short cache[M][35], cache2[M][35];
 
short check(int a, int b)
{
	short &ans = cache[a][b];
	if(ans != -1)
		return ans;
	int val = a;
	for(int i = 2; i <= b; i++)
	{
		val *= a;
		if(val >= n)
			return ans = 0;
	}
	return ans = 1;
}
 
short dp(int a, int b)
{
	if(!check(a, b))
		return 1;
	if(check(a, b) && !check(a, b + 1) && a == 1)
		return 2;
	if(a * a >= n)
		return ((n - a) % 2 == 0);
	short &ans = cache2[a][b];
	if(ans != -1)
		return ans;
	ans = 2;
	if(dp(a + 1, b) == 0 || dp(a, b + 1) == 0)
		ans = 1;
	else if(dp(a + 1, b) == 1 && dp(a, b + 1) == 1)
		ans = 0;
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> a >> b >> n;
	int ans = dp(a, b);
	if(ans == 0)
		cout << "Stas";
	else if(ans == 1)
		cout << "Masha";
	else
		cout << "Missing";
	return 0;
}