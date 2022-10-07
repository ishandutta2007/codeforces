#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int n, m, k, b[N];
long long ans;
struct node{
	int val, id;
	bool operator < (const node &res) const {
		return val > res.val;
	}
}a[N];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (register int i = 1; i <= n; ++i)
		scanf("%d", &a[i].val), a[i].id = i;
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= m * k; ++i) b[a[i].id] = 1, ans += a[i].val;
	printf("%lld\n", ans);
	int s = 0;
	for (register int i = 1; i <= n; ++i){
		if (b[i]) ++s;
		if (k > 1 && s == m) --k, printf("%d ", i), s = 0;
	}
}