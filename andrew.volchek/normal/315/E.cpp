#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long

const int mod = 1000000007;
const int maxn = 100005;
const int maxt = 1000005;

int tree[4*maxt];

void modify(int v, int l, int r, int p, int val)
{
	if (l == r)
	{
		tree[v] = val;
		return;
	}
	
	int c = (l + r) / 2;
	
	if (p <= c)
		modify(2*v, l, c, p, val);
	else
		modify(2*v+1, c+1, r, p, val);
		
	tree[v] = (tree[2*v] + tree[2*v + 1]) % mod;
	//if (tree[v] >= mod)
	//	tree[v] -= mod;
}

ll res = 0; 

void sum(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
	{
		res += tree[v];
		//if (res >= mod)
		//	res -= mod;
		res %= mod;
		return;
	}
	
	int c = (l + r) / 2;
	
	if (i <= c)
		sum(2*v, l, c, i, j);
	if (c < j)
		sum(2*v+1, c+1, r, i, j);
		
}

int a[maxn];
bool f[maxt];

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a+i);
	}
	
	for (int i = 0; i < n; i++)
	{
		res = 0;
		sum(1, 1, maxt-1, 1, a[i]);
		/*if (f[a[i]])
		{
			ll res2 = res;
			res = 0;
			sum(1, 1, maxt-1, a[i], a[i]);
			res = (res2 + mod * 2 - res) % mod;
		}*/
		int nn = (res * a[i] + a[i]) % (ll)mod;
		//cout << nn << endl;
		modify(1, 1, maxt-1, a[i], nn);
	}
	
	res = 0;
	sum(1, 1, maxt-1, 1, maxt-2);
	
	printf("%d", (int)res);
	
	
	return 0;
}