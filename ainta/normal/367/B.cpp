#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[400010], b[400010], p, C[400010];
int n, m, r, cnt[400010], mm;
bool v[400010];
struct A{
	int a, num;
	bool operator <(const A &p)const{
		return a < p.a;
	}
}w[400010];
int main()
{
	int i, t, c, tp, ct = 0;
	scanf("%d%d%d", &n, &m, &p);
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		w[i].num = i, w[i].a = a[i];
	}
	for (i = 1; i <= m; i++){
		scanf("%d", &b[i]);
		w[n + i].num = i + n, w[n + i].a = b[i];
	}
	sort(w + 1, w + n + m + 1);
	for (i = 1; i <= n + m; i++){
		if (i == 1 || w[i].a != w[i - 1].a)ct++;
		if (w[i].num <= n){
			a[w[i].num] = ct;
		}
		else{
			b[w[i].num - n] = ct;
		}
	}
	for (i = 1; i <= m; i++)C[b[i]]++;
	for (i = 1; i <= m; i++){
		if (!cnt[b[i]])mm++;
		cnt[b[i]] = C[b[i]];
	}
	for (i = 1; i <= p; i++){
		t = i - p;
		c = 0;
		r = 0;
		while (c < m && t <= n){
			c++;
			t += p;
			if (t > n)break;
			C[a[t]]--;
			if (C[a[t]] == 0) r++;
		}
		if (c == m){
			for (; t <= n; t += p){
				tp = t - p*(m - 1);
				if (r == mm){
					v[tp] = true;
				}
				if (t + p > n)break;
				C[a[tp]]++;
				if (C[a[tp]] == 1)r--;
				C[a[t + p]]--;
				if (C[a[t + p]] == 0)r++;
			}
		}
		for (t = i; t <= n; t += p){
			C[a[t]] = cnt[a[t]];
		}
	}
	int res = 0;
	for (i = 1; i <= n; i++){
		if (v[i])res++;
	}
	printf("%d\n", res);
	for (i = 1; i <= n; i++){
		if (v[i])printf("%d ", i);
	}
}