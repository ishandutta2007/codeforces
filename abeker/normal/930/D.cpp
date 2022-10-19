#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define x first
#define y second

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N;
pii p[MAXN];
int pref_mn[4 * MAXN], pref_mx[4 * MAXN];
int suff_mn[4 * MAXN], suff_mx[4 * MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].x += MAXN;
		p[i].y += MAXN;
	}
}

void mn(int &a, int b) {
	a = min(a, b);
}

void mx(int &a, int b) {
	a = max(a, b);
}

int calc(int a, int b, int c) {
	return b < c ? (c + a % 2) / 2 - (b + a % 2) / 2 : 0;
}

ll solve() {
	for (int i = 0; i < N; i++) 
		p[i] = {p[i].x + p[i].y, p[i].x - p[i].y + 2 * MAXN};
	
	ll sol = 0;
	for (int k = 0; k < 2; k++) {
		memset(pref_mn, INF, sizeof pref_mn);
		memset(suff_mn, INF, sizeof suff_mn);
		memset(pref_mx, 0, sizeof pref_mx);
		memset(suff_mx, 0, sizeof suff_mx);
		
		for (int i = 0; i < N; i++) 
			if ((p[i].x + k) % 2) {
				mn(pref_mn[p[i].x], p[i].y);
				mx(pref_mx[p[i].x], p[i].y);
				mn(suff_mn[p[i].x], p[i].y);
				mx(suff_mx[p[i].x], p[i].y);
			}
		
		for (int i = 1; i < 4 * MAXN; i++) {
			mn(pref_mn[i], pref_mn[i - 1]);
			mx(pref_mx[i], pref_mx[i - 1]);
		}
		
		for (int i = 4 * MAXN - 2; i >= 0; i--) {
			mn(suff_mn[i], suff_mn[i + 1]);
			mx(suff_mx[i], suff_mx[i + 1]);
		}
		
		for (int i = 1; i < 4 * MAXN - 1; i++) 
			if (!((i + k) % 2))
				sol += calc(i, max(pref_mn[i - 1], suff_mn[i + 1]), min(pref_mx[i - 1], suff_mx[i + 1]) - 1);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}