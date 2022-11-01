/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0;
int a[100005];

int main (int argc, char const *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort (a, a + n);

	int now = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= now) a[i] = now, ++now;
	}

	printf("%d\n", now);
    return 0;
}