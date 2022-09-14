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
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());


int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x;
	cin >> n >> k >> x;
	vector<int> cur(1 << 10), next(1 << 10);
	for (int i = 0; i < n; ++i)  {
		int a;
		cin >> a;
		++cur[a];
	}

	for (int i = 0; i < k; ++i) {
		next.assign(1 << 10, 0);
		int par = 0;
		for (int j = 0; j < (1 << 10); ++j)  {
			if (!par) {
				next[j ^ x] += (cur[j] + 1) / 2;
				next[j] += cur[j] / 2;
			} else {	
				next[j] += (cur[j] + 1) / 2;
				next[j ^ x] += cur[j] / 2;
			}
			par += cur[j];
			par &= 1;
		}
		swap(next, cur);
	}

	int maxx = -1, minn = 1024;
	for (int i = 0; i < 1 << 10; ++i) {
		if (cur[i]) {
			minn = min(minn, i);
			maxx = max(maxx, i);
		}
	}
	cout << maxx << " " << minn << endl;
}