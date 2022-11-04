#include <bits/stdc++.h>
#define M 50010
#define it map <ll, int>::iterator
#define int long long

using namespace std;

typedef long long ll;

map <ll, int> hsh;

ll n, S[M], K[M], P[M], tmp[M], T, Ans[M];

bool cmp(int x, int y) {return P[x] > P[y];}

void dec(int x) {if(hsh[x] == 1) hsh.erase(x); else hsh[x] = -1;}

int insert(int S, int K)
{
	ll tmp;
	it it1 = hsh.lower_bound(S);
	if(it1 != hsh.end() && it1->first == S && it1->second == 1) it1++;
	if(it1 == hsh.end() || it1->second == 1) {
		if(it1 == hsh.end() || it1->first - S >= K) return hsh[S] = 1, dec(S + K), S + K;
		else hsh[S] = 1, K -= it1->first - S, tmp = it1->first, it1++, hsh.erase(tmp);
	}
	for(; ; tmp = it1->first, it1++, hsh.erase(tmp)) {
		assert(it1->second == -1);
		tmp = it1->first, it1++, hsh.erase(tmp);
		if(it1 == hsh.end() || it1->first - tmp >= K) return dec(tmp + K), tmp + K; else K -= it1->first - tmp;
	}
}

ll check(int s, int t, int p)
{
	hsh.clear();
	for(int i = 2; i <= n && P[tmp[i]] > p; i++) insert(S[tmp[i]], K[tmp[i]]);
	return insert(s, t);
}

void getans(ll p)
{
	hsh.clear();
	printf("%lld\n", P[tmp[1]] = p);
	sort(tmp + 1, tmp + n + 1, cmp);
	for(int i = 1; i <= n; i++) Ans[tmp[i]] = insert(S[tmp[i]], K[tmp[i]]);
	for(int i = 1; i <= n; i++) printf("%lld ", Ans[i]);
	exit(putchar('\n') * 0);
}

#undef int
int main()
#define int long long
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &S[i], &K[i], &P[i]), P[i] = P[i] == -1 ? 2000000000 : P[i], tmp[i] = i;
	sort(tmp + 1, tmp + n + 1, cmp);
	scanf("%lld", &T);
	for(int l = 1, r = 1000000000; l <= r; ) {
		int md = (l + r) / 2;
		ll tp = check(S[tmp[1]], K[tmp[1]], md);
		if(tp == T) getans(md);
		else if(tp < T) r = md - 1; else l = md + 1;
	}
}