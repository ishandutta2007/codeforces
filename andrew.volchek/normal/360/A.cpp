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
#define ull long long
#define fst first
#define snd second
#define ld long double

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const ll inf = 1e9;
ll a[5005];
ll b[5005];

pair < pair < ll, ll > , pair < ll, ll > > q[5005];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> q[i].fst.fst >> q[i].snd.fst >> q[i].snd.snd >> q[i].fst.snd ;
	}
	
	for (int i = 1; i <= n; i++)
		a[i] = inf;
		
	for (int i = m-1; i >= 0; i--)
	{
		if (q[i].fst.fst == 1)
		{
			for (int j = q[i].snd.fst; j <= q[i].snd.snd; j++)
			{
				a[j] -= q[i].fst.snd;
			}
		}
		else
		{
			for (int j = q[i].snd.fst; j <= q[i].snd.snd; j++)
			{
				a[j] = min(a[j], q[i].fst.snd);
			}
		}
	}
	

	
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = min(inf, a[i]);
	
	for (int i = 0; i < m; i++)
	{
		if (q[i].fst.fst == 1)
		{
			for (int j = q[i].snd.fst; j <= q[i].snd.snd; j++)
			{
				a[j] += q[i].fst.snd;
				
			}
		}
		else
		{
			ll mm = -inf;
			
			for (int j = q[i].snd.fst; j <= q[i].snd.snd; j++)
			{
				mm = max(mm, a[j]);
			}
			
			//cerr << i << " " << mm << endl;
			
			if (mm != q[i].fst.snd)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > inf)
		{
			cout << "NO";
			return 0;
		}
	}
	
	
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
			cout << " ";
		cout << b[i];
	}
	
	return 0;
}