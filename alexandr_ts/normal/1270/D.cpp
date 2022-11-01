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
#include <numeric>

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
	int n, k;
	cin >> n >> k;
	vector<int> pos(k + 1), val(k + 1);
	for (int i = 0; i <= k; i++) {
		cout << "? ";
		for (int j = 0; j <= k; j++) {
			if (i != j) {
				cout << j + 1 << " ";
			}
		}
		cout << endl;
		cin >> pos[i] >> val[i];
	}
	sort(val.begin(), val.end());
	int ans = count(val.begin(), val.end(), val.back());
	cout << "! " << ans << endl;
}


int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}