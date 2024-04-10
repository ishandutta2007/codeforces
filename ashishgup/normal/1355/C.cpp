#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int a, b, c, d, ans = 0;
int cnt[N];

int get(int x)
{
	int mx = x - 1;
	mx = min(mx, d);
	if(mx < c)
		return 0;
	return mx - c + 1;
}

int32_t main()
{
	IOS;
	cin >> a >> b >> c >> d;
	for(int x = a; x <= b; x++)
	{
		cnt[x + b]++;
		cnt[x + c + 1]--;
	}
	for(int i = 1; i <= 1e6; i++)
	{
		cnt[i] += cnt[i - 1];
		ans += cnt[i] * get(i);
	}
	cout << ans;
	return 0;
}