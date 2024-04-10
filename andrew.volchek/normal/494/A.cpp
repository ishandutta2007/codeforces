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

const int maxn = 100005;

char s[maxn];
int ans[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	gets(s);
	
	int n = strlen(s);
	
	int bal = 0;
	
	vector < int > sp;
	vector < int > st;
	
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			st.pb(i);
			bal++;
		}
		else if (s[i] == ')')
		{
			if (st.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			st.pop_back();
			bal--;
		}
		else
		{
			if (st.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			
			ans[sp.size()] = 1;
			sp.pb(i);
			
			st.pop_back();
			bal--;
		}
	}
	
	for (int x : st)
	{
		auto it = lower_bound(sp.begin(), sp.end(), x);
		if (it == sp.end())
		{
			cout << -1 << endl;
			return 0;
		}
		ans[it - sp.begin()]++;
	}
	
	for (int i = 0; i < sp.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}