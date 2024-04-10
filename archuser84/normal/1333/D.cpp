#define _CRT_SECURE_NO_WARNINGS
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

const int N = 3010;
int n, k, kh;
char s[N];

vector<vector<int>> ans(1);

int main()
{
	FAST;
	cin >> n >> k >> s; kh = k;
	int cntR = 0;
	int maax = 0;
	int m = 0;
	Loop(i, 0, n)
	{
		if (s[i] == 'R')
			cntR++;
		else
		{
			maax += cntR;
			m = i + 1;
		}
	}
	int miin = 0; bool flag = 0;
	Loop(i, 0, m - 1)
	{
		if (s[i] == 'R')
			flag = 1;
		if (flag)
		{
			if (s[i] == 'R')
				miin = max(0, miin - 1);
			else
				miin++;
		}
	}
	miin += cntR - (n - m);
	n = m;
	if (k<miin || k>maax)
	{
		cout << "-1\n";
		return 0;
	}
	int cnt = 0;
	while (true)
	{
		k--;
		Loop(i, 0, n - 1)
		{
			if (s[i] == 'R' && s[i + 1] == 'L')
			{
				ans[ans.size() - 1].push_back(i + 1);
				swap(s[i], s[i + 1]);
				cnt++;
				i++;
				if (k == maax - cnt)
				{
					vector<int> h(0);
					ans.push_back(h);
					goto last;
				}
			}
		}
		if (!flag)
		{
			k++;
			break;
		}
		vector<int> h(0);
		ans.push_back(h);
	}
last:
	while (k)
	{
		Loop(i, 0, n - 1)
		{
			if (s[i] == 'R' && s[i + 1] == 'L')
			{
				ans[ans.size() - 1].push_back(i + 1);
				vector<int> h(0);
				ans.push_back(h);
				swap(s[i], s[i + 1]);
				i++; k--;
			}
		}
	}
	Loop(i, 0, kh)
	{
		int size = ans[i].size();
		cout << size << ' ';
		Loop(j, 0, size)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}