#include <map>
#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 363304 + 5
#define Mod 1000000007

int n, ans = 1;
set <int> S;
set <int> :: iterator it, _it, __it;
map <int, int> Map;

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		string instr;
		cin >> instr >> x;
		if (instr == "ADD")
		{
			S.insert(x);
			_it = it = S.find(x);
			int t = 0;
			if (_it == S.begin() || (Map[*(-- _it)] & 1)) t |= 1;
			_it = it; ++ _it;
			if (_it == S.end() || (Map[*_it] & 2)) t |= 2;
			Map[x] = t;
		}
		else
		{
			_it = it = S.find(x);
			if (_it != S.begin())
			{
				_it --;
				if ((Map[*_it] & 1) == 0)
				{
					puts("0");
					return 0;
				}
				for (__it = it; __it != S.begin() && (Map[*_it] & 2); __it --, _it --)
					Map[*_it] &= 1;
			}
			_it = it; ++ _it;
			if (_it != S.end())
			{
				if ((Map[*_it] & 2) == 0)
				{
					puts("0");
					return 0;
				}
				for (; _it != S.end() && (Map[*_it] & 1); _it ++)
					Map[*_it] &= 2;
			}
			S.erase(x);
			ans = ans * (1 + (Map[x] == 3)) % Mod;
			Map[x] = 0;
		}
	}
	int cnt = 0;
	for (const pair <int, int>& p : Map)
		if (p.second == 3) cnt ++;
	ans = 1LL * ans * (cnt + 1) % Mod;
	printf("%d\n", ans);
	return 0;
}