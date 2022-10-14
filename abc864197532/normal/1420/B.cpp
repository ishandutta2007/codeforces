#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <string>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, tmp;
    	cin >> n;
    	int a[31] = {};
    	for (int i = 0; i < n; ++i) {
    		cin >> tmp;
    		a[__lg(tmp)]++;
		}
		long long ans = 0;
		for (int i = 0; i < 31; ++i) ans += 1ll * a[i] * (a[i] - 1) / 2;
		cout << ans << endl;
	}
}