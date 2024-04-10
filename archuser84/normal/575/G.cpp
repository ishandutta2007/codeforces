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

const int N = 100010;
vector<int> A[10][N];
int n, m;

int par[N];
int yal[N];
bool tag[N] = {};
int ezaf[N];
void get_tag(int s)
{
	queue<int> Q;
	tag[s] = true;
	par[s] = -1;
	memset(ezaf, -1, sizeof(ezaf));
	ezaf[s] = 0;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int v : A[0][u])
		{
			if (!tag[v])
			{
				tag[v] = true;
				par[v] = u;
				ezaf[v] = ezaf[u] + 1;
				Q.push(v);
			}
		}
	}
}

int d[N];
void get_d(int s)
{
	memset(d, -1, sizeof(d));
	queue<int> Q;
	d[s] = 0;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		Loop(w, 0, 10)
		{
			for (int v : A[w][u])
			{
				if (d[v] == -1)
				{
					d[v] = d[u] + 1;
					Q.push(v);
				}
			}
		}
	}
}

void get_par()
{
	vector<int> Q;
	Loop(i,0,n)
		if (tag[i])
			Q.push_back(i);
	int s = 0;
	int e = Q.size();
	int min_d = Mod1;
	for(int i : Q)
		min_d = min(min_d, d[i]);
	Loop(i, s, e)
		if (d[Q[i]] == min_d)
			Q.push_back(Q[i]);
	s = e;
	e = Q.size();
	while (true)
	{
		int dis = d[Q[s]];
		if (dis == 0)
			break;
		int min_w;
		Loop(w, 0, 10)
		{
			Loop(i, s, e)
			{
				for (int v : A[w][Q[i]])
					if (d[v] == dis - 1)
					{
						min_w = w;
						goto lb;
					}
			}
		}
	lb:
		Loop(i, s, e)
		{
			for (int v : A[min_w][Q[i]])
				if (d[v] == dis - 1)
				{
					if (ezaf[v] == -1)
					{
						yal[v] = min_w;
						par[v] = Q[i];
						ezaf[v] = ezaf[Q[i]];
						Q.push_back(v);
					}
					else if (ezaf[Q[i]] < ezaf[v])
					{
						par[v] = Q[i];
						ezaf[v] = ezaf[Q[i]];
					}
				}
		}
		s = e;
		e = Q.size();
	}
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		A[w][u].push_back(v);
		A[w][v].push_back(u);
	}
	get_tag(n - 1);
	get_d(0);
	get_par();
	int i = 0;
	stack<int> S;
	while (par[i] != -1)
	{
		S.push(yal[i]);
		i = par[i];
	}
	int ans = 1 + S.size();
	bool flag = 0;
	while (!S.empty())
	{
		int x = S.top();
		S.pop();
		if (x != 0)
			flag = true;
		if (flag)
			cout << x;
	}
	if (!flag)
		cout << 0;
	cout << '\n' << ans << '\n';
	i = 0;
	while (i != -1)
	{
		cout << i << ' ';
		i = par[i];
	}
}