#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 6;

#define ll long long

int n, m;
int cR[N];
boolean rL[N];
int L[N], R[N];
int _L[N], _R[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m + 1; i++) {
		L[i] = n + 1, R[i] = 0;
	}
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		L[x] = min(L[x], i);
		R[x] = max(R[x], i);
	}
	for (int i = 1; i <= m; i++) {
		_L[i] = L[i];
		_R[i] = R[i];
	}
	rL[m + 1] = true, cR[m + 1] = 1;
	for (int i = m; i; i--) {
		L[i] = min(L[i], L[i + 1]);
		rL[i] = true; 
		if (!rL[i + 1]) {
			rL[i] = false;
		} else {
			if (R[i] >= L[i + 1]) {
				rL[i] = false;
			}
		}
		cR[i] = cR[i + 1] + rL[i];
	}
	for (int i = 1; i <= m + 1; i++)
		R[i] = max(R[i], R[i - 1]);
	
	int r = 1;
	ll ans = 0;
	for (int l = 0; l < m; l++) {
		if (l && R[l - 1] >= _L[l]) {
			break;
		}
		while (r <= m && L[r] <= R[l])
			r++;
		ans += cR[max(l + 2, r)];
	}
	cout << ans << '\n';
	return 0;
}