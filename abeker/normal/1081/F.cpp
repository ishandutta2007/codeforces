#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N, T;
int pref[MAXN];

int ask(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	if (res == -1)
		exit(0);
	return res;
}

int main() {
	scanf("%d%d", &N, &T);
	
	if (N == 1) {
		printf("! %d\n", T);
		fflush(stdout);
		return 0;
	}
	
	int k = N % 2, curr = T;
	for (int i = 1; i <= N - k; i++) {
		int lft = 0, rig = 0;
		bool ok = false;
		while (!ok || lft || rig) {
			int nxt = ask(i, i + k);
			if ((curr + nxt) % 2 == (i + k) % 2) {
				lft ^= 1;
				if (lft && !rig) {
					pref[i + k] = (i + k - nxt + T) / 2;
					ok = true;
				}
			}
			else 
				rig ^= 1;
			curr = nxt;
		}
	}
	
	if (k) {
		int it = 0;
		while (1) {
			int nxt = ask(2, N);
			if (!((curr + nxt) % 2)) {
				pref[1] = it ? (T - nxt + 1) / 2 : (nxt + T - N + 1) / 2;
				break;
			}
			curr = nxt;
			it ^= 1;
		}
	}
	
	printf("! ");
	for (int i = 1; i <= N; i++)
		printf("%d", pref[i] - pref[i - 1]);
	puts("");
	fflush(stdout);
	
	return 0;
}