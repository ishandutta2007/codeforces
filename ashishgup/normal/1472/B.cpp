//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int sumA = 0, sumB = 0;
		sort(a + 1, a + n + 1);
		for(int i = n; i >= 1; i--)
		{
			if(sumA <= sumB)
				sumA += a[i];
			else
				sumB += a[i];
		}
		if(sumA == sumB)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}