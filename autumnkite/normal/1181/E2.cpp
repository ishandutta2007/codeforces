#include <cstdio>
#include <cctype>
#include <algorithm>
#include <set>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
struct node{
	int l, r, id;
	bool operator < (const node &res) const {
		return l < res.l || (l == res.l && r < res.r) || (l == res.l && r == res.r && id < res.id);
	}
}p[100005][4];
int n;
std :: set<node> s[4];
bool solve(std :: set<node> a[4]){
	int n = a[0].size(), mx[4];
	std :: set<node> :: iterator t[4];
	if (n == 1) return 1;
	for (register int i = 0; i < 4; ++i) t[i] = a[i].begin(), mx[i] = -1e9;
	for (register int i = 1; i < n; ++i)
		for (register int j = 0; j < 4; ++j){
			mx[j] = std :: max(mx[j], t[j] -> r), ++t[j];
			if (t[j] -> l >= mx[j]){
				std :: set<node> b[4];
				for (register int _ = 1; _ <= i; ++_){
					int id = a[j].begin() -> id;
					for (register int k = 0; k < 4; ++k)
						a[k].erase(p[id][k]), b[k].insert(p[id][k]);
				}
				return solve(b) && solve(a);
			}
		}
	return 0;
}
int main(){
	n = read();
	for (register int i = 1, a, b, c, d; i <= n; ++i){
		a = read(), b = read(), c = read(), d = read();
		s[0].insert(p[i][0] = (node){a, c, i}), s[1].insert(p[i][1] = (node){-c, -a, i});
		s[2].insert(p[i][2] = (node){b, d, i}), s[3].insert(p[i][3] = (node){-d, -b, i});
	}
	if (solve(s)) printf("Yes\n"); else printf("No\n");
}