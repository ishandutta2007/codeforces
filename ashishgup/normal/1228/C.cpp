#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD = 1e9 + 7;

int pow(int a, int b, int m)
{
	int ans=1;
	a %= m;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int x, n;
vector<int> v;

void work(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			v.push_back(i);
			while(x % i == 0)
				x /= i;
		}
	}
	if(x > 1)
		v.push_back(x);
}

int32_t main()
{
	IOS;
	cin >> x >> n;
	work(x);
	int value = 1;
	for(auto &it:v)
	{
		int p = it;
		int pw = 0, val = 1;
		while(val <= n)
		{
			if(val > n / p)
				break;
			val *= p;
			pw++;
		}
		int cnt = 0;
		while(val > 1)
		{
			int total = n / val;
			value *= pow(val, total - cnt, MOD);
			value %= MOD;
			cnt = total;
			val /= p;
		}
	}
	cout << value;
	return 0;
}