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

const int maxn = 200005;



char str[maxn];
int cnt[maxn];
pair < int, int > b[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	gets(str + 1);
	int n = strlen(str + 1);
	
	for (int i = 1; i <= n; i++)
		cnt[i] = cnt[i - 1] + (str[i] == '[');
		
	pair < int, int > bal = mp(0, 0);
	int ansCost = 0, ansL = 0, ansR = 0;
	
	vector < int > st;
	
	set < pair < int, int > > s[2];
	map < pair < int, int >, int > m;
	s[0].insert(mp(0, 0));
	s[1].insert(mp(0, 0));
	m[bal] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		bool bad = false;
		
		if (str[i] == ')')
		{
			if (st.empty() || st.back() != '(')
				bad = true;
			else
			{
				st.pop_back();
				bal.fst--;
			}
		}
		else if (str[i] == ']')
		{
			if (st.empty() || st.back() != '[')
				bad = true;
			else
			{
				st.pop_back();
				bal.snd--;
			}
		}
		else if (str[i] == '(')
		{
			st.push_back(str[i]);
			bal.fst++;
		}
		else
		{
			st.push_back(str[i]);
			bal.snd++;
		}
		
		
		if (bad)
		{
			st.clear();
			bal = mp(0, 0);
			b[i] = bal;
			s[0].clear();
			s[1].clear();
			m.clear();
			m[bal] = i;
			s[0].insert(mp(0, i));
			s[1].insert(mp(0, i));
			continue;
		}
		
		while (true)
		{
			auto it = s[0].upper_bound(mp(bal.fst, 1e9));
			if (it == s[0].end())
				break;
			m.erase(b[it->snd]);
			s[1].erase(mp(b[it->snd].snd, it->snd));
			s[0].erase(it);
		}
		
		while (true)
		{
			auto it = s[1].upper_bound(mp(bal.snd, 1e9));
			if (it == s[1].end())
				break;
			m.erase(b[it->snd]);
			s[0].erase(mp(b[it->snd].fst, it->snd));
			s[1].erase(it);
		}
		
		if (m.find(bal) != m.end())
		{
			int curr = cnt[i] - cnt[m[bal]];
			if (curr > ansCost)
			{
				ansCost = curr;
				ansL = m[bal] + 1;
				ansR = i + 1;
			}
		}
		else
		{
			m[bal] = i;
		}
		
		b[i] = bal;
		
		s[0].insert(mp(bal.fst, i));
		s[1].insert(mp(bal.snd, i));
	}
	
	cout << ansCost << endl;
	for (int i = ansL; i < ansR; i++)
		printf("%c", str[i]);
	
	return 0;
}