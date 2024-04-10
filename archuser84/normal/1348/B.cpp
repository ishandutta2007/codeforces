#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

struct link
{
	int a;
	link* nex;
	link(int x)
	{
		a = x;
	}
};

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		int l = 0;
		cin >> n >> k;
		int m = n;
		int a[100];
		int nexn;
		map<int, bool> ex;
		link lis(-1);
		link* p = &lis;
		Loop(i, 0, n)
		{
			int x;
			cin >> x;
			if (!ex[x])
			{
				if (l == k)
				{
					Loop(j, i + 1, n)
					{
						int y; cin >> y;
					}
					goto ter;
				}
				a[l] = x;
				l++;
				ex[x] = true;
			}
			(*p).a = x;
			(*p).nex = new link(-1);
			p = (*p).nex;
		}
		p = &lis;
		nexn = 1 % k;
		Loop(i, l, k)
			a[i] = a[l - 1];
		while ((*((*p).nex)).a != -1)
		{
			if ((*((*p).nex)).a != a[nexn])
			{
				link* t = (*p).nex;
				(*p).nex = new link(a[nexn]);
				p = (*p).nex;
				(*p).nex = t;
				m++;
			}
			else
				p = (*p).nex;
			nexn = (nexn + 1) % k;
		}
		p = &lis;
		cout << m << '\n';
		while ((*p).a != -1)
		{
			cout << (*p).a << ' ';
			p = (*p).nex;
		}
		cout << '\n';
		delete[](lis.nex);
		continue;
	ter:
		cout << "-1\n";
	}
}