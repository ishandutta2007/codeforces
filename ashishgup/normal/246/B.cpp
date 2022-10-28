#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n == 0)
		cout << n;
	else
		cout << n - 1;
	return 0;
}