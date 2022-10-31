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

struct node
{
	int nxt[26];
	int lnk;
	int len;
	int cnt;
	int deg;
	
	node()
	{
		for (int i = 0; i < 26; i++)
			nxt[i] = -1;
		lnk = len = -1;
		deg = 0;
		cnt = 0;
	}
};

const int maxn = 2005000;

node s[maxn];
int ncnt = 1;
int last = 0;

void extend(int ch)
{
	int curr = ncnt++;
	s[curr].len = s[last].len + 1;
	s[last].nxt[ch] = curr;
	s[curr].lnk = 0;
	s[curr].cnt = 1;
	
	int v = s[last].lnk;
	
	while (v != -1)
	{
		if (s[v].nxt[ch] == -1)
		{
			s[v].nxt[ch] = curr;
			v = s[v].lnk;
		}
		else
		{
			if (s[s[v].nxt[ch]].len == s[v].len + 1)
			{
				s[curr].lnk = s[v].nxt[ch];
				break;
			}
			else
			{
				int p = v, q = s[v].nxt[ch];
				
				int clone = ncnt++;
				
				for (int i = 0; i < 26; i++)
					s[clone].nxt[i] = s[q].nxt[i];
				s[clone].lnk = s[q].lnk;
				s[clone].len = s[p].len + 1;
				s[q].lnk = clone;
				s[curr].lnk = clone;
				
				for (int j = p; j != -1 && s[j].nxt[ch] == q; j = s[j].lnk)
				{
					s[j].nxt[ch] = clone;
				}
			}
		}
	}
	
	last = curr;
}


char str[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	s[0].len = 0;
	
	gets(str);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++)
		extend(str[i] - 'a');
		
	
	for (int i = 0; i < ncnt; i++)
	{
		if (s[i].lnk != -1)
			s[s[i].lnk].deg++;
	}
	
	queue < int > q;
	for (int i = 0; i < ncnt; i++)
	{
		if (s[i].deg == 0)
			q.push(i);
	}
	
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		if (s[v].lnk != -1)
		{
			s[s[v].lnk].cnt += s[v].cnt;
			s[s[v].lnk].deg--;
			if (s[s[v].lnk].deg == 0)
				q.push(s[v].lnk);
		}
	}

	
	int m;
	scanf("%d\n", &m);
	
	for (int i = 0; i < m; i++)
	{
		gets(str);
		int len = strlen(str);
		for (int j = len; j < len + len; j++)
			str[j] = str[j - len];
		
		set < int > was;
		
		int curr = 0;
		int v = 0;
		
		for (int j = 0; j < len + len; j++)
		{
			str[j] -= 'a';
			if (s[v].nxt[str[j]] != -1)
			{
				curr++;
				v = s[v].nxt[str[j]];
			}
			else
			{
				while (s[v].lnk != -1 && s[v].nxt[str[j]] == -1)
				{
					curr -= s[v].len - s[s[v].lnk].len;
					v = s[v].lnk;
				}
				
				curr = s[v].len;
				
				if (s[v].nxt[str[j]] != -1)
				{
					v = s[v].nxt[str[j]];
					curr++;
				}
			}
			
			while (s[v].lnk != -1 && curr <= s[s[v].lnk].len)
					v = s[v].lnk;
			
			
			if (curr == len)
			{
				was.insert(v);
				curr--;
			}
			
			while (s[v].lnk != -1 && curr <= s[s[v].lnk].len)
					v = s[v].lnk;
		}
		
		int ans = 0;
		
		for (int x : was)
		{
			ans += s[x].cnt;
		}
			
		printf("%d\n", ans);
	}
	
	
	return 0;
}