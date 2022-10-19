#include <bits/stdc++.h>
using namespace std;

int N;

int query(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

void finish(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int diff(int pos) {
	return query((pos - 1 + N / 2) % N + 1) - query(pos);
}

int sgn(int x) {
	return x > 0;
}

int main() {
	scanf("%d", &N);
	
	if ((N / 2) % 2)
		finish(-1);
	
	int lo = 1, hi = N / 2 + 1;
	int l = diff(1);
	int r = -l;
	
	if (!l)
		finish(1);
		
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int tmp = diff(mid);
		if (!tmp)
			finish(mid);
		if (sgn(l) ^ sgn(tmp)) {
			hi = mid;
			r = tmp;
		}
		else {
			lo = mid;
			l = tmp;
		}
	}

	return 0;
}