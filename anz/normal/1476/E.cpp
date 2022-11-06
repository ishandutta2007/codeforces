#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;

string p[100001];
string s[100001];
int mt[100001];

int ridx[600001];

vector <int> graph[100001];
int in[100001];
vector <int> ans;

int getHash(string s)
{
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans *= 27;
		if (s[i] == '_') continue;
		else ans += s[i] - 'a' + 1;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		int idx = getHash(p[i]);
		ridx[idx] = i;
	}

	bool hasAns = true;
	for (int i = 1; i <= m; i++)
	{
		cin >> s[i] >> mt[i];

		bool flag = false;
		vector <int> vec;

		for (int bt = 0; bt < (1 << k); bt++)
		{
			string tmp = s[i];
			for (int j = 0; j < k; j++)
			{
				if (bt & (1 << j)) tmp[j] = '_';
			}

			int idx = getHash(tmp);
			if (ridx[idx] == 0) continue;

			if (ridx[idx] == mt[i]) flag = true;
			else vec.push_back(ridx[idx]);
		}

		if (!flag)
		{
			hasAns = false;
			break;
		}

		for (int v : vec)
		{
			graph[mt[i]].push_back(v);
			in[v]++;
		}
	}

	int cnt = 0;
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);

	while (!q.empty())
	{
		int v = q.front(); q.pop(); cnt++;
		ans.push_back(v);

		for (int nv : graph[v])
			if (--in[nv] == 0) q.push(nv);
	}

	if (cnt < n) hasAns = false;

	if (!hasAns)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int v : ans) cout << v << ' ';
}