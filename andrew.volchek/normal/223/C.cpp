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

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 2005;
const ll mod = 1000000007;

ll a[maxn];
ll inv[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	inv[1] = 1;
	for (int i = 2; i < maxn; i++)
		inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
		
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		ll sum = 0;
		ll curr = 1;
		
		for (int j = i; j >= 0; j--)
		{
			sum = (sum + a[j] * curr) % mod;
			curr = (((curr * (k + (i - j))) % mod) * inv[i - j + 1]) % mod;
		}
		
		cout << sum;
	}
	
	
	return 0;
}