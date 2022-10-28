#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

const int N = 5e5 + 5;
const int M = 1e7 + 5;

int n;
int a[N], b[N], c[N];
int prime[M];

void precompute()
{
	for(int i = 2; i < M; i++)
	{
		if(!prime[i])
		{
			for(int j = 1; i * j < M; j++)
				prime[i * j] = i;
		}
	}
}

int32_t main()
{
	IOS;
	precompute();
	memset(b, -1, sizeof(b));
	memset(c, -1, sizeof(c));
	cin >> n;
	for(int idx = 1; idx <= n; idx++)
	{
		cin >> a[idx];
		int x = a[idx];
		vector<int> v;
		while(x > 1)
		{
			v.push_back(prime[x]);
			x /= prime[x];
		}
		int sz = v.size();
		for(int i = 0; i < sz; i++)
		{
			for(int j = i; j < sz; j++)
			{
				if(__gcd(v[i] + v[j], a[idx]) == 1)
				{
					b[idx] = v[i];
					c[idx] = v[j];
					break;
				}
			}
		}
		for(int i = 0; i < sz; i++)
		{
			int j = i;
			int val = v[i];
			while(j + 1 < sz && v[i] == v[j + 1])
			{
				val *= v[i];
				j++;
			}
			i = j;
			if(a[idx] / val == 1)
				continue;
			if(__gcd(val + a[idx] / val, a[idx]) == 1)
			{
				b[idx] = val;
				c[idx] = a[idx] / val;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << c[i] << " ";
	cout << endl;
	return 0;
}