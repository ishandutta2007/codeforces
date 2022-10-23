#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

namespace sa
{
	int n; 
	int dat[200005];
	int sa[200005], rk[200005], lcp[200005];
	PII tmp[400005];
	int cnt[200005], tsa[200005];
	
	void radix_sort(int md)
	{
		for(int i = 0; i <= md; i ++) cnt[i] = 0;
		for(int i = 0; i <= n; i ++) cnt[tmp[i].second] ++;
		rep1(i, md) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 0; i --) tsa[-- cnt[tmp[i].second]] = i;
	
		for(int i = 0; i <= md; i ++) cnt[i] = 0;
		for(int i = 0; i <= n; i ++) cnt[tmp[tsa[i]].first] ++;
		rep1(i, md) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 0; i --) sa[-- cnt[tmp[tsa[i]].first]] = tsa[i];
		
		rep1(i, n) rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i]] != tmp[sa[i - 1]]);
	}
	
	void gen_sa()
	{
		rep(i, n) tmp[i] = MP(dat[i], 1);
		tmp[n] = MP(0, 0);
		radix_sort(127);
		for(int d = 1; d <= n; d <<= 1) {
			for(int i = 0; i <= n; i ++) tmp[i] = MP(rk[i], rk[i + d]);
			radix_sort(n);
		}
	}
	
	void gen_lcp()
	{
		int h = 0;
		for(int i = 0; i <= n; i ++) {
			if(rk[i] == 0) continue;
			int j = sa[rk[i] - 1];
			if(h > 0) h --;
			while(i + h < n && j + h < n && dat[i + h] == dat[j + h]) h ++;
			lcp[rk[i]] = h;
		}
	}
}

int n, m;
char s[200005], t[200005];
int lcp[400005], bdr[200005];

int cnt[400005];

int main()
{
	scanf("%s%s", s, t);
	n = strlen(s);
	m = strlen(t);
	
	sa::n = n + m + 1;
	rep(i, n) sa::dat[i] = s[i];
	sa::dat[n] = '$';
	rep(i, m) sa::dat[n + 1 + i] = t[i];
	sa::gen_sa();
	sa::gen_lcp();
	
	lcp[n + 1] = INF;
	for(int i = sa::rk[n + 1]; i > 0; i --)
	lcp[sa::sa[i - 1]] = min(lcp[sa::sa[i]], sa::lcp[i]);
	for(int i = sa::rk[n + 1] + 1; i <= sa::n; i ++)
	lcp[sa::sa[i]] = min(lcp[sa::sa[i - 1]], sa::lcp[i]);
	
	bdr[0] = -1;
	for(int i = 1; i < m; i ++) {
		bdr[i] = bdr[i - 1];
		while(bdr[i] != -1 && t[i] != t[bdr[i] + 1])
		bdr[i] = bdr[bdr[i]];
		if(t[i] == t[bdr[i] + 1]) bdr[i] ++;
	}
	rep(i, m) cnt[bdr[i] == -1 ? n + m : i - bdr[i]] ++;
	for(int i = n + m - 1; i >= 0; i --) cnt[i] += cnt[i + 1];
	
	LL ans = 0;
	rep(i, n) ans += cnt[lcp[i + 1] + 1]; 
	printf("%I64d\n", ans);
	return 0; 
}