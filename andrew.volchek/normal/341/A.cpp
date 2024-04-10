#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double


int a[100005];
ll gcd(ll a, ll b)
{
	if (a) return gcd(b % a, a);
		else return b;
}

typedef vector<int> lnum;
const int base = 1000*1000*1000;

vector < int > mul(vector < int > &a, vector < int > &b)
{
	lnum c (a.size()+b.size());
for (size_t i=0; i<a.size(); ++i)
	for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
		long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
		c[i+j] = int (cur % base);
		carry = int (cur / base);
	}
while (c.size() > 1 && c.back() == 0)
	c.pop_back();
	return c;
}


int main(int argc, char **argv)
{
	ll nn = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		nn += (ll)a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n-1; i++)
	{
		nn += (a[i+1] - a[i]) * 2LL * (i + 1) * (n - i - 1);
	}
	
	ll c = gcd(nn, n);
	cout << nn / c << " " << n / c;
	
	
	
	return 0;
}