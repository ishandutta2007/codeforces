#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin >> n;
	bool cur = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int sign = (a[i] < 0) ? -1 : 1;
		b[i] = abs(a[i]) / 2;
		b[i] *= sign;
		if(sign == -1 && a[i] % 2)
			b[i]--;
		sum += b[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] % 2 && sum < 0)
		{
			sum++;
			b[i]++;
		}
		cout << b[i] << endl;
	}
	return 0;
}