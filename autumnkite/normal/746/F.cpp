#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <set>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, w, k, a[200005], t[200005], ans;
std :: multiset<int> Sw, S;
int main(){
	n = read(), w = read(), k = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i) t[i] = read();
	for (register int l = 1, r = 1, T = 0, sum = 0; r <= n; ++r){
		Sw.insert(t[r]), T += t[r] + 1 >> 1, sum += a[r];
		if (Sw.size() > w) S.insert(*(Sw.begin())), T += *(Sw.begin()) >> 1, Sw.erase(Sw.begin());
		while (l <= r && T > k){
			if (t[l] < *(Sw.begin())) S.erase(S.find(t[l])), T -= t[l];
			else{
				Sw.erase(Sw.find(t[l])), T -= t[l] + 1 >> 1;
				if (!S.empty())
					Sw.insert(*(--S.end())), T -= *(--S.end()) >> 1, S.erase(--S.end());
			}
			sum -= a[l], ++l;
		}
		ans = std :: max(ans, sum);
	}
	printf("%d", ans);
	getchar(), getchar();
}