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
int a[1000001], vis[1000001], match[1000001];
vector<int> num[1<<20];
vector<int> edge[1000001];
bool check(int n, int ans) {
	for (int i = 0; i < (1 << ans); i++) num[i].clear();
	for (int i = 1; i <= n * 2; i++) num[a[i]&((1<<ans)-1)].push_back(i);
	for (int i = 0; i < (1 << ans); i++)
		if (num[i].size() & 1) return 0;
	for (int i = 1; i <= n * 2; i++) {
		edge[i].clear();
		edge[i].push_back(match[i]);
	}
	for (int i = 0; i < (1 << ans); i++)
		if (num[i].size())
			for (int j = 1; j < num[i].size(); j++) {
				edge[num[i][0]].push_back(num[i][j]);
				edge[num[i][j]].push_back(num[i][0]);
			}
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	q.push(1), vis[1] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i : edge[u])
			if (!vis[i]) {
				vis[i] = 1;
				q.push(i);
			}
	}
	for (int i = 1; i <= n * 2; i++)
		if (!vis[i]) return 0;
	return 1;
}
int cnt[1<<20], ans[1000001];
int seq[1000001], tot = 1;
vector<int> ins[1000001];
void put(int id, int len) {
	if (id == tot) {
		for (int i = seq[id]; i <= len; i++) write(ans[i]), putchar(' ');
		return;
	}
	for (int i = seq[id]; i < seq[id+1]; i++) {
		write(ans[i]), putchar(' ');
		for (int j : ins[i]) put(j, len);
	}
}
void solve(int n, int k) {
	for (int i = 0; i < (1 << k); i++) cnt[i] = num[i].size();
	for (int i = 1; i <= n * 2; i++) a[i] &= (1 << k) - 1;
	ans[1] = 1, ans[2] = 2;
	vis[1] = vis[2] = 0;
	--cnt[a[1]], --cnt[a[2]];
	int find = 1, p = 2, lins = 2;
	seq[1] = 1;
	while (find < n) {
		if (!cnt[a[ans[p]]]) {
			for (int i = lins; i <= find * 2; i += 2)
				if (cnt[a[ans[i]]]) {
					ins[i].push_back(tot + 1);
					seq[++tot] = find * 2 + 1;
					while (!vis[*(num[a[ans[i]]].end()-1)]) num[a[ans[i]]].pop_back();
					++p;
					ans[p] = *(num[a[ans[i]]].end()-1);
					ans[p+1] = match[ans[p]];
					vis[ans[p]] = vis[ans[p+1]] = 0;
					--cnt[a[ans[p]]], --cnt[a[ans[p+1]]];
					++p;
					lins = i;
					break;
				}
			++find;
			continue;
		}
		while (!vis[*(num[a[ans[p]]].end()-1)]) num[a[ans[p]]].pop_back();
		++p;
		ans[p] = *(num[a[ans[p-1]]].end()-1);
		ans[p+1] = match[ans[p]];
		vis[ans[p]] = vis[ans[p+1]] = 0;
		--cnt[a[ans[p]]], --cnt[a[ans[p+1]]];
		++p;
		++find;
	}
	put(1, n * 2);
	putchar('\n');
}
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) a[2*i-1] = read(), a[2*i] = read();
	for (int i = 1; i <= n; i++) match[2*i-1] = 2*i, match[2*i] = 2*i-1;
	for (int i = 20; i >= 0; i--) 
		if (check(n, i)) {
			write(i), putchar('\n');
			solve(n, i);
			return 0;
		}
}