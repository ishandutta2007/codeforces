//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <deque>

#define X first
#define Y second

using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	int k, l;
	s = "a";
	cout << s << endl;
	cin >> k;
	if (k == 0)
	{
		return 0;
	}
	l = k + 1;
	s = "";
	if (l != 301)
	{
		for (int i = 0; i < l; i++)
		{
			s += 'a';
		}
		cout << s << endl;
		cin >> k;
		if (k == l)
		{
			l--;
			s = "";
			for (int i = 0; i < l; i++)
			{
				s += 'b';
			}
			cout << s << endl;
			return 0;
		}
		if (k == 0)
		{
			return 0;
		}
	}
	else
	{
		l--;
	}
	s = "";
	for (int i = 0; i < l; i++)
	{
		s += 'a';
	}
	int flag = 0;
	for (int i = 0; i < l; i++)
	{
		s[i] = 'b';
		cout << s << endl;
		int tmp;
		cin >> tmp;
		if (tmp > k)
		{
			s[i] = 'a';
		}
		else
		{
			k = tmp;
		}
		if (k == 0)
		{
			return 0;
		}
	}
	cin >> k;
	cout << k;
}