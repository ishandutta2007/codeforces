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

const int N = 100000;
int l[N];
int n, m;
ll sum = 0;

void Solve()
{
	if (sum < n)
	{
		cout << "-1\n";
		return;
	}
	Loop(i, 0, m)
	{
		if(n - l[i] < i)
		{
			cout << "-1\n";
			return;
		}
	}
	int p = -1;
	Loop(i, 0, m)
	{
		if (p == -1)
		{
			if (sum - l[i] < n - i - 1)
			{
				sum -= l[i];
				// n - p = sum
				p = n - sum;
				cout << i + 1 << ' ';
			}
			else
			{
				cout << i + 1 << ' ';
				sum -= l[i];
			}
		}
		else
		{
			cout << p + 1 << ' ';
			p = p + l[i];
		}
	}
}

int main()
{
	cin >> n >> m;
	Loop(i, 0, m)
	{
		cin >> l[i];
		sum += l[i];
	}
	Solve();
}