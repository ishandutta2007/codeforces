#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], fr[N];
long long f[N], pp[N];
bool blk[N];
char s[10], ans[N];
inline void Print() {
	ans[n] = '\n';
	for (int i = 1; i <= n; i++) {
		putchar(a[i] + '0');
		putchar(ans[i]);
	}
	exit(0);
}
inline void Solve(int l, int r) {
	for (int j = l; j < r; j++) ans[j] = '*';
	long long prd = 1;
	pp[l - 1] = 1;
	for (int i = l; i <= r; i++) {
		prd *= a[i];
		pp[i] = prd;
		if (prd > 1e17) {
			return;
		}
	}
	vector<int> vp;
	f[l - 1] = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] != 1) {
			vp.push_back(i - 1);
			f[i] = -1;
			for (int j : vp) {
				if (f[i] < f[j] + pp[i] / pp[j]) {
					f[i] = f[j] + pp[i] / pp[j];
					fr[i] = j;
				}
			}
			assert(f[i] > -1);
		} else {
			f[i] = f[i - 1] + 1;
			fr[i] = i - 1;
		}
	}
	for (int i = r; i >= l; i = fr[i]) {
		ans[i] = '+';
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf(" %s", s);
	bool fmul = 0, fadd = 0, fmns = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] == '*') fmul = 1;
		else if (s[i] == '+') fadd = 1;
		else fmns = 1;
	}
	if (!fmul) {
		if (fadd) for (int i = 1; i < n; i++) ans[i] = '+';
		else for (int i = 1; i < n; i++) ans[i] = '-';
		Print();
	}
	if (!fadd) {
		if (!fmns) {
			for (int i = 1; i < n; i++) ans[i] = '*';
		} else {
			int pos = n + 1;
			for (int i = 1; i <= n; i++) if (a[i] == 0) {
				pos = i;
				break;
			}
			for (int i = 1; i < pos - 1; i++) ans[i] = '*';
			ans[pos - 1] = '-';
			for (int i = pos; i < n; i++) ans[i] = '*';
		}
		Print();
	}
	for (int i = 0; i <= n + 1; i++) if (a[i] == 0) {
		blk[i] = 1;
		for (int j = i - 1; j >= 1 && a[j] == 1; j--) blk[j] = 1;
		for (int j = i + 1; j <= n && a[j] == 1; j++) blk[j] = 1;
	}
	for (int i = 1; i < n; i++) if (blk[i] || blk[i + 1]) ans[i] = '+';
	for (int i = 1, lst = 1; i <= n + 1; i++) {
		if (blk[i]) {
			if (lst <= i - 1) {
				Solve(lst, i - 1);
			}
			lst = i + 1;
		}
	}
	Print();
	return 0;
}