#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 60;
char s[N];
int b[N];
char ans[N];
int n, m;
set<char, greater<char>> S;
int cnt[26];

int count()
{
	int ans = 0;
	Loop(i, 0, m)
		if (b[i] == 0)
			ans++;
	return ans;
}
void find(char c)
{
	vector<int> v;
	Loop(i, 0, m)
	{
		if (b[i] == 0)
		{
			ans[i] = c;
			v.push_back(i);
			b[i] = -1;
		}
	}
	Loop(i, 0, m)
		for (int x : v)
			b[i] -= abs(i - x);
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		cin >> s >> m;
		n = strlen(s);
		S.clear();
		Loop(i, 0, n)
		{
			S.insert(s[i]);
			cnt[s[i] - 'a']++;
		}
		Loop(i, 0, m)
			cin >> b[i];
		for (char c : S)
		{
			if (count() > cnt[c - 'a'])
				continue;
			find(c);
		}
		ans[m] = '\0';
		printf("%s\n", ans);
	}
}