#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

int N;
int a[MAXN];
map <int, bool> bio;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	int sol = N + 1;
	bool ok = true;
	for (int i = 0; i < N; i++) {
		map <int, bool> tmp;
		for (int j = N - 1; j >= i; j--) {
			sol = min(sol, j - i + 1);
			if (bio[a[j]] || tmp[a[j]])
				break;
			tmp[a[j]] = true;
		}
		if (bio[a[i]]) {
			ok = false;
			break;
		}
		bio[a[i]] = true;
	}
	
	if (ok)
		sol = 0;
	
	printf("%d\n", sol);
	
	return 0;
}