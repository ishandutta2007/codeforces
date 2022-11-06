#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
 
const int maxn = 70;
const int maxk = 15;
const int mod = 1e9 + 7;

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void solve()
{
	ll m;
	scanf("%I64d", &m);

	ll x = m / 2 + 1;

	ll a = (x + (x % 2? 1 : 2));
	ll b = m / 4 + 1;

	if(a % 2 == 0)
		a /= 2;
	else
		b /= 2;

	printf("%I64d\n", (a % mod) * (b % mod) % mod);  
}

int main()
{
	int q;
	cin >> q;

	while(q--)
		solve();
}