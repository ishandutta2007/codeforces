#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 2000;

int main()
{
	FAST;
	char s[N];
	cin >> s;
	int n = strlen(s);
	int p1 = -1;
	int p2 = n;
	vector<int> a;
	vector<int> b;
	while (true)
	{
		p1++;
		if (s[p1] == ')')
			continue;
		bool flag = false;
		LoopR(i, p1 + 1, p2)
		{
			if (s[i] == ')')
			{
				p2 = i;
				flag = true;
				break;
			}
		}
		if (flag)
		{
			a.push_back(p1);
			b.push_back(p2);
		}
		else
			break;
	}
	if (a.size() == 0)
	{
		cout << 0;
		return 0;
	}
	cout << 1 << '\n' << 2 * a.size() << '\n';
	for (auto i : a)
		cout << i + 1 << ' ';
	LoopR(i, 0, b.size())
		cout << b[i] + 1 << ' ';
}