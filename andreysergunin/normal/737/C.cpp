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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;    

const ll INF = 1e10;

int main() {
	ios_base::sync_with_stdio(0);

	int n, s;
	cin >> n >> s;
	--s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);

	for (int i = 0; i < n; ++i) {
		if (i != s)
			++b[a[i]];
	}

	vector<int> suff(n + 1);
	suff[n] = 0;
	for (int i = n - 1; i >= 0; --i)
		suff[i] = suff[i + 1] + b[i];

	int ans = n - 1;
	int cur = 0;
	for (int i = 1; i < n; ++i) {
		if (!b[i])
			++cur;

		ans = min(ans, max(cur, suff[i + 1] + b[0]) );
	}

	if (a[s] != 0)
		++ans;

	cout << ans << endl;
	return 0;
}