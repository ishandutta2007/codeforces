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
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2020;

bitset<MAXN + MAXN> mat[MAXN];

int main()
{
	// ifstream cin("joke.in");
	// ofstream cout("joke.out");

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> g;

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		mat[u][v] = 1;
		g.push_back({u, v});
	}

	for (int i = 0; i < n; ++i)
		mat[i][n + i] = 1;

	for (int i = 0; i < n - 1; ++i) {
		int k = i;
		for (; !mat[k][i]; ++k);

		swap(mat[i], mat[k]);

		for (int j = i + 1; j < n; ++j) {
			if (mat[j][i])
				mat[j] ^= mat[i];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j)
			if (mat[j][i])
				mat[j] ^= mat[i];
	}

	for (int i = 0; i < m; ++i) {
		if (mat[g[i].second][g[i].first + n]) 
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	

}