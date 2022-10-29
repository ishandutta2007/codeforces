#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

bool comp[1123456];
long long primes[1123456], nprimes;
long long a;
long long used[112];int sz = 0;
vector<pair<ll, ll> > num;
vector<long long> divisor;
int tab[11234][2123];
bool been[11234][2123];

long long foo(long long x)
{
	if(x < 2)
		return -1;
	
	for(int i = 0; primes[i] * primes[i] <= x && i < nprimes; i++)
		if(x % primes[i] == 0)
		{
			long long tmp = primes[i];
			while(tmp <= x)
			{
				if(tmp == x)
					return primes[i];
				tmp *= primes[i];
			}
			return -1;
		}
	return x;
}

int next[11234];
map<int,int> rdm;

int pd(long long x, int i)
{
	if(x == divisor.back())
		return 1;
	if(i >= num.size())
		return 0;
	if(divisor.back() % x != 0 || x > divisor.back())
		return 0;
	int tmp = rdm[x];
	if(been[tmp][i])
		return tab[tmp][i];
	been[tmp][i] = true;
	int retv = pd(x, i+1);
	retv += pd(x * num[i].second, next[i]);
	return tab[tmp][i] = retv;
}

int
main(void)
{
	for(long long i = 2; i <= 1000000; i++)
	{
		if(comp[i] == false)
			primes[nprimes++] = i;
		for(long long j = i*i; j <= 1000000; j += i)
			comp[j] = true;
	}
	cin >> a;
	for(long long i = 1; i * i <= a; i++)
	 	if(a % i == 0)
	 	{
	 		divisor.push_back(i);
		 	if(i*i != a)
		 		divisor.push_back(a/i);
	 	}
	sort(divisor.begin(), divisor.end());
	for(int i = 0; i < divisor.size(); i++)
	{
		rdm[divisor[i]] = i;
		long long tmp;
		if((tmp = foo(divisor[i] - 1)) > 0)
		{
			num.push_back(pair<ll,ll> (tmp, divisor[i]));
		}
	}
	sort(num.begin(), num.end());
	if(!num.empty())
		next[num.size() - 1] = num.size();
	for(int i = int(num.size()) - 1; i >= 0; i--)
		if(num[i].first == num[i+1].first)
			next[i] = next[i+1];
		else
			next[i] = i+1;
	printf("%d\n", pd(1, 0));
}