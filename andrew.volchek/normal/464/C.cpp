#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <ctime>
#include <unordered_map>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100105;
const ll mod = 1000000007;

char str[maxn];
vector < pair < int, string > > a;
char tmp[maxn];

ll bpow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	gets(str);
	int n;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		char c;
		gets(tmp);
		a.pb(mp(tmp[0] - '0', string(tmp + 3)));
	}
	
	pair < ll, ll > b[10];
	for (int i = 0; i < 10; i++)
		b[i] = mp(i, 1);
		
	for (int i = n - 1; i >= 0; i--)
	{
		ll val = 0, len = 0;
		for (int j = 0; j < a[i].snd.size(); j++)
		{
			int curr = a[i].snd[j] - '0';
			val = (val * bpow(10, b[curr].snd)) % mod;
			val = (val + b[curr].fst) % mod;
			len += b[curr].snd;
			len %= mod - 1;
		}
		//cerr << len << endl;
		b[a[i].fst] = mp(val, len);
	}
	
	//cout << b[2].fst << " " << b[2].snd << endl;
	
	ll ans = 0;
	
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int curr = str[i] - '0';
		ans = (ans * bpow(10, b[curr].snd)) % mod;
		ans = (ans + b[curr].fst) % mod;
	}
	
	cout << ans;
	
	return 0;
}