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
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[1] == a[n / 2] && a[n / 2 + 1] == a[n] && a[1] != a[n])
	{
		cout << "YES" << endl;
		cout << a[1] << " " << a[n];
	}
	else
		cout << "NO";
	return 0;
}