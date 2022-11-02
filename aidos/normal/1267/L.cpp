//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = 1005;

using namespace std;

int n, l, k;
char ans[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	cin >> n >> l >> k;
	string s;
	cin >> s;
	sort(all(s));
	int tl = 1, tr = k;
	int ptr = 0;
	string t;
	forn(i, (n - k) * l)
	{
		t += s[(int)s.size() - 1];
		s.pop_back();
	}
	for (int i = k + 1; i <= n; i++)
	{
		forn(j, l)
		{
			ans[i][j] = t[(int)t.size() - 1];
			t.pop_back();
		}
	} 
	for (int i = 1; i <= l; i++)
	{
		for (int j = tl; j <= tr; j++)
		{
			ans[j][i] = s[ptr++];
		}
		while(ans[tl][i] < ans[tr][i])
		{
			for (int j = i + 1; j <= l; j++)
			{
				ans[tl][j] = s[(int)s.size() - 1];
				s.pop_back();
			}
			tl++;
		}
	}
	vector < string > res;
	forn(i, n)
	{
		string cur;
		forn(j, l)
			cur += ans[i][j];
		res.pb(cur);
	}
	sort(all(res));
	for (auto it : res)
		cout << it << endl;


	return 0;
}