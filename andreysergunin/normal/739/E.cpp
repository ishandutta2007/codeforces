#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;	
	
const int MAXN = 2020;
double dp[MAXN][MAXN];

int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	iostream::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	vector<double> p(n), q(n);

	for (int i = 0; i < n; ++i)
		cin >> p[i];

	for (int i = 0; i < n; ++i)
		cin >> q[i];

	for (int i = 0; i < n; ++i) {
		for (int j = min(a, i); j >= max(0, a - n + i); --j)
			for (int k = min(b, i); k >= max(0, b - n + i); --k) {
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + p[i]);
				dp[j][k + 1] = max(dp[j][k + 1], dp[j][k] + q[i]);
				dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k] + p[i] + q[i] - p[i] * q[i]);
			} 
	}

	cout.precision(10);
	cout << dp[a][b] << endl;
	return 0;
}