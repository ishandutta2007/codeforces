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
ll g[maxn];
vector <int> ed[maxn];

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

vector <pair <ll, int> > buf;

const int mod = (int)1e9 + 7;

ll go(int v, int p, vector <pair <ll, int> > f) {
	for (int i = 0; i < (int)f.size(); i++) {
		f[i].first = gcd(f[i].first, g[v]);
	}

	buf.clear();

	f.push_back(mp(g[v], 1));

	ll ans = 0;

	for (int i = 0; i < (int)f.size(); i++) {
		ans += f[i].first * f[i].second;
		if (!buf.empty() && buf.back().first == f[i].first) {
			buf.back().second += f[i].second;
		}
		else {
			buf.push_back(f[i]);
		}
	}

	ans %= mod;

	f = buf;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			ans += go(u, v, f);
		}
	}

	return ans % mod;
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &g[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	vector <pair <ll, int> > f;
	
	cout << go(1, 1, f) << endl;

	//system("pause");
}