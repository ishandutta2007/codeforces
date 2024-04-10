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

const int maxn = 1000005;
const ll mod = 1000000007;

struct state
{
	int nxt[30];
	int lnk;
	int len;
	ll cnt[3]; 
	
	state()
	{
		for (int i = 0; i < 30; i++)
			nxt[i] = -1;
		for (int i = 0; i < 3; i++)
			cnt[i] = 0;
	}
};

state s[maxn];
int sz = 0;
int last = 0;

string str;

vector < int > sl[maxn];

void buildSA()
{
	s[0].len = 0;
	s[0].lnk = -1;
	sl[0].pb(0);
	
	
	for (char ch : str)
	{
		int cur = ++sz;
		s[cur].len = s[last].len + 1;
		sl[s[cur].len].pb(cur);
		int p = last;
		
		while (p != -1)
		{
			if (s[p].nxt[ch] == -1)
			{
				s[p].nxt[ch] = cur;
				p = s[p].lnk;
			}
			else
				break;
		}
		
		if (p != -1)
		{
			int q = s[p].nxt[ch];
			
			if (s[p].len + 1 == s[q].len)
			{
				s[cur].lnk = q;
			}
			else
			{
				int clone = ++sz;
				s[clone].len = s[p].len + 1;
				sl[s[clone].len].pb(clone);
				for (int j = 0; j < 26; j++)
					s[clone].nxt[j] = s[q].nxt[j];
				s[clone].lnk = s[q].lnk;
				s[q].lnk = clone;
				s[cur].lnk = clone;
				
				while (p != -1)
				{
					if (s[p].nxt[ch] == q)
					{
						s[p].nxt[ch] = clone;
						p = s[p].lnk;
					}
					else
						break;
				}
			}
		}
		else
		{
			s[cur].lnk = 0;
		}
		
		last = cur;
	}
}

ll ans[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	string a[3];
	
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
		for (char &ch : a[i])
			ch -= 'a';
		str += a[i] + char(27 + i);
	}
	
	buildSA();
		
	
	for (int i = 0; i < 3; i++)
	{
		int p = 0;
		for (char ch : a[i])
		{
			while (p != -1)
			{
				if (s[p].nxt[ch] == -1)
				{
					p = s[p].lnk;
				}
				else
					break;
			}			
			
			if (p == -1)
				p = 0;
			else
				p = s[p].nxt[ch];
				
			s[p].cnt[i]++;
		}
	}
	
	for (int i = maxn - 1; i > 0; i--)
	{
		for (int j : sl[i])
		{
			int lnk = s[j].lnk;
			ll curr = 1;
			
			for (int k = 0; k < 3; k++)
			{
				s[lnk].cnt[k] = (s[lnk].cnt[k] + s[j].cnt[k]) % mod;
				curr = (curr * s[j].cnt[k]) % mod;
			}
				
			ans[s[j].len + 1] = (ans[s[j].len + 1] + mod - curr) % mod;
			ans[s[lnk].len + 1] = (ans[s[lnk].len + 1] + curr) % mod;
		}
	}
	
	int len = 1e9;
	for (int i = 0; i < 3; i++)
		len = min(len, (int)a[i].size());
		
	ll curr = 0;
	for (int i = 1; i <= len; i++)
	{
		if (i > 1)
			cout << " ";
		curr = (curr + ans[i]) % mod;
		cout << curr;
	}
	
	return 0;
}