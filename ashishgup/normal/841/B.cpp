#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	int flag = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		flag &= (a[i] % 2 == 0);
	}
	if(flag)
		cout << "Second";
	else
		cout << "First";
	return 0;
}