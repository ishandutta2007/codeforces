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
using namespace std;

const int N = 110;
vector<int> in[N], out[N];
ll a[N];
int b[N];
int n;

int Do(int i)
{
	if (b[i] != -1)
		return b[i];
	int maax = 0;
	for (int u : out[i])
		maax = max(maax, Do(u));
	b[i] = maax + 1;
	return b[i];
}

void Print(int i)
{
	cout << a[i] << ' ';
	for(int u : out[i])
		if (b[u] == b[i] - 1)
		{
			Print(u);
			return;
		}
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, n)
	{
		Loop(j, 0, n)
		{
			if (2 * a[i] == a[j] || (a[i] % 3 == 0 && a[i] / 3 == a[j]))
			{
				out[i].push_back(j);
				in[j].push_back(i);
			}
		}
	}
	memset(b, -1, sizeof(b));
	Loop(i, 0, n)
	{
		if (in[i].size() == 0)
		{
			Do(i);
			Print(i);
		}
	}
}