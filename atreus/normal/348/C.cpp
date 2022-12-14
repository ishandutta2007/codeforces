#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 100;
const int SQRT = 400;

ll a[maxn], sum[maxn];
vector <int> se[maxn], v;
bool boz[maxn], mark[maxn];
int dp[maxn][SQRT + 100];
ll lazy[maxn];


int main () {
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			se[i].PB (x);
			sum[i] += a[x];
		}
		if (k >= SQRT) {
			v.PB (i);
			boz[i] = 1;
		}
	}
	for (int p = 0; p < v.size(); p++) {
		int x = v[p];
		for (auto j : se[x])
			mark[j] = 1;
		for (int i = 1; i <= m; i++) {
			for (auto j : se[i]) {
				dp[i][p] += mark[j];
			}
		}
		for (auto j : se[x])
			mark[j] = 0;
	}

	for (int i = 1; i <= q; i++) {
		char type;
		cin >> type;
		if (type == '?') {
			int x;
			cin >> x;
			if (boz[x]) {
				cout << sum[x] << '\n';
			}
			else {
				ll ans = 0;
				for (auto j : se[x])
					ans += a[j];
				for (int j = 0; j < v.size(); j++)
					ans += 1ll * lazy[v[j]] * dp[x][j];
				cout << ans << '\n';
			}
		}
		else {
			int x, val;
			cin >> x >> val;
			for (int j = 0; j < v.size(); j++)
				sum[v[j]] += 1ll * dp[x][j] * val;
			if (!boz[x])
				for (auto j : se[x])
					a[j] += val;
			else
				lazy[x] += val;
		}
	}
}