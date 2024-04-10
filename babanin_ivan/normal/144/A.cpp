#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n;
int a[1000];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int minx = inf;
	int maxx = -1;
	for (int i = 0; i < n; ++i) {
		minx = min(minx, a[i]);
		maxx = max(maxx, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == maxx) {
			int j = i;
			while (j != 0) {
				swap(a[j], a[j - 1]);
				++ans;
				--j;
			}
			break;
		}
	for (int i = n - 1; i >= 0; --i)
		if (a[i] == minx) {
			int j = i;
			while (j != (n - 1)) {
				//swap(a[j], a[j - 1]);
				++ans;
				++j;
			}
			break;
		}
	cout << ans << endl;
	return 0;
}