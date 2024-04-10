#include <bits/stdc++.h>

using namespace std;

const long long M = 100005;

struct data {long long l, r, id;} Q[M];

long long pref[M], temp, n, m, k, i, s, t, S, T, A[M], B[30 * M], sq, Ret[M];

bool SqDec (data A, data B) {
	if (A.l/sq == B.l/sq) return A.r > B.r;
	return A.l/sq < B.l/sq;
}

void Add (long long pos) {
	temp += B[pref[pos] ^ k];
	B[pref[pos]]++;
}

void Remove (long long pos) {
	B[pref[pos]]--;
	temp -= B[pref[pos] ^ k];
}

int main () {
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	sq = floor(sqrt(n)), B[0] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%I64d", A + i);
		pref[i] = i == 1 ? A[i] : pref[i - 1] ^ A[i];
	}
	for (i = 0; i < m; i++) {
		scanf("%I64d %I64d", &Q[i].l, &Q[i].r);
		Q[i].id = i;
	}
	sort (Q, Q + m, SqDec);
	s = t = 0; for (i = 0; i < m; i++) {
		S = Q[i].l - 1, T = Q[i].r;
		while (s < S) Remove(s++);
		while (s > S) Add(--s);
		while (t > T) Remove(t--);
		while (t < T) Add(++t);
		Ret[Q[i].id] = temp;
	}
	for (i = 0; i < m; i++) printf("%I64d\n", Ret[i]);
	return 0;		
}