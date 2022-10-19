#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 300005;
int n, m, k;
int par[N];
int erk[N];
int ans[N];
bool c[N];
vector<int> b[N];
void erkdfs(int x)
{
	int i, h, r, p, maxu=0,maxi;
	p = par[x];
	ans[x] = x;
	erk[x] = 1;
	for (i = 0; i<b[x].size(); i++)
	{
		h = b[x][i];
		erkdfs(h);
		erk[x] += erk[h];
		if (erk[h]>maxu)
		{
			maxu = erk[h];
			maxi = h;
		}
	}
	if (maxu * 2 > erk[x])
	{
		int aans = ans[maxi];
		while ((erk[x] - erk[aans]) * 2 > erk[x])
		{
			aans = par[aans];
		}
		ans[x] = aans;
	}
}
int main()
{
	int i, j, x;
	cin >> n >> m;
	k = n / 2;
	par[1] = 1;
	for (i = 2; i <= n; i++)
	{
		cin >> par[i];
		b[par[i]].push_back(i);
	}
	erkdfs(1);
	for (i = 0; i<m; i++)
	{
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}