#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

#define pii pair<int, int>

int n, S;
int a[N], p[N], q[N];
vector<vector<int>> cir;

int uf[N];
int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}
void adjust() {
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}
	pii *b = new pii[(n + 1)];
	for (int i = 1; i <= n; i++)
		b[i] = pii(a[i], i);
	sort(b + 1, b + n + 1);
	for (int i = 1, j = 1; i <= n; i++, i = j) {
		while (j <= n && b[i].first == b[j].first)
			j++;
		for (int k = i, x; k < j; k++) {
			x = b[k].second;
			if (x >= i && x < j) {
				q[x] = x;
			}
		}
		for (int k = i, cur = i; k < j; k++) {
			if (!q[k]) {
				while (cur < j && q[b[cur].second] == b[cur].second)
					cur++;
				q[k] = b[cur++].second;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		p[q[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		uf[find(i)] = find(p[i]);
	}
	for (int i = 1, j = 1, ls; i <= n; i = j) {
		while (j <= n && b[i].first == b[j].first)
			j++;
		for (ls = i; ls < j && q[ls] == ls; ls++);
		for (int k = ls + 1; k < j; k++) {
			if (q[k] != k && find(q[k]) != find(q[ls])) {
				uf[find(q[k])] = find(ls);
				uf[find(q[ls])] = find(k);
				swap(p[q[ls]], p[q[k]]);
				swap(q[ls], q[k]);
				ls = k;
			}
		}
	}
}

boolean vis[N];
int find_circle(int x) {
	if (p[x] == x) {
		return 0;
	}
	cir.push_back(vector<int>());
	do {
		vis[x] = true;
		cir.back().push_back(x);
		x = p[x];
	} while (!vis[x]);
	return cir.back().size();
}

int main() {
	scanf("%d%d", &n, &S);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	adjust();
	int t = 0, m = 0;
	for (int i = 1, x; i <= n; i++) {
		if (!vis[i]) {
			x = find_circle(i);
			t += x;
			m += (x != 0);
		}
	}
	if (t > S) {
		puts("-1");
		return 0;
	}	
	if (m <= 2 || t + 2 >= S) {
		printf("%d\n", m);
		for (int i = 0; i < m; i++) {
			printf("%d\n", (signed) cir[i].size());
			for (auto& e : cir[i]) {
				printf("%d ", e);
			}
			putchar('\n');
		}
	} else {
		int c = min(m, S - t);
		printf("%d\n", 2 + m - c);
		int sum = 0;
		for (int i = 0; i < c; i++)
			sum += cir[i].size();
		printf("%d\n", sum);
		for (int i = 0; i < c; i++) {
			for (auto& e : cir[i]) {
				printf("%d ", e);
			}
		}
		putchar('\n');
		printf("%d\n%d", c, cir[0][0]);
		for (int i = c - 1; i; i--)
			printf(" %d", cir[i][0]);
		putchar('\n');
		for (int i = c; i < m; i++) {
			printf("%d\n", (signed) cir[i].size());
			for (auto& e : cir[i]) {
				printf("%d ", e);
			}
			putchar('\n');
		}
	}
	return 0;
}