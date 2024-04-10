#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<bool> vis(n);
	for(int i = 0; i < n-1; i ++) {
		int x;
		scanf("%d", &x), x --;
		vis[x] = true;
	}
	int ans = find(vis.begin(), vis.end(), false) - vis.begin();
	printf("%d\n", ans + 1);
	return 0;
}