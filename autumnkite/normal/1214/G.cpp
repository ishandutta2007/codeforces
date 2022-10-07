#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <set>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 2005
int n, m, q, x1, _y1, x2, _y2;
std :: bitset<N> a[N], nw[N], tmp;
std :: set< std :: pair<int, int> > S, ans;
bool check(int i, int j){
	return (a[i] & a[j]) != a[i];
}
void add(std :: pair<int, int> p){
	if (check(p.first, p.second)) ans.insert(p);
}
void del(std :: pair<int, int> p){
	if (check(p.first, p.second)) ans.erase(p);
}
void Erase(std :: pair<int, int> x){
	int nx, i, pr;
	auto it = S.lower_bound(x), tmp = it;
	i = x.second, nx = (++tmp) -> second, pr = (--it) -> second;
	del(std :: make_pair(pr, i)), del(std :: make_pair(i, nx)), add(std :: make_pair(pr, nx));
	S.erase(x);
}
void Insert(std :: pair<int, int> x){
	int nx, i, pr;
	auto it = S.lower_bound(x);
	i=  x.second, nx = it -> second, pr = (--it) -> second;
	add(std :: make_pair(pr, i)), add(std :: make_pair(i, nx)), del(std :: make_pair(pr, nx));
	S.insert(x);
}
int main(){
	n = read(), m = read(), q = read();
	nw[1] = 1;
	for (register int i = 2; i <= m; ++i) nw[i] = nw[i - 1] << 1 | nw[1];
	a[n + 1] = nw[m], S.insert(std :: make_pair(0, 0));
	for (register int i = 1; i <= n; ++i) S.insert(std :: make_pair(0, i));
	S.insert(std :: make_pair(m, n + 1));
	for (register int i = 1; i <= q; ++i){
		int k = read(), l = read(), r = read();
		Erase(std :: make_pair(a[k].count(), k));
		a[k] ^= nw[r - l + 1] << (l - 1);
		Insert(std :: make_pair(a[k].count(), k));
		if (ans.empty()) printf("-1\n");
		else{
			x1 = ans.begin() -> first, x2 = ans.begin() -> second;
			_y1 = ((a[x1] ^ a[x2]) & a[x1])._Find_first(), _y2 = ((a[x1] ^ a[x2]) & a[x2])._Find_first();
			if (x1 > x2) std :: swap(x1, x2);
			if (_y1 > _y2) std :: swap(_y1, _y2);
			printf("%d %d %d %d\n", x1, _y1 + 1, x2, _y2 + 1);
		}
	}
}