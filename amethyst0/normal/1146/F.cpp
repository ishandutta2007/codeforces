#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int mod = 998244353;
const int maxn = (int)2e5 + 10;

vector <int> ed[maxn];
int dp[maxn][2];

void go(int v) {
	if (ed[v].empty()) {
		dp[v][0] = 1;
		dp[v][1] = 1;
		return;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		go(u);
	}

	int res[3];
	res[0] = res[1] = res[2] = 0;
	res[0] = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		res[2] = ((ll)res[2] * dp[u][0] + (ll)(res[2] + res[1]) * dp[u][1]) % mod;
		res[1] = ((ll)res[1] * dp[u][0] + (ll)res[0] * dp[u][1]) % mod;
		res[0] = (ll)res[0] * dp[u][0] % mod;
	}

	dp[v][0] = ((ll)res[0] + res[2]) % mod;
	dp[v][1] = ((ll)res[1] + res[2]) % mod;
}

int main() {
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;

		scanf("%d", &p);
		ed[p].push_back(i);
	}

	go(1);
	cout << dp[1][0] << endl;

	//system("pause");

	return 0;
}