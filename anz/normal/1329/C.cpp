#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll h, g;
int idx[1048577];
int height[1048577];
int org_pq[1048577];
int pq[1048577];

vector <int> comp;
int getIdx(int x)
{
	return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}

void DFS(int v, int ch)
{
	if (v >= (1 << h)) return;
	height[v] = ch;
	DFS(v * 2, ch + 1);
	DFS(v * 2 + 1, ch + 1);
}

bool isOK(int v)
{
	int l, r;
	if (v * 2 >= (1 << h)) l = 0;
	else l = pq[v * 2];
	if (v * 2 + 1 >= (1 << h)) r = 0;
	else r = pq[v * 2 + 1];

	int org_l, org_r;
	if (v * 2 >= (1 << h)) org_l = 0;
	else org_l = org_pq[v * 2];
	if (v * 2 + 1 >= (1 << h)) org_r = 0;
	else org_r = org_pq[v * 2 + 1];

	if (l == 0 && r == 0)
	{
		if (height[v] > g)
		{
			pq[v] = 0;
			org_pq[v] = 0;
			return true;
		}
		else return false;
	}

	if (l > r)
	{
		if (isOK(v * 2))
		{
			idx[l] = v;
			pq[v] = l;
			org_pq[v] = org_l;
			return true;
		}
		else return false;
	}
	else
	{
		if (isOK(v * 2 + 1))
		{
			idx[r] = v;
			pq[v] = r;
			org_pq[v] = org_r;
			return true;
		}
		else return false;
	}
}

vector <int> ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ans.clear();
		comp.clear();

		cin >> h >> g;
		for (int i = 1; i <= (1 << h) - 1; i++)
		{
			cin >> org_pq[i];
			comp.push_back(org_pq[i]);
		}

		sort(comp.begin(), comp.end());

		for (int i = 1; i <= (1 << h) - 1; i++)
		{
			pq[i] = getIdx(org_pq[i]) + 1;
			idx[pq[i]] = i;
		}

		DFS(1, 1);

		int cur_num = (1 << h) - 1;
		int cnt = (1 << h) - (1 << g);
		while (cnt)
		{
			if (isOK(idx[cur_num]))
			{
				ans.push_back(idx[cur_num]);
				cnt--;
			}

			cur_num--;
		}

		ll sum = 0;
		for (int i = 1; i <= (1 << g) - 1; i++) sum += org_pq[i];

		cout << sum << '\n';
		for (auto it : ans) cout << it << ' ';
		cout << "\n";
	}
}