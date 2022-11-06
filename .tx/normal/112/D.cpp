#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y, ans;
	cin >> n;
	vector<int> a(100001, -1);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		ans = 0;
		for (int g = 1; g <= floor(sqrt(x + .0)); g++) {
			if (x % g == 0) {
				if (a[g] < i - y) {
					ans++;
				}
				a[g] = i;
				if (a[x / g] < i - y) {
					ans++;
				}
				a[x / g] = i;
			}
		}
		printf("%d\n", ans);
	}
	
	
	
	
	return 0;
}//yzhhkk