//Similar to my problem: https://codeforces.com/contest/1451/problem/E1

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int askAnd(int i, int j)
{
	cout << "and " << i << " " << j << endl;
	int x;
	cin >> x;
	return x;
}

int askOr(int i, int j)
{
	cout << "or " << i << " " << j << endl;
	int x;
	cin >> x;
	return x;
}

int finish(int x)
{
	cout << "finish " << x << endl;
	exit(0);
}

int a[N];

int32_t main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	int sumAB = askAnd(1, 2) + askOr(1, 2);
	int sumAC = askAnd(1, 3) + askOr(1, 3);
	int sumBC = askAnd(2, 3) + askOr(2, 3);
	int sumABC = (sumAB + sumBC + sumAC) / 2;
	a[1] = sumABC - sumBC;
	a[2] = sumABC - sumAC;
	a[3] = sumABC - sumAB;
	for(int i = 4; i <= n; i++)
	{
		int sum = askAnd(1, i) + askOr(1, i);
		a[i] = sum - a[1];
	}
	sort(a + 1, a + n + 1);
	finish(a[k]);
	return 0;
}