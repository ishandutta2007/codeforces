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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 400010;

class TWO_SAT {
	vector<int> A[N], T[N];
	int tag[N], somev[N];
	int noot[N];

	vector<int> topo;
	bool vis1[N];
	void dfs1(int u)
	{
		vis1[u] = true;
		for (auto v : A[u])
			if (!vis1[v])
				dfs1(v);
		topo.push_back(u);
	}

	bool vis2[N];
	void dfs2(int u, int k)
	{
		vis2[u] = true;
		tag[u] = k;
		for (auto v : T[u])
			if (!vis2[v])
				dfs2(v, k);
	}

	int dagN;
	void makeDag(int n)
	{
		memset(tag, -1, sizeof(tag));
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		Loop(i, 0, n)
			if (!vis1[i])
				dfs1(i);
		dagN = 0;
		reverse(all(topo));
		for(auto u : topo)
		{
			if (!vis2[u])
			{
				somev[dagN] = u;
				dfs2(u, dagN++);
			}
		}
	}

	bool did[N];
	bool ans[N];
	bool solve()
	{
		for (int so : topo)
		{
			if (did[tag[so]])
				continue;
			int si = noot[so];
			if (tag[si] == tag[so])
				return false;
			ans[tag[si]] = 1;
			ans[tag[so]] = 0;
			did[tag[si]] = true;
			did[tag[so]] = true;
		}
		return true;
	}

	int satn = 0;
	int mapp[N];
	bool exist = false;

public:

	TWO_SAT() { memset(mapp, -1, sizeof(mapp)); }

	bool Exist() { return exist; }

	bool Solve()
	{
		makeDag(satn);
		exist = solve();
		return exist;
	}

	void addClaw(int x1, int x2, bool b1, bool b2)
	{
		if (mapp[x1] == -1)
		{
			mapp[x1] = satn++;
			noot[mapp[x1]] = satn++;
			noot[noot[mapp[x1]]] = mapp[x1];
		}
		if (mapp[x2] == -1)
		{
			mapp[x2] = satn++;
			noot[mapp[x2]] = satn++;
			noot[noot[mapp[x2]]] = mapp[x2];
		}
		x1 = mapp[x1]; if (b1) x1 = noot[x1];
		x2 = mapp[x2]; if (b2) x2 = noot[x2];
		A[noot[x1]].push_back(x2);
		A[noot[x2]].push_back(x1);
		T[x1].push_back(noot[x2]);
		T[x2].push_back(noot[x1]);
	}

	bool Ans(int x) { return ans[tag[mapp[x]]]; }
}sat;

bool rstat[N];
vector<int> A[N];
int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> rstat[i];
	Loop(i, 0, m)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int u;
			cin >> u; u--;
			A[u].push_back(i);
		}
	}
	Loop(i, 0, n)
	{
		sat.addClaw(A[i][0], A[i][1], 0, 0 ^ rstat[i]);
		sat.addClaw(A[i][0], A[i][1], 1, 1 ^ rstat[i]);
	}
	cout << YN(sat.Solve()) << '\n';
}