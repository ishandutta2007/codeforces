#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

pll get(ll a, ll b, ll c)
{
	if(b == 0) return make_pair(c,0);
	ll p = a % b, q = a / b;
	pll temp = get(b,p,c);
	ll X = temp.second, Y = temp.first - q * X;
	return make_pair(X,Y);
}

int main()
{
	int a,b,c,d;
	scanf("%d%d%d", &a, &b, &c);
	d = __gcd(a,b);
	if(c % d != 0)
	{
		printf("-1\n");
		return 0;
	}
	a /= d;
	b /= d;
	c /= d;
	pll res = get(a,b,-c);
	cout << res.first << " " << res.second << endl;
}