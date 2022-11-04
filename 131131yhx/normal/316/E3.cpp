#include <bits/stdc++.h>
#define P 1000000000
#define md (L + R >> 1)

typedef long long ll;

const int C = 262144;

using namespace std;

struct two
{
	ll A, B;
	two(){} two(ll a, ll b) {A = a, B = b;}
	void operator += (const two& X) {A = (A + X.A) % P, B = (B + X.B) % P;}
};

ll Tag[C * 2 + 10], fib[C * 2 + 10], S[C * 2 + 10], n, m, op, a, b, c, ans;

two K[C * 2 + 10];

ll fb(two s, ll x)
{
	if(x == 1) return s.A;
	if(x == 2) return s.B;
	return (s.A * fib[x - 2] + s.B * fib[x - 1]) % P;
}

void merge(two& A, two B, two C, int pos) {A = two((B.A + fb(C, pos)) % P, (B.B + fb(C, pos + 1)) % P);}

void pd(int x, int L, int R)
{
	if(!Tag[x]) return;
	Tag[x * 2] += Tag[x], Tag[x * 2 + 1] += Tag[x];
	two tmp = two(Tag[x] * S[R - md] % P, Tag[x] * (S[R - md + 1] - 1) % P);
	K[x * 2] += tmp, K[x * 2 + 1] += tmp, Tag[x] = 0;
}

void build(int x, int L, int R)
{
	if(L == R) {if(L <= n) scanf("%lld", &K[x].A), K[x].B = K[x].A; return;}
	build(x * 2, L, md), build(x * 2 + 1, md + 1, R);
	merge(K[x], K[x * 2], K[x * 2 + 1], md - L + 2);
}

void insert(int x, int L, int R, int l, int r, int v)
{
	if(l == L && r == R) {
		Tag[x] += v, K[x] += two(v * S[R - L + 1] % P, v * (S[R - L + 2] - 1) % P);
		return;
	}
	pd(x, L, R);
	if(l <= md) insert(x * 2, L, md, l, min(md, r), v);
	if(r > md) insert(x * 2 + 1, md + 1, R, max(md + 1, l), r, v);
	merge(K[x], K[x * 2], K[x * 2 + 1], md - L + 2);
}

void change(int x, int L, int R, int pos, int v)
{
	if(L == R) {K[x] = two(v, v); return;}
	pd(x, L, R);
	if(pos <= md) change(x * 2, L, md, pos, v); else change(x * 2 + 1, md + 1, R, pos, v);
	merge(K[x], K[x * 2], K[x * 2 + 1], md - L + 2);
}

void query(int x, int L, int R, int l, int r, int s)
{
	if(L == l && R == r) {ans = (ans + fb(K[x], L - s + 1)) % P; return;}
	pd(x, L, R);
	if(l <= md) query(x * 2, L, md, l, min(md, r), s);
	if(r > md) query(x * 2 + 1, md + 1, R, max(md + 1, l), r, s);
}

int main()
{
	fib[1] = fib[2] = S[1] = 1, S[2] = 2;
	for(int i = 3; i <= C; i++) fib[i] = (fib[i - 2] + fib[i - 1]) % P, S[i] = (S[i - 1] + fib[i]) % P;
	scanf("%lld%lld", &n, &m);
	build(1, 1, C);
	while(m--) {
		scanf("%lld%lld%lld", &op, &a, &b);
		if(op == 3) scanf("%lld", &c), insert(1, 1, C, a, b, c);
		else if(op == 1) change(1, 1, C, a, b);
		else ans = 0, query(1, 1, C, a, b, a), printf("%lld\n", ans);
	}
	return 0;
}