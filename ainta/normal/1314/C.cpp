#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, cnt, L;
long long K;
char p[1010], q[1010];
struct Trie {
	int Ch[26];
	int c, s;
}T[1010000];
void Put(int nd, char *key) {
	if(nd!=1)T[nd].c++;
	if (!(*key)) return;
	int t = (*key) - 'a';
	if (!T[nd].Ch[t]) {
		T[nd].Ch[t] = ++cnt;
	}
	Put(T[nd].Ch[t], key + 1);
}
void Find(int c) {
	int nd = 1;
	int i;
	L = 0;
	while (1) {
		if (T[nd].c >= c) {
			return;
		}
		c -= T[nd].c;
		for (i = 0; i < 26; i++) {
			int x = T[nd].Ch[i];
			if (!x)continue;
			if (T[x].s >= c) {
				q[L++] = i + 'a';
				nd = x;
				break;
			}
			c -= T[x].s;
		}
	}
}
void DFS(int a) {
	T[a].s = T[a].c;
	for (int i = 0; i < 26; i++) {
		int x = T[a].Ch[i];
		if (x) {
			DFS(x);
			T[a].s += T[x].s;
		}
	}
}
int Mn[1010];
long long D[1010][1010], S[1010][1010], INF = 2e18;
long long Calc() {
	int i, j;
	Mn[n] = -1;
	for (i = 0; i < n; i++) {
		Mn[i] = -1;
		for (j = i; j < i + L && j < n; j++) {
			if (p[j] != q[j - i]) {
				if (p[j] > q[j - i]) {
					Mn[i] = j - i + 1;
				}
				break;
			}
		}
		if (j == i + L)Mn[i] = L;
	}
	for (i = 0; i <= m; i++)for (j = 0; j <= n; j++)S[i][j]=D[i][j] = 0;
	D[0][0] = 1;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (j) {
				S[i][j] = min(S[i][j] + S[i][j - 1],INF);
			}
			if (i)D[i][j] = S[i][j];
			if (Mn[j] != -1) {
				S[i+1][j + Mn[j]] = min(S[i+1][j + Mn[j]] + D[i][j], INF);
			}
		}
	}
	return D[m][n];
}
int main() {
	int i, j;
	scanf("%d%d%lld", &n, &m, &K);
	++cnt;
	scanf("%s", p);
	for (i = 0; i < n; i++) {
		Put(1, p + i);
	}
	DFS(1);
	int b = 1, e = n * (n + 1) / 2, r= 0;
	
	while (b <= e) {
		int mid = (b + e) >> 1;
		Find(mid);
		q[L] = 0;
		if (Calc() >= K) {
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	Find(r);
	q[L] = 0;
	printf("%s\n", q);
}