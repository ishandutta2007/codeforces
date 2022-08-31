#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define SZ 524288
using namespace std;
int n;
int w[501000], ori[501000];
long long S[501000];
struct Tree {
	long long Mn[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, long long x) {
		Mn[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, long long x) {
		if (b == s&&e == l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, min(m, l), x);
		if (l>m)Add(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	bool OK() {
		return Mn[1] >= 0;
	}
}T;
void Do(int a) {
	w[a]++;
	T.Add(1, 1, n, a, n, -1);
	if (w[a] < a)T.Add(1, 1, n, w[a], a - 1, 1);
}
int main() {
	int i, j;
	scanf("%d", &n);
	n++;
	long long s = 0;
	for (i = 1; i < n; i++) {
		scanf("%d", &w[i]);
		s += w[i];
	}
	sort(w + 1, w + n);
	reverse(w + 1, w + n);
	for (i = 1; i <= n; i++)S[i] = S[i - 1] + w[i];
	for (i = n; i >= 1; i--) {
		long long t = 1ll * i*(i - 1) - S[i];
		int bb = 1, ee = n, pv = 0;
		while (bb <= ee) {
			int mid = (bb + ee) >> 1;
			if (w[mid] >= i)pv = mid, bb = mid + 1;
			else ee = mid - 1;
		}
		if (pv >= i + 1) {
			t += 1ll * (pv - i) * i;
		}
		t += S[n] - S[max(i, pv)];
		T.Add(1, 1, n, i, i, t);
	}
	for (i = 1; i <= n; i++)ori[i] = w[i];
	ori[0] = n - 1;
	vector<int>res;
	if (T.OK() && s % 2 == 0)res.push_back(0);
	for (i = n; i >= 1; i--) {
		for (j = ori[i]; j < ori[i - 1]; j++) {
			Do(i);
			if (T.OK() && (s + w[i]) % 2 == 0)res.push_back(w[i]);
		}
	}
	if (res.empty())puts("-1");
	else {
		for (auto &x : res)printf("%d ", x);
	}
}