#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const ll mod = 1000000007;
const int maxn = 100005;
ll fact[maxn], invFact[maxn];

ll powmod(ll x, ll n, ll m = mod)
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

ll C(ll n, ll k)
{
	ll res = (((fact[n] * invFact[k]) % mod) * invFact[n-k]) % mod;
	return res;
}

ll K(int len)
{
	if (len == 0)
		return 1;
	ll res = 0;
	for (int i = 0; i < len; i++)
	{
		res = (res + C(len-1, i)) % mod;
	}
	return res;
}

pair < int, int > a[maxn];
int b[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = (i * fact[i-1]) % mod;
		invFact[i] = powmod(fact[i], mod - 2);
	}
	
	int n;
	scanf("%d", &n);
	
	bool any = false;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].fst);
		b[i] = a[i].fst;
		any |= a[i].fst;
		a[i].snd = i;
		if (a[i].fst == 0)
			a[i].fst = 1e9;
	}
	
	if (!any)
	{
		cout << K(n);
		return 0;
	}
	
	sort(a, a + n);
	ll ans = 0;
	
	//cerr << a[0].fst << endl;
	
	for (int dir = 0; dir < 2; dir++)
	{
		int len = a[0].fst - 1;
		ll curr = 1;
		
		if (len == 0 && dir == 1)
			break;
		
		int left, right;
		
		if (dir == 0)
		{
			right = a[0].snd-1;
			left = right - len + 1;
		}
		else
		{
			left = a[0].snd + 1;
			right = left + len - 1;
		}
		
		if (left < 0 || right >= n)
			continue;
			
		bool good = true;
		
		for (int i = left; i <= right; i++)
		{
			if (b[i])
			{
				good = false;
			}
		}
		
		if (!good)
			continue;
		
		curr = (curr * K(len)) % mod;
		
		if (dir == 0)
			right++;
		else
			left--;
			
		int prv = a[0].fst;
			
		for (int i = 1; i < n; i++)
		{
			if (a[i].fst == 1e9)
				break;
			
			len = a[i].fst - prv - 1;
			
			int lcnt = 0;
			
			if (a[i].snd > right)
			{
				for (int j = right+1; j <= a[i].snd-1; j++)
				{
					if (len <= 0 || b[j])
					{
						good = false;
						break;
					}
					len--;
					right = j;
				}
				
				for (int j = 0; j < len; j++)
				{
					left--;
					if (left < 0 || b[left])
					{
						good = false;
						break;
					}
					lcnt++;
				}
				right++;
			}
			else
			{
				for (int j = left-1; j >= a[i].snd+1; j--)
				{
					if (len <= 0 || b[j])
					{
						good = false;
						break;
					}
					len--;
					left = j;
					lcnt++;
				}
				
				for (int j = 0; j < len; j++)
				{
					right++;
					if (right >= n || b[right])
					{
						good = false;
						break;
					}
				}
				left--;
			}
			
			if (!good)
				break;
				
			len = a[i].fst - prv - 1;
			curr = (curr * C(len, lcnt)) % mod;
			prv = a[i].fst;
		}
		
		if (!good)
			continue;
			
		int cnt = (n-1) - right + left;
		
		curr = (curr * C(cnt, left)) % mod;
		
		ans = (ans + curr) % mod;
	} 
	
	cout << ans << endl;

	return 0;
}