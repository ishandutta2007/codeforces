#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int q[100001][3];
vector <int> idx[100001];

bool cache[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int a; cin >> a;
			q[i][j] = a;
			idx[a].push_back(i);
		}
		sort(q[i], q[i] + 3);
	}

	int n1 = -1;
	int n2 = -1;

	int ci = -1;
	for (int i = 1; i <= n; i++)
	{
		if (idx[i].size() == 1)
		{
			n1 = i;
			ci = idx[i][0];

			for (int j = 0; j < 3; j++)
			{
				if (idx[q[ci][j]].size() == 2)
				{
					n2 = q[ci][j];
					break;
				}
			}
			break;
		}
	}

	cout << n1 << ' ' << n2;
	cache[ci] = true;
	for (int i = 2; i < n; i++)
	{
		int n3 = -1;
		for (int j = 0; j < 3; j++)
		{
			if (q[ci][j] != n1 && q[ci][j] != n2)
				n3 = q[ci][j];
		}

		cout << ' ' << n3;
		
		for (auto it : idx[n3])
		{
			if (it == ci) continue;
			bool flag = false;
			for (int j = 0; j < 3; j++)
			{
				if (q[it][j] == n2)
				{
					flag = true;
					break;
				}
			}

			if (flag)
			{
				ci = it;
				break;
			}
		}

		n1 = n2, n2 = n3;
	}
}