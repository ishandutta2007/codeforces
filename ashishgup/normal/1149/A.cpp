#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;

int n;
int a[N], sieve[N], f[5];
int pref[N];

void precompute()
{
	fill(sieve + 2, sieve + N, 1);
	for(int i = 2; i < N; i++)
	{
		if(sieve[i])
		{
			for(int j = 2; i * j < N; j++)
				sieve[i * j] = 0;
		}
	}
	for(int i = 2; i < N; i++)
		pref[i] = pref[i - 1] + sieve[i];
}
int32_t main()
{
	IOS;
	precompute();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	if(f[2] > 0)
	{
		cout << 2 << " ";
		f[2]--;
	}
	if(f[1] > 0)
	{
		cout << 1 << " ";
		f[1]--;
	}
	while(f[2] > 0)
	{
		cout << 2 << " ";
		f[2]--;
	}
	while(f[1] > 0)
	{
		cout << 1 << " ";
		f[1]--;
	}
	return 0;
}