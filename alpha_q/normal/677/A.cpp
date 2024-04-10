/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	int n, h, ans = 0;
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if (x <= h) ++ans;
		else ans += 2;
	}	
	printf("%d\n", ans);
	return 0;
}