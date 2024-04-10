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
int seat[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> seat[i];

	int sum = 0;
	for (int i = 0; i < n; i++) sum += seat[i];

	vector <int> ans;
	ans.push_back(0);
	int curSum = seat[0];
	for (int i = 1; i < n; i++)
	{
		if (seat[i] * 2 <= seat[0])
		{
			ans.push_back(i);
			curSum += seat[i];
		}
	}

	if (curSum > sum / 2)
	{
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] + 1 << ' ';
	}
	else cout << 0;
}