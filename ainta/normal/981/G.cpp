#include<cstdio>
#include<algorithm>
#include<set>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
#define SZ 264144
int Mod = 998244353;
set<pii>Set[SZ];
int n, Q ,po[SZ];
struct SegTree {
	int S[SZ + SZ];
	int AK[SZ + SZ], BK[SZ + SZ];
	void Spread(int nd, int b, int e, int m) {
		if (AK[nd] || BK[nd]) {
			S[nd * 2] = ((long long)S[nd * 2] * po[AK[nd]] + (long long)(m - b + 1)*BK[nd]) % Mod;
			S[nd * 2 + 1] = ((long long)S[nd * 2 + 1] * po[AK[nd]] + (long long)(e - m)*BK[nd]) % Mod;
			AK[nd * 2] += AK[nd];
			BK[nd * 2] = ((long long)BK[nd * 2] * po[AK[nd]] + BK[nd]) % Mod;
			AK[nd * 2 + 1] += AK[nd];
			BK[nd * 2 + 1] = ((long long)BK[nd * 2 + 1] * po[AK[nd]] + BK[nd]) % Mod;
		}
		AK[nd] = BK[nd] = 0;
	}
	void Add(int nd, int b, int e, int s, int l, int ck) {
		if (b == s&&e == l) {
			if (!ck) {
				BK[nd]++;
				S[nd] = (S[nd] + (e - b + 1)) % Mod;
			}
			else {
				BK[nd] = BK[nd] * 2 % Mod;
				AK[nd]++;
				S[nd] = S[nd] * 2 % Mod;
			}
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd, b, e, m);
		if (s <= m)Add(nd * 2, b, m, s, min(m, l), ck);
		if (l > m)Add(nd * 2 + 1, m + 1, e, max(m + 1, s), l, ck);
		S[nd] = (S[nd * 2] + S[nd * 2 + 1]) % Mod;
	}
	int Sum(int nd, int b, int e, int s, int l) {
		if (b == s&&e == l)return S[nd];
		int m = (b + e) >> 1;
		Spread(nd, b, e, m);
		int r = 0;
		if (s <= m)r += Sum(nd * 2, b, m, s, min(m, l));
		if (l > m)r += Sum(nd * 2 + 1, m + 1, e, max(m + 1, s), l);
		return r%Mod;
	}
}T;
void Put(int x, int b, int e) {
	pii t = { b, e };
	if (Set[x].empty()) {
		T.Add(1, 1, n, b, e, 0);
		Set[x].insert(t);
		return;
	}
	auto it = Set[x].lower_bound(t);
	if (it != Set[x].begin())it--;
	if (it->Y < b)it++;
	if (it == Set[x].end() || it -> X > e) {
		T.Add(1, 1, n, b, e, 0);
		Set[x].insert(t);
		return;
	}
	int bb = min(it->X, b), ee = e;
	int ed = b - 1;
	while (it != Set[x].end()) {
		int bbb = max(it->X, b), eee = min(it->Y, e);
		if (bbb > eee)break;
		if (bbb-1 >= ed+1) {
			T.Add(1, 1, n, ed + 1, bbb - 1, 0);
		}
		ee = max(ee, it->Y);
		T.Add(1, 1, n, bbb, eee, 1);
		ed = eee;
		auto it2 = it;
		it++;
		Set[x].erase(it2);
	}
	if (e >= ed + 1) {
		T.Add(1, 1, n, ed + 1, e, 0);
	}
	Set[x].insert({ bb,ee });
}
int main() {
	int i, ck, b, e, x;
	po[0] = 1;
	for (i = 1; i < SZ; i++)po[i] = po[i - 1] * 2 % Mod;
	scanf("%d%d", &n, &Q);
	while (Q--) {
		scanf("%d%d%d", &ck, &b, &e);
		if (ck == 1) {
			scanf("%d", &x);
			Put(x, b, e);
		}
		else {
			printf("%d\n", T.Sum(1, 1, n, b, e));
		}
	}
}