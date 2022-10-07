#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
long long read(){
    register long long x = 0;
    register char f = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
    return f ? x : -x;
}
#define N 1000005
int n;
long long k, a[N], ans;
struct node{
	int l, r;
	int get_md(int d){
		long long x = (a[l] >> (d + 1) << 1 | 1) << d;
		return std :: lower_bound(a + l, a + r + 1, x) - a - 1;
	}
	int sz(int id, int md){
		return id ? r - md : md - l + 1;
	}
	node son(int id, int md){
		return id ? (node){md + 1, r} : (node){l, md};
	}
};
std :: vector< std :: pair<node, node> > p, tmp;
int main(){
	n = read(), k = read(), a[1] = 0;
	for (register int i = 2; i <= n; ++i)
		a[i] = a[read()], a[i] ^= read();
	std :: sort(a + 1, a + 1 + n);
	p.push_back(std :: make_pair((node){1, n}, (node){1, n}));
	for (register int i = 61; ~i; --i){
		long long Sum = 0;
		for (auto v : p){
			int md1 = v.first.get_md(i), md2 = v.second.get_md(i);
			Sum += 1ll * v.first.sz(0, md1) * v.second.sz(0, md2);
			Sum += 1ll * v.first.sz(1, md1) * v.second.sz(1, md2);
		}
		int w = k > Sum;
		if (w) k -= Sum;
		tmp.clear(), ans = ans << 1 | w;
		for (auto v : p){
			int md1 = v.first.get_md(i), md2 = v.second.get_md(i);
			for (register int j = 0; j < 2; ++j)
				if (v.first.sz(j, md1) && v.second.sz(w ^ j, md2))
					tmp.push_back(std :: make_pair(v.first.son(j, md1), v.second.son(w ^ j, md2)));
		}
		p = tmp;
	}
	printf("%lld\n", ans);
}