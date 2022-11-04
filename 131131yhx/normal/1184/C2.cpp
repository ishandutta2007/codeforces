#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

struct node {
	int tim, l, r, o;
	node() {}
	node(int _1, int _2, int _3, int _4) {tim = _1, l = _2, r = _3, o = _4;}
	bool operator < (const node& X) const {return tim < X.tim;}
};

int n, r;

node S[1200010];

int Mx[5000010], Tg[5000010];

void pd(int x) {
	if(Tg[x]) Tg[x * 2] += Tg[x], Tg[x * 2 + 1] += Tg[x], Mx[x * 2] += Tg[x], Mx[x * 2 + 1] += Tg[x], Tg[x] = 0;
}

void add(int x, int L, int R, int l, int r, int o) {
	if(L == l && R == r) {
		Tg[x] += o;
		Mx[x] += o;
		return;
	}
	pd(x);
	int md = (L + R) / 2;
	if(l <= md) add(x * 2, L, md, l, min(md, r), o);
	if(r > md) add(x * 2 + 1, md + 1, R, max(md + 1, l), r, o);
	Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
}

int main() {
	scanf("%d%d", &n, &r);
	int cnt = 0;
	vector <int> S1(0), S2(0);
	for(int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int A = a + b, B = a - b;
		S[++cnt] = node(A - r, B - r, B + r, 1);
		S[++cnt] = node(A + r + 1, B - r, B + r, -1);
		S1.push_back(B - r), S1.push_back(B + r);
	}
	sort(S1.begin(), S1.end()), S1.resize(unique(S1.begin(), S1.end()) - S1.begin());
	sort(S + 1, S + cnt + 1);
	int ans = 0;
	for(int i = 1, nxt; i <= cnt; i = nxt + 1) {
		for(nxt = i; nxt + 1 <= cnt && S[nxt + 1].tim == S[i].tim; nxt++);
		for(int j = i; j <= nxt; j++) {
			int l = S[j].l, r = S[j].r, o = S[j].o;
			l = lower_bound(S1.begin(), S1.end(), l) - S1.begin() + 1;
			r = lower_bound(S1.begin(), S1.end(), r) - S1.begin() + 1;
			add(1, 1, S1.size(), l, r, o);
		}
		ans = max(ans, Mx[1]);
	}
	printf("%d\n", ans);
	return 0;
}