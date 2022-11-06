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
int isMinus[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll minus = 0, plus = 0;

	bool isMinus = false;
	ll plusNum = 0;
	ll minusNum = 0;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		if (t > 0)
		{
			plusNum++;
			plus += plusNum;
			minus += minusNum;
		}
		else
		{
			swap(plusNum, minusNum);
			minusNum++;
			plus += plusNum;
			minus += minusNum;
		}
	}

	cout << minus << ' ' << plus;
}