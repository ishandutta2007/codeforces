#include <stdio.h>
#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll count(ll x)
{
	for(int i = 63; i >= 0; i--)
		if(x & (1LL<<i))
			return i;
	return 0;
}

//(n,k) = (n!)/((k!)*(n-k)!)

ll choose(ll n, ll k)
{
	if(n < k)
		return 0;
	if(n == 0 && k == 0)
		return 1;
	if(k == 1)
		return n;
	if(k == 0)
		return 0;
	return ((n-k+1)*choose(n, k-1))/k;
}

ll c_bits(ll x)
{
	ll retv = 0;
	while(x)
	{
		if(x&1LL)
			retv++;
		x >>= 1LL;
	}
	return retv;
}

ll foo(ll x, ll k)
{
//	cout << x << '\n';
	if(x == 0)
		return 0;
	if(k == 0)
		return 0;
	if(x + 1 < (1LL<<k))
		return 0ll;
	ll y = count(x);
	return choose(y, k) + foo(x-(1LL<<y), k-1) ;
}

int
main(void)
{
	unsigned long long m, k;
	cin >> m >> k;
	unsigned long long bot = 1, top = 1e18, mid, tmp;
	while(bot < top)
	{
		mid = (bot+top)/2;
		if((tmp = (foo(2*mid, k) - foo(mid,k))) < m)
			bot = mid + 1;
		else
			top = mid;
//		cout << tmp << '\n'; 
	}
//	cout << tmp << '\n'; 
	cout << bot << '\n'; 
}