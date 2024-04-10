#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;
 
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
 
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
 
 
 
const int N = 1e5 + 30;
const lli mod = 1e9 + 7;
int n, k;
vector <pair<int, int> > g[N];
int ver[N], ner[N][2];
int sm, mx = mod;
int pat;
void dfs1(int v, int par)
{
	vector <int> sm;
	for (auto p : g[v])
	{
		if (p.fr == par) continue;
		dfs1(p.fr, v);
		sm.PB(p.sc + ner[p.fr][0]);
	}
	sort(sm.begin(), sm.end(), greater<int>());
	for (int i = 0; i < 2 && i < sm.size(); i++) ner[v][i] = sm[i];
	
}
void dfs2(int v, int par)
{
	for (auto p : g[v])
	{
		if (p.fr == par) continue;
		if (p.sc + ner[p.fr][0] == ner[v][0])
			ver[p.fr] = max(ver[v] + p.sc, p.sc + ner[v][1]);
		else
			ver[p.fr] = max(ver[v] + p.sc, p.sc + ner[v][0]);
		dfs2(p.fr, v);
	}
}
pair<int, int> nr[N];
void dfs3(int v, int par)
{
	for (auto p : g[v])
	{
		if (p.fr == par) continue;
		dfs3(p.fr, v);
		if (nr[v].fr < p.sc + nr[p.fr].fr)
			nr[v] = MP(p.sc + nr[p.fr].fr, p.fr);
	}
}
bool col[N];
int main()
{
 
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].PB(MP(b, c));
		g[b].PB(MP(a, c));
	}
	dfs1(1, -1);
	dfs2(1, -1);
	for (int i = 1; i <= n; i++)
	{
		if (max(ver[i], ner[i][0]) < mx)
		{
			sm = i;
			mx = max(ver[i], ner[i][0]);
		}
	}
	dfs3(sm, -1);
	col[sm] = true;
	int l = sm, r = sm;
	for (int i = 0; i < k - 1; i++)
	{
		if (nr[l].fr == 0 && nr[r].fr == 0) break;
		if (col[nr[l].sc])
		{
			nr[l] = MP(0, 0);
			for (auto p : g[l])
			{
				if (col[p.fr]) continue;
				if (nr[l].fr < p.sc + nr[p.fr].fr)
					nr[l] = MP(p.sc + nr[p.fr].fr, p.fr);
			}
		}
		if (col[nr[r].sc])
		{
			nr[r] = MP(0, 0);
			for (auto p : g[r])
			{
				if (col[p.fr]) continue;
				if (nr[r].fr < p.sc + nr[p.fr].fr)
					nr[r] = MP(p.sc + nr[p.fr].fr, p.fr);
			}
		}
		if (nr[l].fr > nr[r].fr)
		{
			l = nr[l].sc;
			col[l] = true;
			//cout << "l-" << l << endl;
		}
		else
		{
			r = nr[r].sc;
			col[r] = true;
			//cout << "r-" << r << endl;
		}
		//cout << i << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (col[i])
		{
			for (auto p : g[i])
			{
				if (col[p.fr]) continue;
				pat = max(pat, p.sc + nr[p.fr].fr);
			}
		}
	}
	cout << pat << endl;
	return 0;
}