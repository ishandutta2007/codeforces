#include <bits/stdc++.h>

using namespace std;

pair <int, int> rows[5000];
pair <int, int> cols[5000];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int q, r, c, t;
    int time = 0;
    while (k--) {
	scanf("%d", &q);
	if (q == 1) {
	    scanf("%d%d", &r, &t);
	    r--;
	    rows[r].first = t;
	    rows[r].second = ++time;
	} else {
	    scanf("%d%d", &c, &t);
	    c--;
	    cols[c].first = t;
	    cols[c].second = ++time;
	}
    }
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (rows[i].second > cols[j].second)
		printf("%d ", rows[i].first);
	    else
		printf("%d ", cols[j].first);
	}
	puts("");
    }
}