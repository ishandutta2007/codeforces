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
int b[N];

void solve() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	for (int i = 0; i < k1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k2; i++) {
		cin >> b[i];
	}
	if (*max_element(a, a + k1) > * max_element(b, b + k2)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}


int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	solve();
}