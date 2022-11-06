#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[100001];
int hasEven[100001], hasOdd[100001];
int isLeaf[100001];

bool hasOddLength = false;
void DFS(int v, int p) // even, odd
{
	int& even = hasEven[v];
	int& odd = hasOdd[v];

	if (graph[v].size() == 1)
	{
		isLeaf[v] = 1;
		if (v != 1) return;
	}

	for (auto nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);

		if (isLeaf[nv])
		{
			odd |= 1;
		}
		else
		{
			even |= hasOdd[nv];
			odd |= hasEven[nv];
		}
	}

	if (even && odd) hasOddLength = true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 0);

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (auto nv : graph[i])
		{
			if (isLeaf[nv]) cnt++;
		}

		res += max(0, cnt - 1);
	}

	if (isLeaf[1] && hasOdd[1]) hasOddLength = true;

	if (hasOddLength)
	{
		cout << "3 " << n - 1 - res;
	}
	else
	{
		cout << "1 " << n - 1 - res;
	}
}