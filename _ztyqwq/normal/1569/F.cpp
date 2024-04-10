#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int n, hf;
bool g[50][50];
inline void addedge(int from, int to)
{
	g[from][to] = g[to][from] = true;
}
int makepair[50];
int chains[50][2], belong[50];
int p[50];

bool check()
{
	for(int i = 1; i <= hf; i++)
		p[i] = i;
	do
	{
		for(int i = 1; i < hf; i++)
		{
			if(g[ chains[p[i]][0] ][ chains[p[i + 1]][0] ] && g[ chains[p[i]][1] ][ chains[p[i + 1]][1] ]);
			else if(g[ chains[p[i]][0] ][ chains[p[i + 1]][1] ] && g[ chains[p[i]][1] ][ chains[p[i + 1]][0] ]);
			else
				goto no;
		}
		if(!g[chains[p[hf]][0]][chains[p[hf]][1]])
			continue;
		return true;
		no:;
	}
	while(next_permutation(p + 1, p + hf + 1));
	return false;
}
vector< vector<int> > colors;
vector<int> nowcolor;
void color(int u, int now)
{
	if(u == hf + 1)
	{
		nowcolor[0] = now - 1;
		colors.push_back(nowcolor);
		return;
	}
	for(int i = 1; i <= now; i++)
	{
		nowcolor[u] = i;
		color(u + 1, max(now, i + 1));
	}
}
set< pair<int, int> > anss;
void dfs(int u, int now)
{
	while(u <= n && makepair[u])
		u++;
	if(u == n + 1)
	{
		bool ok = check();
		if(!ok)
			return;
		for(auto vec: colors)
		{
			int Hash = 0;
			for(int i = 1; i <= n; i++)
				Hash = Hash * 6 + (vec[belong[i]] - 1);
			anss.insert({Hash, vec[0]});
		}
		return;
	}
	for(int i = u + 1; i <= n; i++)
		if(!makepair[i])
		{
			// make pair u - i
			makepair[u] = i, makepair[i] = u;
			chains[now][0] = u, chains[now][1] = i;
			belong[u] = belong[i] = now;
			dfs(u + 1, now + 1);
			makepair[u] = makepair[i] = 0;
		}
}
int fac[50];
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i;
}
inline int A(int n, int m)
{
	return n < m ? 0 : fac[n] / fac[n - m];
}
signed main()
{
	memset(g, false, sizeof(g));
	InitFac(15);
	int m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	hf = n >> 1;
	while(m--)
	{
		int u, v;
		scanf("%lld %lld", &u, &v);
		addedge(u, v);
	}
	memset(makepair, 0, sizeof(makepair));
	nowcolor.resize(50);
	color(1, 1);
	dfs(1, 1);
	int ans = 0;
	for(auto x: anss)
	{
		int cnt = x.second;
		ans += A(k, cnt);
	}
	printf("%lld\n", ans);
	return 0;
}