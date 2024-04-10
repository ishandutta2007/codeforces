#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int head[500001], ver[1000001], nxt[1000001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int t[500001], vis[500001];
vector<int> tmp[500001];
int main() {
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int a, b;
		a = read(), b = read();
		addedge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		t[i] = read();
		tmp[t[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j : tmp[i]) {
			if (vis[j] != i - 1) {
				puts("-1");
				return 0;
			}
			for (int k = head[j]; k; k = nxt[k]) {
				if (t[ver[k]] < i) continue;
				if (vis[ver[k]] != i - 1 && vis[ver[k]] != i) {
					puts("-1");
					return 0;
				}
				vis[ver[k]] = i;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j : tmp[i]) write(j), putchar(' ');
	putchar('\n');
}