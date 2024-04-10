#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1010000
#define SZ 1048576
using namespace std;

int n, Rank[N_], SA[N_], ord[N_], C[N_], ord1[N_], ord2[N_], LCP[N_][21], B[N_], m, L, MM[SZ], Res[201000][2], IT[SZ+SZ];
char p[N_];
int BE[201000];
struct AA {
	int a, b;
}w[N_];
struct UU {
	int b, e, s, l, num, len;
	bool operator<(const UU &p)const {
		return s < p.s;
	}
}U[N_];
int Get(int b, int e) {
	if (b > e)swap(b, e);
	int l = e - b;
	int t = MM[l];
	return min(LCP[b][t], LCP[e - (1 << t)][t]);
}
void Suffix_Array(int n) {
	int i, L = 1, j;
	for (i = 0; i < n; i++) {
		w[i].a = p[i];
		w[i].b = p[i + 1];
	}
	int M = max(n, 200);
	while (1) {
		for (i = 0; i <= M; i++) C[i] = 0;
		for (i = 0; i < n; i++)C[w[i].b]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = 0; i < n; i++)ord1[--C[w[i].b]] = i;
		for (i = 0; i <= M; i++) C[i] = 0;
		for (i = 0; i < n; i++)C[w[i].a]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = n - 1; i >= 0; i--)ord2[--C[w[ord1[i]].a]] = ord1[i];
		int cnt = 0;
		for (i = 0; i < n; i++) {
			if (i == 0 || w[ord2[i]].a != w[ord2[i - 1]].a || w[ord2[i]].b != w[ord2[i - 1]].b) {
				cnt++;
			}
			Rank[ord2[i]] = cnt;
		}
		if (cnt == n)break;
		L <<= 1;
		for (i = 0; i < n; i++) {
			w[i].a = Rank[i];
			if (i + L >= n)w[i].b = 0;
			else w[i].b = Rank[i + L];
		}
	}
	for (i = 0; i < n; i++)SA[Rank[i]] = i;
	int t = 0;
	for (i = 0; i < n; i++) {
		int x = Rank[i];
		if (t)t--;
		if (x == n)continue;
		int y = SA[x + 1];
		while (p[i + t] == p[y + t])t++;
		LCP[x][0] = t;
	}
	for (i = 0; i < 20; i++) {
		for (j = 1; j <= (n-(1<<i)); j++) {
			LCP[j][i + 1] = min(LCP[j][i], LCP[j + (1 << i)][i]);
		}
	}
}
struct Query {
	int b, e;
}Q[201000];
int Len[201000];
int Calc(int a, int l) {
	int b = a + 1, e = L, r = L+1, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Get(a, mid) <= l) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	return r;
}
int Calc2(int a, int l) {
	int b = a + 1, e = L, r = a, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Get(a, mid) >= l) {
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	return r;
}

void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = min(IT[a * 2], IT[a * 2 + 1]);
	}
}

int ppv;

int Min(int b, int e) {
	b += SZ, e += SZ;
	int r = 2e9, pv = 0;
	while (b <= e) {
		if (r > IT[b])r = IT[b], pv = b;
		if (r > IT[e])r = IT[e], pv = e;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	while (pv < SZ) {
		pv *= 2;
		if (IT[pv] != r)pv++;
	}
	pv -= SZ;
	ppv = pv;
	return r;
}

int main() {
	int i, j, pv = 0;
	for (i = 1; i < SZ + SZ; i++)IT[i] = 1e9;
	for (i = 1; i < SZ; i++) {
		while ((1 << (pv + 1)) <= i)pv++;
		MM[i] = pv;
	}
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	L = n;
	p[L] = 0;
	L++;
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		Res[i][0] = 0;
		Res[i][1] = -1;
		scanf("%d%d", &Q[i].b, &Q[i].e);
		Q[i].b--, Q[i].e--;
		BE[i] = L;
		scanf("%s", p + BE[i]);
		for (j = L; p[j]; j++);
		Len[i] = j - BE[i];
		L = j;
		p[L] = 0;
		L++;
	}
	Suffix_Array(L);
	int cnt = 0;
	for (i = 1; i <= m; i++) {
		int pv = BE[i], l = Len[i];
		int b = Q[i].b, e = Q[i].e;
		for (j = l; j >= 0; j--) {
			int t = Calc(Rank[pv], j);
			int t2 = Calc2(Rank[pv], j);
			if (t == L + 1 || t>t2)continue;
			if (b > e - j)continue;
			U[cnt++] = { b, e - j, t, t2, i, j+1 };
		}
	}
	sort(U, U + cnt);
	pv = L;
	for (i = cnt - 1; i >= 0; i--) {
		while (U[i].s <= pv) {
			Put(SA[pv], pv);
			pv--;
		}
		if (Min(U[i].b, U[i].e) > U[i].l)continue;

		int x = U[i].num;

		if (Res[x][1] - Res[x][0] + 1 < U[i].len) {
			Res[x][0] = ppv;
			Res[x][1] = ppv + U[i].len - 1;
		}
	}

	for (i = 1; i <= m; i++) {
		if (Res[i][1] == -1)puts("-1");
		else {
			for (j = Res[i][0]; j <= Res[i][1]; j++)printf("%c", p[j]);
			printf("\n");
		}
	}

	return 0;
}