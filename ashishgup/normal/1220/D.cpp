#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], f[N], store[N];

int get(int x)
{
	int cnt = 0;
	while(x % 2 == 0)
	{
		x /= 2;
		cnt++;
	}	
	return cnt;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int cnt = get(a[i]);
		store[i] = cnt;
		f[cnt]++;
	}
	int ans = n + 1, save = -1;
	for(int i = 0; i <= 200; i++)
	{
		if(n - f[i] < ans)
		{
			ans = n - f[i];
			save = i;
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++)
	{
		if(store[i] != save)
			cout << a[i] << " ";
	}
	return 0;
}