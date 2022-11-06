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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m;
string ans[1001];
int score[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> ans[i];

	for (int i = 0; i < m; i++) cin >> score[i];

	ll res = 0;
	for (int i = 0; i < m; i++)
	{
		int stu[5] = { 0, };

		ll mx = 0;
		for (int j = 0; j < n; j++)
		{
			stu[ans[j][i] - 'A']++;
			if (stu[ans[j][i] - 'A'] > mx)
				mx = stu[ans[j][i] - 'A'];
		}

		res += mx * score[i];
	}

	cout << res;
}