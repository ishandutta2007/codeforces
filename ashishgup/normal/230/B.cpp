#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int a[N];
bool sieve[N];
set<int> tprimes;

int32_t main()
{
	IOS;
	for(int i = 2; i < N; i++)
		sieve[i] = 1;
	for(int i = 2; i < N; i++)
	{
		if(sieve[i])
		{
			tprimes.insert(i * i);
			for(int j = 2; i * j < N; j++)
				sieve[i * j] = 0;
		}
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(tprimes.find(a[i]) != tprimes.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}