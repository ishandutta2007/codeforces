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

const int N = 200010;

vector<pii> T[4];
int n, m, k;
int p[4] = {};
int ans[4] = {}, anssum = (1 << 31) - 1;
int sum = 0;
bool found = 0;

bool nex()
{
	int k = 0; while (p[k] == T[k].size())k++;
	if (k == 3)
		return 0;
	if (p[1] < T[1].size() && T[1][p[1]] < T[k][p[k]])
		k = 1;
	if (p[2] < T[2].size() && T[2][p[2]] < T[k][p[k]])
		k = 2;
	sum += T[k][p[k]++].first;
	return 1;
}
bool pre()
{
	int k = 0; while (!p[k])k++;
	if (k == 3)
		return 0;
	if (p[1] && T[1][p[1] - 1] > T[k][p[k] - 1])
		k = 1;
	if (p[2] && T[2][p[2] - 1] > T[k][p[k] - 1])
		k = 2;
	sum -= T[k][--p[k]].first;
	return 1;
}

void setAns()
{
	if (anssum <= sum)
		return;
	anssum = sum;
	ans[0] = p[0];
	ans[1] = p[1];
	ans[2] = p[2];
	ans[3] = p[3];
	found = 1;
}

int used() { return p[0] + p[1] + p[2] + p[3]; }

int main()
{
	FAST;
	cin >> n >> m >> k;
	Loop(i, 0, n)
	{
		int t, a, b;
		cin >> t >> a >> b;
		T[2 * a + b].push_back({ t,i });
	}
	sort(all(T[0])); sort(all(T[1])); sort(all(T[2])); sort(all(T[3]));
	if (2 * k > m)
	{
		p[3] = 2 * k - m;
		k -= p[3];
	}
	if (min(T[1].size(), T[2].size()) < k)
	{
		p[3] += k - min(T[1].size(), T[2].size());
		k = min(T[1].size(), T[2].size());
	}
	if (p[3] > T[3].size())
		Kill(-1);
	p[1] = k;
	p[2] = k;
	Loop(i, 0, k)
		sum += T[1][i].first + T[2][i].first;
	Loop(i, 0, p[3])
		sum += T[3][i].first;
	while (used() < m && used() - p[3] < n - T[3].size())
		nex();
	while(used() < m)
		sum += T[3][p[3]++].first;
	setAns();
	while (p[3] < T[3].size())
	{
		sum += T[3][p[3]++].first;
		int cnt = 0;
		if (p[0])
			sum -= T[0][--p[0]].first, cnt++;
		if(p[1])
			sum -= T[1][--p[1]].first, cnt++;
		if(p[2])
			sum -= T[2][--p[2]].first, cnt++;
		if (cnt == 0)
			break;
		Loop(i, 1, cnt)
			nex();
		setAns();
	}
	if (!found)
		Kill("Error!\n");
	cout << anssum << '\n';
	Loop(i, 0, 4)
		Loop(j, 0, ans[i])
			cout << T[i][j].second + 1 << ' ';
}