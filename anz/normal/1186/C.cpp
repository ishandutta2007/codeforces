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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int b_0 = 0, b_1 = 0;

int a_0[1000001], a_1[1000001];

int main()
{
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '0') b_0++;
		else b_1++;
	}

	for (int i = 1; i <= a.size(); i++)
	{
		if (a[i-1] == '0') a_0[i]++;
		else a_1[i-1]++;


		a_0[i] += a_0[i - 1];
		a_1[i] += a_1[i - 1];

	}

	int ans = 0;

	for (int i = 0; i + b.size() <= a.size(); i++)
	{
		int c_0 = a_0[i + b.size()] - a_0[i];
		int c_1 = a_1[i + b.size()] - a_1[i];

		if (c_0 % 2 == b_0 % 2) ans++;
	}

	printf("%d", ans);
}