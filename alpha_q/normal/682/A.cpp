/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

long long n, m, ans = 0;

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	scanf("%I64d %I64d", &n, &m);
	if (m < n) swap(m, n);

	for (int i = 1; i <= n; ++i) ans += (m + (i % 5))/5;
	printf("%I64d\n", ans);
    return 0;
}