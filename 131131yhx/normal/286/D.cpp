#include <bits/stdc++.h>
#define M 500010
#define Inf 1000000007

using namespace std;

int K[M], L[M], R[M], T[M], F[M], Mn[M], tmpL[M], tmpR[M], tmpT[M], Q[M], n, m, cnt = 0;

long long Ls1[M], Ls2[M];

bool cmpL(int x, int y) {return L[x] < L[y];}
bool cmpR(int x, int y) {return R[x] < R[y];}
bool cmpT(int x, int y) {return T[x] < T[y];}
int getf(int x) {return F[x] == x ? x : F[x] = getf(F[x]);}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &L[i], &R[i], &T[i]), tmpL[i] = tmpR[i] = tmpT[i] = i, K[i * 2 - 1] = L[i], K[i * 2] = R[i];
	sort(K + 1, K + m * 2 + 1);
	cnt = unique(K + 1, K + m * 2 + 1) - K - 1;
	sort(tmpL + 1, tmpL + m + 1, cmpL);
	sort(tmpR + 1, tmpR + m + 1, cmpR);
	sort(tmpT + 1, tmpT + m + 1, cmpT);
	for(int i = 1, nw = 1; i <= m; i++) {
		while(K[nw] != L[tmpL[i]]) nw++;
		L[tmpL[i]] = nw;
	}
	for(int i = 1, nw = 1; i <= m; i++) {
		while(K[nw] != R[tmpR[i]]) nw++;
		R[tmpR[i]] = nw;
	}
	for(int i = 1; i <= cnt; i++) F[i] = i;
	memset(Mn, 127, sizeof Mn);
	for(int i = 1; i <= m; i++)
		for(int s = tmpT[i], j = getf(L[s]); j < R[s]; j = getf(j))
			Mn[j] = T[s], F[j] = j + 1;
	for(int i = 1; i <= n; i++) scanf("%d", &Q[i]);
	for(int i = 1; i < cnt; i++) {
		int l = lower_bound(Q + 1, Q + n + 1, Mn[i] - K[i + 1]) - Q;
		int r = lower_bound(Q + 1, Q + n + 1, Mn[i] - K[i]) - Q;
		Ls1[l] += Q[l] - (Mn[i] - K[i + 1]), Ls2[l]++;
		Ls1[r] += Mn[i] - K[i] - Q[r], Ls2[r]--;
	}
	long long ans = 0, nw = 0;
	for(int i = 1; i <= n; i++)
		ans += nw * (Q[i] - Q[i - 1]) + Ls1[i], printf("%lld\n", ans), nw += Ls2[i];
	return 0;
}