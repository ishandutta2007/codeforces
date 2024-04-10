/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
 
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

const int maxn = (int)1e4 + 10;
pii v[maxn];
vector <pii> ans;

void make(int l, int r) {
	if (l == r) {
		return;
	}

	int m = (l + r) >> 1;

	make(l, m);
	make(m + 1, r);

	int x = v[m].first;

	for (int i = l; i <= r; i++) {
		ans.push_back(mp(x, v[i].second));
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
		ans.push_back(v[i]);
	}

	sort(v, v + n);

	make(0, n - 1);

	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}