#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e6 + 5;

int n;
int a[N], f[N];
int sieve[N];

int32_t main()
{
	IOS;
	cin >> n;
	fill(sieve + 2, sieve + N, 1);
	for(int i = 2; i < N; i++)
	{
		for(int j = 2; i * j < N; j++)
			sieve[i * j] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	int ans = 0;
	int ones = f[1];
	if(ones > 0)
	{
		for(int i = 3; i < N; i++)
		{
			if(sieve[i] && f[i - 1])
			{
				cout << ones + 1 << endl;
				for(int j = 1; j <= ones; j++)
					cout << 1 << " ";
				cout << i - 1;
				return 0;
			}
		}
		if(ones > 1)
		{
			cout << ones << endl;
			for(int j = 1; j <= ones; j++)
				cout << 1 << " ";
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(sieve[a[i] + a[j]])
			{
				cout << 2 << endl;
				cout << a[i] << " " << a[j];
				return 0;
			}
		}
	}
	cout << 1 << endl;
	cout << a[1];
	return 0;
}