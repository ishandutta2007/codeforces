#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
map<int, vector<int>*> adj;
set<int> seen;
int compsz[100010][2], upto;
int p[100010];
void dfs(int a, int c)
{
	if (seen.find(a) != seen.end()) return;
	seen.insert(a);
	compsz[c][0]++;
	vector<int>* v = adj[a];
	for (int b : (*v))
	{
		compsz[c][1]++;
		dfs(b, c);
	}
}
#undef int
int main()
{
	#define int long long
	vector<int> points;
	int n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%lld%lld", &x, &y);
		x += 1000000001;
		y -= 1000000001;
		if (adj.find(x) == adj.end()) adj[x] = new vector<int>();
		if (adj.find(y) == adj.end()) adj[y] = new vector<int>();
		adj[x]->push_back(y);
		adj[y]->push_back(x);
		points.push_back(x);
	}
	p[0] = 1;
	for (int i = 1; i < 100010; i++) p[i] = (p[i-1]*2)%mod;
	int ans = 1;
	for (int a : points)
	{
		if (seen.find(a) == seen.end())
		{
			dfs(a, upto);
			if (compsz[upto][0] > compsz[upto][1]/2)
			{
				ans *= p[compsz[upto][0]]-1;
			}
			else ans *= p[compsz[upto][0]];
			ans %= mod;
			upto++;
		}
	}
	printf("%lld\n", ans);
}