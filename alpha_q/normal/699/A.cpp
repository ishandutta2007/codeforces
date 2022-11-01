#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
const int INF = 2e9 + 50;

int n, a[N];
string s;

int main (int argc, char const *argv[]) {
	cin >> n >> s;
 	for (int i = 0; i < n; ++i) scanf("%d", a + i);
 	
 	int res = INF;
 	for (int i = 0; i < n - 1; ++i) {
 		if (s[i] == 'R' and s[i + 1] == 'L') {
 			res = min(res, (a[i + 1] - a[i]) >> 1);
 		}
 	}
 	
 	if (res == INF) res = -1;
 	printf("%d\n", res);
	return 0;
}