#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[200010], y[200010];
int r, c, n;
int has0r, has0c;
int adjr[200010];
int adjc[200010];
struct UF
{
	int rep[400010], comps;
	void init(int r, int c)
	{
		comps = r+c;
		for (int i = 0; i < r+c; i++) rep[i] = i;
	}
	int findrep(int a)
	{
		if (rep[a] == a) return a;
		return rep[a] = findrep(rep[a]);
	}
	bool connected(int a, int b)
	{
		return findrep(a) == findrep(b);
	}
	void merge(int a, int b)
	{
		b += r;
		if (connected(a, b)) return;
	//	printf("%d %d - %d\n", a, b, comps);
		comps--;
		rep[findrep(a)] = findrep(b);
	}
};
UF uf;
int main()
{
	scanf("%d%d%d", &r, &c, &n);
	uf.init(r, c);
	has0r = r;
	has0c = c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
		if (!adjr[x[i]]) has0r--;
		if (!adjc[y[i]]) has0c--;
		adjr[x[i]]++;
		adjc[y[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		uf.merge(x[i], y[i]);
	}
	int ans = 0;//max(has0r, has0c);
	//printf("%d %d\n", ans, uf.comps);
	ans += uf.comps-1;
	printf("%d\n", ans);
}