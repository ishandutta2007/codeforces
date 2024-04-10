#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;
char s[N];
int cnt[256];
vector<char> lst;
int n;

void reset()
{
	memset(cnt, 0, 1024);
	lst.clear();
}

int main()
{
	FAST;
	srand(time(NULL));
	int t;
	cin >> t;
	while (t--)
	{
		reset();
		cin >> s;
		n = strlen(s);
		Loop(i, 0, n)
		{
			if (!cnt[s[i]])
				lst.push_back(s[i]);
			cnt[s[i]]++;
		}
		sort(all(lst), [](char a, char b) {return (a & 1) < (b & 1); });
		n = lst.size();
		int p = -1;
		Loop(i, 0, n - 1)
		{
			if ((lst[i] ^ lst[i + 1]) & 1)
			{
				p = i;
				break;
			}
		}
		if (p != -1)
		{
			for (int i = 0; i < 60 && abs(lst[p] - lst[p + 1]) == 1; i++)
			{
				if (lst.size() <= 2)
					continue;
				int k = rand() & 1;
				if (p == 0)
					k = 0;
				if (n - p - 2 == 0)
					k = 1;
				if (k)
				{
					int x = rand() % p;
					swap(lst[p], lst[x]);
				}
				else
				{
					int x = rand() % (n - p - 2) + 2 + p;
					swap(lst[p + 1], lst[x]);
				}
			}
		}
		if (p != -1 && abs(lst[p] - lst[p + 1]) == 1)
			cout << "No answer\n";
		else
		{
			for (char c : lst)
				while (cnt[c]--)
					cout << c;
			cout << '\n';
		}
	}
}