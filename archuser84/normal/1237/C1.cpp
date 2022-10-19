#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 50010;
ll x[N], y[N], z[N];
int n;
map<ll, vector<int>> m;
map<ll, vector<int>> m2;

void print(int i, int j)
{
	cout << i + 1 << ' ' << j + 1 << '\n';
}

int Solve1(vector<int>& in)
{
	sort(all(in), [](int i, int j) {return z[i] < z[j]; });
	for (int i = 0; i + 1 < in.size(); i += 2)
		print(in[i], in[i + 1]);
	if (in.size() & 1)
		return in.back();
	return -1;
}

int Solve2(vector<int>& in)
{
	map<ll, vector<int>> m;
	vector<int> solve;
	for (int p : in)
		m[y[p]].push_back(p);
	for (auto p : m)
	{
		int k = Solve1(p.second);
		if (k != -1)
			solve.push_back(k);
	}
	for (int i = 0; i + 1 < solve.size(); i += 2)
		print(solve[i], solve[i + 1]);
	if (solve.size() & 1)
		return solve.back();
	return -1;
}

int Solve3(vector<int>& in)
{
	map<ll, vector<int>> m;
	vector<int> solve;
	for (int p : in)
		m[x[p]].push_back(p);
	for (auto p : m)
	{
		int k = Solve2(p.second);
		if (k != -1)
			solve.push_back(k);
	}
	for (int i = 0; i + 1 < solve.size(); i += 2)
		print(solve[i], solve[i + 1]);
	if (solve.size() & 1)
		return solve.back();
	return -1;
}

int main()
{
	FAST;
	cin >> n;
	vector<int> in;
	Loop(i, 0, n)
	{
		in.push_back(i);
		cin >> x[i] >> y[i] >> z[i];
	}
	Solve3(in);
}