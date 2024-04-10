#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
typedef std :: vector< std :: vector<int> > mat;
typedef std :: vector<long long> vec;
int n, m;
mat a, b;
vec sa, sb;
long long ans;
vec get_sum(int n, int m, mat &a){
	vec sum(n);
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < m; ++j)
			sum[i] += a[i][j];
	return sum;
}
vec get_kmx(vec a, int k){
	int n = a.size();
	k = std :: min(k, n);
	for (register int i = 0; i < k; ++i){
		int mx = i;
		for (register int j = i + 1; j < n; ++j)
			if (a[mx] < a[j]) mx = j;
		if (mx > i) std :: swap(a[mx], a[i]);
	}
	a.resize(k);
	return a;
}
long long get_ksum(vec &a, int k){
	vec tmp = get_kmx(a, k);
	long long res = 0;
	for (register int i = 0; i < tmp.size(); ++i) res += tmp[i];
	return res;
}
long long select_3(int n, int m, mat &a, vec &sum){
	long long res = 0;
	for (register int k = 0; k < m; ++k){
		vec sum_t = sum;
		long long tmp = 0;
		for (register int i = 0; i < n; ++i) sum_t[i] -= a[i][k], tmp += a[i][k];
		res = std :: max(res, tmp + get_ksum(sum_t, 3));
	}
	return res;
}
long long select_2(int n, int m, mat &a, vec &sum){
	if (n == 1 || m == 1) return 0;
	long long res = 0;
	for (register int k1 = 0; k1 < m; ++k1)
		for (register int k2 = k1 + 1; k2 < m; ++k2){
			vec sum_t = sum;
			long long tmp = 0;
			for (register int i = 0; i < n; ++i)
				sum_t[i] -= a[i][k1] + a[i][k2], tmp += a[i][k1] + a[i][k2];
			res = std :: max(res, tmp + get_ksum(sum_t, 2));
		}
	return res;
}
int main(){
	n = read(), m = read();
	a.resize(n), b.resize(m);
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < m; ++j)
			a[i].push_back(read()), b[j].push_back(a[i][j]);
	sa = get_sum(n, m, a), sb = get_sum(m, n, b);
	ans = std :: max(get_ksum(sa, 4), get_ksum(sb, 4));
	ans = std :: max(ans, std :: max(select_3(n, m, a, sa), select_3(m, n, b, sb)));
	if (n >= m) ans = std :: max(ans, select_2(n, m, a, sa));
	else ans = std :: max(ans, select_2(m, n, b, sb));
	printf("%lld\n", ans);
}