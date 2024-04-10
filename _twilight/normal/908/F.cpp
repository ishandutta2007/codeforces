#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const signed inf = (signed) (~0u >> 1);
const int N = 3e5 + 5;

int n;
char str[5];
int p[N], col[N];

inline void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%s", p + i, str);
		if (str[0] == 'R')
			col[i] = 1;
		if (str[0] == 'G')
			col[i] = 2;
	}
}

ll ans = 0;
void calc(int l, int r) {
	ll delta = (p[r] - p[l]) * 3ll;
	int reduce1 = 0, reduce2 = 0;
	int lst_b = p[l], lst_r = p[l];
	for (int i = l + 1; i < r; i++) {
		if (col[i] == 1) {
			reduce2 = max(reduce2, p[i] - lst_r);
			lst_r = p[i];
		} else {
			reduce1 = max(reduce1, p[i] - lst_b);
			lst_b = p[i];
		}
	}
	reduce1 = max(reduce1, p[r] - lst_b);
	reduce2 = max(reduce2, p[r] - lst_r);
	delta -= reduce1;
	delta -= reduce2;
	delta = min(delta, (ll) (p[r] - p[l]) << 1);
	ans += delta;
}

inline void solve() {
	int lst = -1;
	int first_b = -1, first_r = -1;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 2) {
			if (lst == -1) {
				if (first_b != -1)
					ans += p[i] - first_b;
				if (first_r != -1)
					ans += p[i] - first_r;
			} else {
				calc(lst, i);
			}
			lst = i;
		} else {
			if (first_b == -1 && !col[i])
				first_b = p[i];
			if (first_r == -1 && col[i] == 1)
				first_r = p[i];
		}
	}
	if (lst == -1) {
		int bmi = inf, bmx = -1;
		int rmi = inf, rmx = -1;
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0) {
				bmi = min(bmi, p[i]);
				bmx = max(bmx, p[i]);
			} else {
				rmi = min(rmi, p[i]);
				rmx = max(rmx, p[i]);
			}
		}
		if (~bmx)
			ans += bmx - bmi;	
		if (~rmx) 
			ans += rmx - rmi;
	} else {
		int last_b = -1, last_r = -1;
		for (int i = n; i; i--) {
			if (col[i] == 2) {
				if (~last_b)
					ans += last_b - p[i];
				if (~last_r)
					ans += last_r - p[i];	
				break;
			}
			
			if (last_b == -1 && col[i] == 0)
				last_b = p[i];
			if (last_r == -1 && col[i] == 1)
				last_r = p[i];
		}
	}
	printf("%I64d", ans);
} 

int main() {
	init();
	solve();
	return 0;
}