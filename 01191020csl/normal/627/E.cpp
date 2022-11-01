#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
vector<int> point[3001];
struct node {
	int il, ir;
	int r, cnt, res;
	int ls, rs;
}nd[3001];
int fa[3001], size[3001], id[3001];
int getfa(int x) {
	if (!fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void link(int x, int y) {
	x = getfa(x), y = getfa(y);
	if (x == y) return;
	if (size[x] > size[y]) id[x] = id[y], swap(x, y);
	fa[x] = y, size[y] += size[x];
}
void merge(int p) {
	int np = nd[p].rs;
	nd[nd[p].ls].rs = np, nd[np].ls = nd[p].ls;
	nd[np].il = nd[p].il;
	link(p, np);
}
int debug(int p) {
	while (nd[p].rs) p = nd[p].rs;
	return p;
}
int p[3001];
int cnt = 0;
int main() {
	int r, c, n, k;
	r = read(), c = read(), n = read(), k = read();
	for (int i = 1; i <= n; i++) {
		int x, y;
		x = read(), y = read();
		point[x].push_back(y);
	}
	for (int i = 1; i <= r; i++) sort(point[i].begin(), point[i].end());
	long long ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			p[j] = j, nd[j].ls = j - 1, nd[j].rs = j + 1;
			nd[j].il = nd[j].ir = j;
			fa[j] = 0, size[j] = 1, id[j] = j;
		}
		nd[c].rs = 0;
		for (int j = i; j <= r; j++)
			for (int l : point[j]) ++nd[l].cnt;
		int p = 1;
		long long tmp = 0;
		while (p) {
			if (!nd[p].cnt) merge(p);
			else {
				int q = p;
				nd[p].res = nd[p].cnt;
				while (nd[q].rs && nd[p].res < k) q = nd[q].rs, nd[p].res += nd[q].cnt;
				if (nd[p].res < k) nd[p].r = c + 1;
				else nd[p].r = q;
				if (nd[p].r <= c) tmp += (nd[p].ir-nd[p].il+1)*(c-nd[nd[p].r].ir+1);
			}
			p = nd[p].rs;
		}
		for (int j = r; j >= i; j--) {
			ans += tmp;
			for (int l : point[j]) {
				p = id[getfa(l)];
				--nd[p].cnt;
				int st = p;
				while (nd[st].ls && nd[nd[st].ls].r >= l) st = nd[st].ls;
				while (st && nd[st].il <= l) {//++cnt;
					if (nd[st].r == c + 1) break;
					tmp -= (nd[st].ir-nd[st].il+1)*(c-nd[nd[st].r].ir+1);
					--nd[st].res;
					if (nd[nd[st].r].rs && nd[st].res < k) nd[st].r = nd[nd[st].r].rs, nd[st].res += nd[nd[st].r].cnt;
					if (nd[st].res < k) nd[st].r = c + 1;
					if (nd[st].r <= c) tmp += (nd[st].ir-nd[st].il+1)*(c-nd[nd[st].r].ir+1);
					st = nd[st].rs;
				}
				if (!nd[p].cnt) merge(p), p = nd[p].rs;
			}
		}
	}
	cout << ans << endl;
}