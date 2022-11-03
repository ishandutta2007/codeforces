#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <string>
#include <iomanip>
#include <functional>
#include <limits>
#include <map>

#define pb push_back
#define mp make_pair
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define forv(i, n) for (int i = 0; i < n; i++)
#define forie(n) for (int i = 1; i <= n; i++)
#define forje(n) for (int j = 1; j <= n; j++)
#define forve(i, n) for (int i = 1; i <= n; i++)
#define ll long long
#define uns unsigned
#define endl '\n'

#pragma warning (disable : 4996)

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vector <int>> vvi;

const int N = 300 + 10;

int n;
vi a;
vector<char> used;

void rec(int i) {
	if (i == -1)
		return;
	if (used[i])
		return;
	used[i] = 1;
	rec(a[i] - 1);
	return;
}

int main()
{
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	a.resize(n);
	used.resize(n);
	fill(used.begin(), used.end(), 0);

	fori(n)
		cin >> a[i];

	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
		if (!used[i]) {
			rec(i);
			ans++;
		}

	cout << ans;

	return 0;
}