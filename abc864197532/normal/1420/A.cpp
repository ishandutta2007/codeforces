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
    	int n;
    	cin >> n;
    	int tmp, pre;
    	bool is = false;
    	cin >> tmp;
    	for (int i = 1; i < n; ++i) {
    		cin >> pre;
    		is |= tmp <= pre;
    		tmp = pre;
		}
		cout << (is ? "YES\n" : "NO\n");
	}
}