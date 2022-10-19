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

const int N = 2010;
vector<int> A[N];
int c[N];
int s[N];
int n;
int fans[N];

bool check1(int u)
{
	bool flag = 1;
	int ans = 1;
	for (int v : A[u])
	{
		flag &= check1(v);
		ans += s[v];
	}
	s[u] = ans;
	if (ans <= c[u])
		flag = 0;
	return flag;
}

int linv[N] = {};
int linn[N] = {};
int lins = -1;
int line = 0;
int nxt = 1;

void Do(int u)
{
	for (int v : A[u])
		Do(v);
	fans[u] = nxt++;
	linv[line] = u; linn[line] = lins; lins = line++;
	if (s[u] - 1 - c[u])
	{
		int k = lins;
		Loop(i, 0, s[u] - 1 - c[u])
			k = linn[k];
		fans[u] = fans[linv[k]] + 1;
		k = lins;
		Loop(i, 0, s[u] - 1 - c[u])
		{
			k = linn[k];
			fans[linv[k]]++;
		}
		int tmp = linn[lins];
		linn[lins] = linn[k];
		linn[k] = lins;
		lins = tmp;
	}
}

int main()
{
	FAST;
	cin >> n;
	int P;
	Loop(i, 0, n)
	{
		int p;
		cin >> p >> c[i];
		if (p != 0)
			A[p - 1].push_back(i);
		else
			P = i;
	}
	if (!check1(P))
		Kill("NO");
	Do(P);
	cout << "YES\n";
	Loop(i, 0, n)
		cout << fans[i] << ' ';
}