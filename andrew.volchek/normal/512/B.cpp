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
//#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 305;

ll a[maxn], b[maxn];

ll gcd(ll a, ll b)
{
	return a ? gcd(b % a, a) : b;
}


int main()
{
	srand(time(NULL));
	//freopen("a.in", "r", stdin);
	
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < n; j++)
		cin >> b[j];
	
	vector < pair < ll, ll > > v;
	v.pb(mp(a[0], b[0]));
	
	for (int i = 1; i < n; i++)
	{
		vector < pair < ll, ll > > nv;
		
		for (auto x : v)
			nv.pb(mp(gcd(x.fst, a[i]), x.snd + b[i]));
	
		nv.pb(mp(a[i], b[i]));
		
		for (auto x : v)
			nv.pb(x);
			
		sort(nv.begin(), nv.end());
		
		v.clear();
		
		for (int j = 0; j < nv.size(); j++)
		{
			int h = j;
			while (h < nv.size() && nv[h].fst == nv[j].fst) h++;
			
			v.pb(nv[j]);
			j = h - 1;
		}
	}
	
	if (v.empty() || v[0].fst != 1)
		cout << -1 << endl;
	else
		cout << v[0].snd << endl;
	
	
	return 0;
}