/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;

	int ar[n+1];

	for(int i = 1; i <= n; i++){
		cin >> ar[i];
	}

	int c[n];
	c[0] = 0;
	c[1] = ar[1];

	for(int i = 2; i <= n; i++){
		c[i] = c[i-1] + ar[i];
	}

	int pos = 1, ans = 0;

	for(int i = 1; i <= n; i++){
		pos = max(pos, i);
		while (pos != n && c[pos+1] - c[i-1] <= m)
			pos++;
		if (c[pos] - c[i-1] > m)
			continue;
		ans = max(ans, pos - i + 1);
	}

	cout << ans;

}