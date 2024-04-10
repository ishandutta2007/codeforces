#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

int n, k;
int a[N];

int pow(int a, int b, int m)
{
	int ans=1;
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
	return pow(k, MOD - 2, MOD);
}

int work(vector<int> &v)
{
	int check = 0;
	for(auto &it:v)
		check |= (it != -1);
	if(!check)
		return (k * pow(k-1, (int)v.size() - 1, MOD))%MOD;
	int ans = 1;
	while(v.size() && v.back() == -1)
	{
		ans *= (k - 1);
		ans %= MOD;
		v.pop_back();
	}
	reverse(v.begin(), v.end());
	while(v.size() && v.back() == -1)
	{
		ans *= (k - 1);
		ans %= MOD;
		v.pop_back();
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i] != -1 && i - 1>=0 && v[i]==v[i-1])
			return 0;
		if(v[i] == -1)
		{
			int j = i;
			while(j + 1 < v.size() && v[j + 1] == -1)
				j++;
			int x = v[i - 1];
			int y = v[j + 1];
			int middle = j - i + 1;
			int range = k;
			middle++;
			int val = pow(range - 1, middle, MOD);
			if(middle%2)
				val = (-val + MOD)%MOD;
			int num;
			if(middle%2)
				num = (1 - val + MOD)%MOD;
			else
				num = (val - 1 + MOD)%MOD;
			num *= modinv(range);
			num %= MOD;
			if(x == y)
			{
				if(middle%2)
					num = (num - 1 + MOD)%MOD;
				else 
					num = (num + 1)%MOD;
			}
			ans *= num;
			ans %= MOD;
			i = j;
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<int> v;
	for(int i=1;i<=n;i+=2)
		v.push_back(a[i]);
	int ans = work(v);
	v.clear();
	for(int i=2;i<=n;i+=2)
		v.push_back(a[i]);
	ans *= work(v);
	ans %= MOD;
	cout<<ans;
	return 0;
}