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
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

const int MAXN = 200000;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> s(MAXN);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++s[a[i]];
	}

	int ans = 1;
	for (int i = 2; i < MAXN; ++i) {
		int cur = 0;
		for (int j = 1; i * j < MAXN; ++j)
			cur += s[i * j];
		if (ans < cur)
			ans = cur;
	}

	cout << ans << endl;

}