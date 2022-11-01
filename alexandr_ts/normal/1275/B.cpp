#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e5 + 1;
const int EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int a[N];

void solve() {
	int t;
	cin >> t;
	while (t--) {
		int h, m;
		cin >> h >> m;
		cout << 24 * 60 - h * 60 - m << endl;
	}
}


int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}