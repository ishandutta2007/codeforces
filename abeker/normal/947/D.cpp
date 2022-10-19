#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct str {
	char s[MAXN];
	int sum[MAXN];
	int lst[MAXN];
	
	void load() {
		memset(sum, 0, sizeof sum);
		memset(lst, 0, sizeof lst);
		scanf("%s", s + 1);
		int N = strlen(s + 1);
		for (int i = 1; i <= N; i++) {
			int tmp = s[i] != 'A';
			sum[i] = sum[i - 1] + tmp;
			lst[i] = tmp ? i : lst[i - 1];
		}
	}
	
	int get(int lo, int hi) {
		return sum[hi] - sum[lo - 1];
	}
	
	int suff(int lo, int hi) {
		return hi - max(lst[hi], lo - 1);
	}
};

str S, T;

int query(int a, int b, int c, int d) {
	int sum_s = S.get(a, b);
	int sum_t = T.get(c, d);
	int suff_s = S.suff(a, b);
	int suff_t = T.suff(c, d);
	
	if (sum_s > sum_t || (sum_s - sum_t) % 2 || suff_s < suff_t)
		return 0;
	
	if (sum_s == sum_t)
		return !((suff_s - suff_t) % 3);
	
	return suff_s > suff_t || sum_s;
}

int main() {
	S.load();
	T.load();
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d", query(a, b, c, d));
	}
	puts("");
	
	return 0;
}