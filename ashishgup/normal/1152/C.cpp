#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
	
int a, b;
int least = 1e18, bestk;

void brute()
{
	for(int k = 0; k <= 1e6; k++)
	{
		int cur = (a + k) * (b + k) / __gcd(a + k, b + k);
		if(cur < least)
		{
			least = cur;
			bestk = k;
		}
	}
}

void work(int x)
{
	for(int diff = 1; diff * diff <= x; diff++)
	{
		if(x % diff == 0)
		{
			int k = (diff - (b % diff)) % diff;
			int nlcm = (a + k) * (b + k) / __gcd(a + k, b + k);
			if(nlcm < least)
			{
				least = nlcm;
				bestk = k;
			}
			int other = diff;
			diff = x / diff;
			k = (diff - (b % diff)) % diff;
			nlcm = (a + k) * (b + k) / __gcd(a + k, b + k);
			if(nlcm < least)
			{
				least = nlcm;
				bestk = k;
			}
			diff = other;
		}
	}
}

int32_t main()
{
	IOS;
	cin >> a >> b;
	if(a > b)
		swap(a, b);
	brute();
	int diff = b - a;
	if(diff > 0)
		work(diff);
	cout << bestk;
	return 0;
}