//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
int cnt[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		if (x > y) {
			swap(x, y);
		}

		cnt[x]++;
		cnt[y]++;
		ed[x].push_back(y);
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += (ll)(cnt[i] - (int)ed[i].size()) * ed[i].size();
	}

	int q;

	cin >> q;

	printf("%lld\n", ans);

	while (q--) {
		int x;

		scanf("%d", &x);

		ans -= (ll)(cnt[x] - (int)ed[x].size()) * ed[x].size();

		for (int i = 0; i < (int)ed[x].size(); i++) {
			int u = ed[x][i];

			ans -= (ll)(cnt[u] - (int)ed[u].size()) * ed[u].size();
			ed[u].push_back(x);
			ans += (ll)(cnt[u] - (int)ed[u].size()) * ed[u].size();
		}

		ed[x].clear();

		printf("%lld\n", ans);
	}

	//system("pause");
}