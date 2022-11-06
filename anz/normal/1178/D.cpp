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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;

int isPrime[10000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i < 100; i++)
	{
		if (isPrime[i] == 0)
		{
			for (int j = i + i; j < 10000; j += i)
				isPrime[j] = 1;
		}
	}

	cin >> n;
	if (n == 2)
	{
		cout << -1;
		return 0;
	}

	vector <pii> ans;
	for (int i = 0; i < n; i++)
		ans.push_back({ i + 1,(i + 1) % n + 1 });

	int ptr = 0;
	int curNum = n;
	while (isPrime[curNum] == 1)
	{
		ans.push_back({ ptr + 1,(ptr + n/2) % n + 1 });
		ptr++;
		curNum++;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << "\n";
}