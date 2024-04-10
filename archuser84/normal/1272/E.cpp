#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int n;
int a[200000];
vector<int> in[200000];
int ans[200000];

int queue[200000];
void bfs(int s)
{
	queue[0] = s;
	int qs = 0, qe = 1;
	int parity = a[s] % 2;
	int d = 1;
	while (qe - qs > 0)
	{
		int u = queue[qs++];
		Loop(i, 0, in[u].size())
		{
			int v = in[u][i];
			if (a[v] % 2 != parity)
			{
				if (ans[v] == -1 || ans[v] > d)
				{
					ans[v] = d;
					queue[qe++] = v;
				}
			}
		}
		d = ans[queue[qs]] + 1;
	}
}

int main()
{
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> a[i];
		int left = i - a[i];
		int right = i + a[i];
		if (left >= 0)
			in[left].push_back(i);
		if (right < n)
			in[right].push_back(i);
	}
	memset(ans, -1, n * sizeof(ans[0]));
	Loop(i, 0, n)
		bfs(i);
	Loop(i, 0, n)
		cout << ans[i] << ' ';
}