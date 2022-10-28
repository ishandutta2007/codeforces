#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], b[N], c[N];

bool check()
{
	bool check = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] != b[i])
			check = 1;
	bool check2 = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] != c[i])
			check2 = 1;
	return check & check2;
}

void work()
{
	for(int i = 1; i <= n - 1; i++)	
	{
		if(a[i] != a[i + 1])
		{
			swap(a[i], a[i + 1]);
			if(check())
			{
				cout << i << " " << i + 1;
				exit(0);
			}
			swap(a[i], a[i + 1]);
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
		c[i] = b[i];
	}
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1, greater<int>());
	work();
	cout << "-1";
	return 0;
}