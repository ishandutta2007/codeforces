#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 2e5;

int a[MAXN];
int go[MAXN];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	//ios_base::sync_with_stdio(false);
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (cnt < n && a[i] == a[cnt])
			cnt++;
		go[i] = cnt;
	}
	
	for (int i = 0; i < m; i++) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x); l--, r--;
		if (a[l] != x)
			cout << l + 1 << "\n";
		else if (go[l] <= r)
			cout << go[l] + 1 << "\n";
		else
			cout << -1 << "\n";
	}
	
	//f;kgj sgsgj4 3kg 3h 34ok hnjm4o5nh 5koh nm45l
	
	return 0;
}