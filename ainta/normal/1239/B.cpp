#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, S[601000];
char p[601000];
int main() {
	scanf("%d", &n);
	scanf("%s", p);
	int i, Mn = 0, pv = 0, j;
	for (i = 1; i <= n; i++) {
		S[i] = S[i - 1];
		if (p[i-1] == '(')S[i]++;
		else S[i]--;
		if (Mn > S[i]) {
			Mn = S[i];
			pv = i;
		}
	}
	if (S[n]) {
		printf("0\n1 1\n");
		return 0;
	}
	for (i = 0; i <= n; i++) {
		S[i + n] = S[i];
		p[i + n] = p[i];
	}
	vector<int>U;
	for (i = pv; i <= n + pv; i++) {
		if (S[i] == Mn) {
			U.push_back(i);
		}
	}
	int sz = U.size();
	int res = sz - 1, tb = 0, te = 0;
	for (i = 0; i < sz - 1; i++) {
		if (U[i + 1] - U[i] != 2) {
			vector<int>T;
			for (int j = U[i] + 1; j < U[i + 1]; j++) {
				if (S[j] == Mn + 1)T.push_back(j);
			}
			for (int j = 0; j + 1 < T.size(); j++) {
				int b = T[j], e = T[j + 1];
				int t1 = b, t2 = e - 1, cc = sz-1;
				for (int k = b + 1; k < e; k++) {
					if (S[k] == Mn + 2)cc++;
				}
				if (res < cc) {
					res = cc;
					tb = t1, te = t2;
				}
			}

			if (res < T.size()) {
				res = T.size();
				tb = U[i], te = U[i + 1] - 1;
			}
		}
	}

	/*if (U.size() == 2) {
		int cc = 0;
		for (i = 0; i < n; i++) {
			if (S[i] == Mn + 1) {
				cc++;
			}
		}
		if (res < cc) {
			res = cc;
			tb = pv, te = n + pv - 1;
		}
	}*/

	tb %= n, te %= n;
	tb++, te++;
	printf("%d\n%d %d\n", res,tb,te);
}