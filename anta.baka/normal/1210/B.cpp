#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>
#include <map>
#include <array>
#include <bitset>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int N = 7e3 + 100;

int n;
ll a[N];
int b[N];
int deg[N];
bool ban[N];

bitset<N> r[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(i != j) {
		if ((a[i] & a[j]) == a[i]) {
			r[j][i] = 1;
			deg[i]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		ban[v] = true;
		for (int i = 0; i < n; i++) if (r[v][i]) {
			deg[i]--;
			if (deg[i] == 0) q.push(i);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) if (!ban[i]) ans += b[i];
	cout << ans;
}