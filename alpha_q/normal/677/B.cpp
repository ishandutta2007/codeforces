/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 50;

int n; long long h, k, ans = 0, sum = 0, height[MAX];

int main (int argc, char const *argv[]) {
	scanf("%d %I64d %I64d", &n, &h, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", height + i);
	}	

	for (int i = 1; i <= n; ++i) {
		if (sum + height[i] <= h) sum += height[i];
		else {
			ans += sum/k; 
			sum %= k;
			if (sum + height[i] > h) {
				++ans;
				sum = 0;
			} 
			sum += height[i];
		}
	}
	ans += sum/k; sum %= k;
	if (sum) ++ans;

	printf("%I64d\n", ans);
	return 0;
}