#include <bits/stdc++.h>

using namespace std;

int k;
int n, m;
int ans = 0;
char a[160][160];
set <int> t[160];
int res = 0;
int DIG = 0;

void dfs(int r, bool right, int f) {
    if (r == n || DIG == k) 
	return;
    ans++;
    if (right) {
	int cur = f;
	while (1) {
	    if ((t[r].size() == 0 || *t[r].rbegin() < cur + 1) && (t[r + 1].size() == 0 || *t[r + 1].rbegin() < cur + 1)) 
		break;
	    else {
		ans++;
		cur++;
	    }
	}
	DIG += t[r].size();
	dfs(r + 1, 0, cur); 
    } else {
	int cur = f;
	while (1) {
	    if ((t[r].size() == 0 || *t[r].begin() > cur - 1) && (t[r + 1].size() == 0 || *t[r + 1].begin() > cur - 1))
		break;
	    else {
		ans++;
		cur--;
	    }
	}
	DIG += t[r].size();
	dfs(r + 1, 1, cur);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	char c;
	for (int j = 0; j < m; j++) {
	    scanf(" %c", &c);
	    if (c == 'W') {
		k++;
		t[i].insert(j);
	    }
	}
    }
    dfs(0, 1, 0);
    printf("%d\n", ans - 1 * (ans != 0));
}