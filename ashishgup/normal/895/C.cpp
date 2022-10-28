#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int MOD=1e9+7;

int n;
long long freq[N];
int cache[71][1<<19];
vector<int> primes;

long long pow(long long a, long long b, long long m)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

bool isprime(int k)
{
	for(int i=2;i<k;i++)
	{
		if(k%i==0)
			return 0;
	}
	return 1;
}

void preprocess()
{
	for(int i=2;i<=70;i++)
	{
		if(isprime(i))
			primes.push_back(i);
	}
}

int newmask(int k, int bitmask)
{
	for(int i=0;i<primes.size();i++)
	{
		int ct=0;
		while(k%primes[i]==0)
		{
			k/=primes[i];
			ct++;
		}
		if(ct%2)
			bitmask ^= (1<<i);
	}
	return bitmask;
}

int dp(int i, int bitmask)
{
	if(i==71)
	{
		if(!bitmask)
			return 1;
		return 0;
	}
	if(cache[i][bitmask]!=-1)
		return cache[i][bitmask];
	int storemask=newmask(i, bitmask);
	long long ans1=0;
	if(freq[i]!=0)
		ans1=pow(2LL, freq[i]-1, MOD) * dp(i+1, storemask);
	ans1%=MOD;
	long long ans2=1;
	if(freq[i]!=0)
		ans2=(pow(2LL, freq[i]-1, MOD)) * dp(i+1, bitmask); 
	else
		ans2=dp(i+1, bitmask);
	ans2%=MOD;
	cache[i][bitmask]=(ans1+ans2)%MOD;
	return cache[i][bitmask];
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	preprocess();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		freq[k]++;
	}
	int ans=dp(1, 0);
	cout<<ans-1;
	return 0;
}