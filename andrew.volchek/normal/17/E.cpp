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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 2000005;

vector < pair < char, int > > to[maxn];
int lnk[maxn], len[maxn], cnt[maxn];
int strict[maxn];
char s[maxn];
int last = 1, sn = 1, sz = 2;

void init()
{
	for (int i = 0; i < maxn; i++)
		to[i].clear();
	last = 1, sn = 1, sz = 2;
	s[0] = -1;
	lnk[1] = 0;
	strict[1] = 0;
	len[0] = -1;
}

int go(int v, char c)
{
	for (auto x : to[v])
		if (x.fst == c)
			return x.snd;
	return -1;
}

int getLinkNaive(int v, char c)
{
	while (c != s[sn - 1 - len[v] - 1]) v = lnk[v];
	return v;
}

int getLink(int v, char c)
{
	while (true)
	{
		if (s[sn - 1] == s[sn - 1 - len[v] - 1])
			return v;
		if (s[sn - 1] == s[sn - 1 - len[lnk[v]] - 1])
			return lnk[v];
		v = strict[v];
	}
}



int add(char c)
{
	s[sn++] = c;
	//cerr << last << " " << strict[last] << " " << lnk[lnk[lnk[last]]] << " " << getLink(last, c) << " " << getLinkNaive(last, c)  << endl;
	//assert(getLink(last, c) == getLinkNaive(last, c));
	int p = getLink(last, c);
	if (go(p, c) == -1)
	{
		len[sz] = len[p] + 2;
		to[p].pb(mp(c, sz));
		int q;
		if (len[sz] == 1)
			q = 1;
		else
		{
			q = getLink(lnk[p], c);
			q = go(q, c);
		}
		lnk[sz] = q;
		if (s[sn - len[lnk[sz]] - 1] == s[sn - len[lnk[lnk[sz]]] - 1])
			strict[sz] = strict[lnk[sz]];
		else
			strict[sz] = lnk[lnk[sz]];
		sz++;
	}
	last = go(p, c);
	return cnt[last] = cnt[lnk[last]] + 1;
}


ll start[maxn], finish[maxn];
char t[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	gets(t);
	gets(t);
	int n = strlen(t);
	init();
	for (int i = 0; i < n; i++)
		finish[i] = add(t[i]);
	
	init();
	for (int i = n - 1; i >= 0; i--)
		start[i] = add(t[i]);
	const ll mod = 51123987;
	for (int i = n - 2; i >= 0; i--)
	{
		start[i] += start[i + 1];
		if (start[i] >= mod)
			start[i] -= mod;
	}
	ll ans = ((ll)start[0] * (start[0] - 1) / 2) % mod;
	for (int i = 1; i < n; i++)
	{
		ans -= (finish[i - 1] * start[i]) % mod;
		if (ans < 0)
			ans += mod;
	}
	cout << ans << endl;
	
	
	return 0;
}