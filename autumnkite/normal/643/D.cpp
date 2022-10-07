#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <set>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, Q, a[N];
long long b[N], c[N], d[N], e[N], f[N];
std :: multiset<long long> Son[N], S;
int main(){
	n = read(), Q = read();
	for (register int i = 1; i <= n; ++i)
		b[i] = read(), d[i] = 1;
	for (register int i = 1; i <= n; ++i)
		a[i] = read(), ++d[i], ++d[a[i]];
	for (register int i = 1; i <= n; ++i)
		e[i] = b[i] / d[i], c[i] = b[i] % d[i] + e[i];
	for (register int i = 1; i <= n; ++i)
		c[i] += e[a[i]], c[a[i]] += e[i];
	for (register int i = 1; i <= n; ++i)
		f[i] = c[i] - e[a[i]], Son[a[i]].insert(f[i]);
	for (register int i = 1; i <= n; ++i)
		if (Son[i].size()) S.insert(*Son[i].begin() + e[i]), S.insert(*(--Son[i].end()) + e[i]);
	while (Q--){
		int opt = read();
		if (opt == 1){
			int u = read(), v = read();
			if (a[u] == v) continue;
			S.erase(S.find(*Son[a[u]].begin() + e[a[u]])), S.erase(S.find(*(--Son[a[u]].end()) + e[a[u]]));
			Son[a[u]].erase(Son[a[u]].find(f[u]));
			S.erase(S.find(*Son[a[a[u]]].begin() + e[a[a[u]]])), S.erase(S.find(*(--Son[a[a[u]]].end()) + e[a[a[u]]]));
			Son[a[a[u]]].erase(Son[a[a[u]]].find(f[a[u]]));
			S.erase(S.find(*Son[a[a[a[u]]]].begin() + e[a[a[a[u]]]])), S.erase(S.find(*(--Son[a[a[a[u]]]].end()) + e[a[a[a[u]]]]));
			Son[a[a[a[u]]]].erase(Son[a[a[a[u]]]].find(f[a[a[u]]]));
			f[a[u]] = f[a[u]] - e[a[u]] - e[u] - b[a[u]] % d[a[u]], f[a[a[u]]] -= e[a[u]];
			--d[a[u]], e[a[u]] = b[a[u]] / d[a[u]], f[a[u]] += e[a[u]] + b[a[u]] % d[a[u]], f[a[a[u]]] += e[a[u]];
//			printf("f[a[u]]=%d f[a[a[u]]]=%d d[a[u]]=%d e[a[u]]=%d\n", f[a[u]], f[a[a[u]]], d[a[u]], e[a[u]]);
			Son[a[a[u]]].insert(f[a[u]]);
			if (Son[a[u]].size()) S.insert(*Son[a[u]].begin() + e[a[u]]), S.insert(*(--Son[a[u]].end()) + e[a[u]]);
			S.insert(*Son[a[a[u]]].begin() + e[a[a[u]]]), S.insert(*(--Son[a[a[u]]].end()) + e[a[a[u]]]);
			Son[a[a[a[u]]]].insert(f[a[a[u]]]);
			S.insert(*Son[a[a[a[u]]]].begin() + e[a[a[a[u]]]]), S.insert(*(--Son[a[a[a[u]]]].end()) + e[a[a[a[u]]]]);
			a[u] = v;
			if (Son[a[u]].size()) S.erase(S.find(*Son[a[u]].begin() + e[a[u]])), S.erase(S.find(*(--Son[a[u]].end()) + e[a[u]]));
			Son[a[u]].insert(f[u]);
			S.erase(S.find(*Son[a[a[u]]].begin() + e[a[a[u]]])), S.erase(S.find(*(--Son[a[a[u]]].end()) + e[a[a[u]]]));
			Son[a[a[u]]].erase(Son[a[a[u]]].find(f[a[u]]));
			S.erase(S.find(*Son[a[a[a[u]]]].begin() + e[a[a[a[u]]]])), S.erase(S.find(*(--Son[a[a[a[u]]]].end()) + e[a[a[a[u]]]]));
			Son[a[a[a[u]]]].erase(Son[a[a[a[u]]]].find(f[a[a[u]]]));
			f[a[u]] = f[a[u]] - e[a[u]] - b[a[u]] % d[a[u]], f[a[a[u]]] -= e[a[u]];
			++d[a[u]], e[a[u]] = b[a[u]] / d[a[u]], f[a[u]] += e[u] + e[a[u]] + b[a[u]] % d[a[u]], f[a[a[u]]] += e[a[u]];
//			printf("f[a[u]]=%d f[a[a[u]]]=%d d[a[u]]=%d e[a[u]]=%d\n", f[a[u]], f[a[a[u]]], d[a[u]], e[a[u]]);
			Son[a[a[u]]].insert(f[a[u]]);
			S.insert(*Son[a[u]].begin() + e[a[u]]), S.insert(*(--Son[a[u]].end()) + e[a[u]]);
			S.insert(*Son[a[a[u]]].begin() + e[a[a[u]]]), S.insert(*(--Son[a[a[u]]].end()) + e[a[a[u]]]);
			Son[a[a[a[u]]]].insert(f[a[a[u]]]);
			S.insert(*Son[a[a[a[u]]]].begin() + e[a[a[a[u]]]]), S.insert(*(--Son[a[a[a[u]]]].end()) + e[a[a[a[u]]]]);
		}
		if (opt == 2){
			int u = read();
			printf("%lld\n", e[a[u]] + f[u]);
		}
		if (opt == 3) printf("%lld %lld\n", *S.begin(), *(--S.end()));
	}
}