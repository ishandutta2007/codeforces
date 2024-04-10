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

const int N = 300010;

int E[N][2];
int cnt[N] = {};
char state[N];
int n, k;
int par[N + 1];
bool rel[N + 1];
int minoff[N + 1];
int minon[N + 1];
int ans = 0;

pair<int, bool> getpar(int v)
{
	if (par[v] == -1)
		return { v,0 };
	auto tmp = getpar(par[v]);
	par[v] = tmp.first;
	rel[v] = rel[v] != tmp.second;
	return { par[v],rel[v] };
}

void dsu(int a, int b, bool r)
{
	auto tmp = getpar(a);
	r = r != tmp.second;
	a = tmp.first;
	tmp = getpar(b);
	r = r != tmp.second;
	b = tmp.first;
	if (a == b)
		return;
	par[b] = a;
	rel[b] = r;
	ans -= min(minon[a], minoff[a]);
	ans -= min(minon[b], minoff[b]);
	if (r)
	{
		minon[a] += minoff[b];
		minoff[a] += minon[b];
	}
	else
	{
		minon[a] += minon[b];
		minoff[a] += minoff[b];
	}
	ans += min(minon[a], minoff[a]);
}

void setup()
{
	memset(par, -1, sizeof(par));
	memset(rel, 0, sizeof(rel));
	Loop(i, 0, N)
	{
		minoff[i] = 0;
		minon[i] = 1;
	}
	minon[N] = N;
	minoff[N] = 0;
}

int main()
{
	FAST;
	setup();
	cin >> n >> k;
	cin >> state;
	Loop(i, 0, k)
	{
		int c;
		cin >> c;
		Loop(j, 0, c)
		{
			int x;
			cin >> x; x--;
			E[x][cnt[x]++] = i;
		}
	}
	Loop(i, 0, n)
		while (cnt[i] < 2)
			E[i][cnt[i]++] = N;
	Loop(i, 0, n)
	{
		dsu(E[i][0], E[i][1], !(state[i] - '0'));
		cout << ans << '\n';
	}
}