#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
vector<int>E[N_];
int n, C[N_], chk[N_], D[N_], Q[N_], head, tail, v[N_];
int A[N_], par[N_], CC[1<<21], isPow[1<<21];
long long S[N_], R[N_];
char p[N_];
void BFS(int a) {
	int i, x;
	head = tail = 0;
	Q[++tail] = a;
	v[a] = 1;
	D[a] = 1 << A[a];
	while (head < tail) {
		int x = Q[++head];
		for (i = 0; i < E[x].size(); i++) {
			if (v[E[x][i]] || chk[E[x][i]])continue;
			Q[++tail] = E[x][i];
			par[E[x][i]] = x;
			D[E[x][i]] = (D[x] ^ (1 << A[E[x][i]]));
			v[E[x][i]] = 1;
		}
	}
	for (i = 1; i <= tail; i++)v[Q[i]] = C[Q[i]] = 0;
	for (i = tail; i >= 1; i--) {
		C[Q[i]]++;
		if(i!=1) C[par[Q[i]]] += C[Q[i]];
	}
}
int get_mid() {
	int i, Mn = 1e9, x= 0;
	for (i = 1; i <= tail; i++) {
		if (C[Q[i]] * 2 >= tail && C[Q[i]] < Mn)Mn = C[Q[i]], x = Q[i];
	}
	return x;
}
void BFS2(int a, int ss) {
	int i, x;
	head = tail = 0;
	Q[++tail] = a;
	v[a] = 1;
	while (head < tail) {
		int x = Q[++head];
		for (i = 0; i < E[x].size(); i++) {
			if (v[E[x][i]] || chk[E[x][i]])continue;
			Q[++tail] = E[x][i];
			par[E[x][i]] = x;
			v[E[x][i]] = 1;
		}
	}
	for (i = 1; i <= tail; i++)v[Q[i]] = 0;
	for (i = tail; i >= 1; i--) {
		
		if (i != 1) {
			S[par[Q[i]]] += S[Q[i]];
			R[Q[i]] += S[Q[i]];
		}
		else {
			R[Q[i]] += (S[Q[i]] + ss) / 2;
		}
		S[Q[i]] = 0;
	}
}
void Do(int a) {
	BFS(a);
	if (tail == 1) {
		return;
	}
	int m = get_mid();
	chk[m] = 1;
	int i, j, k;
	for (i = 0; i < E[m].size(); i++) {
		if (chk[E[m][i]])continue;
		Do(E[m][i]);
	}
	vector<int>T;
	int ss = 0;
	for (i = 0; i < E[m].size(); i++) {
		int x = E[m][i];
		if (chk[x])continue;
		BFS(x);
		for (j = 1; j <= tail; j++) {
			int a = (D[Q[j]] ^ (1<<A[m]));
			int c = 0;
			if (!a) c++,ss++;
			c += CC[a];
			for (k = 0; k < 20; k++) {
				if (a == (1 << k))c++,ss++;
				c += CC[a ^ (1 << k)];
			}
			S[Q[j]] += c;
		}
		for (j = 1; j <= tail; j++) {
			CC[D[Q[j]]]++;
			T.push_back(D[Q[j]]);
		}
	}
	for (i = 0; i < T.size(); i++)CC[T[i]]--;
	T.clear();
	for (i = E[m].size()-1; i >= 0; i--) {
		int x = E[m][i];
		if (chk[x])continue;
		BFS(x);
		for (j = 1; j <= tail; j++) {
			int a = (D[Q[j]] ^ (1 << A[m]));
			int c = 0;
			c += CC[a];
			for (k = 0; k < 20; k++) {
				c += CC[a ^ (1 << k)];
			}
			S[Q[j]] += c;
		}
		for (j = 1; j <= tail; j++) {
			CC[D[Q[j]]]++;
			T.push_back(D[Q[j]]);
		}
	}
	for (i = 0; i < T.size(); i++)CC[T[i]]--;
	T.clear();
	chk[m] = 0;
	BFS2(m, ss);
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		A[i + 1] = p[i] - 'a';
	}
	Do(1);
	for (i = 1; i <= n; i++)printf("%lld ", R[i] + 1);
}