#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int n;
int a[N], b[N];
int curA[N], curB[N];

bool check(int x)
{
	int N = n + x;
	for(int i = 1; i <= N; i++)
	{
		if(i <= n)
		{
			curA[i] = a[i];
			curB[i] = b[i];
		}
		else
		{
			curA[i] = 100;
			curB[i] = 0;
		}
	}
	sort(curA + 1, curA + N + 1);
	sort(curB + 1, curB + N + 1);
	int rem = N / 4;
	int diff = 0;
	for(int i = rem + 1; i <= N; i++)
		diff += curA[i] - curB[i];
	return diff >= 0;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

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
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		int ans = binsearch(0, 2 * n);
		cout << ans << endl;
	}
	return 0;
}