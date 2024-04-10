#include<cstdio>
#include<algorithm>
#define N_ 201000
using namespace std;
int n, X[N_], w[N_], Q;
long long BIT[N_], SS[N_], BIT2[N_], Mod = 1000000007, BIT3[N_];
void Add(int a, long long x) {
	while (a <= n) {
		BIT[a] += x;
		a += (a&-a);
	}
}
long long Sum(int a) {
	long long r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
void Add2(int a, long long x) {
	while (a <= n) {
		BIT2[a] = (BIT2[a]+x)%Mod;
		a += (a&-a);
	}
}
long long Sum2(int a) {
	long long r = 0;
	while (a) {
		r += BIT2[a];
		a -= (a&-a);
	}
	return r%Mod;
}
void Add3(int a, long long x) {
	while (a <= n) {
		BIT3[a] = (BIT3[a] + x) % Mod;
		a += (a&-a);
	}
}
long long Sum3(int a) {
	long long r = 0;
	while (a) {
		r += BIT3[a];
		a -= (a&-a);
	}
	return r%Mod;
}
void Go(int b, int e) {
	long long G = Sum(e) - Sum(b - 1);
	long long BS = Sum(b - 1);
	int bb = b-1, ee = e, mid, r = 0;
	while (bb <= ee) {
		mid = (bb + ee) >> 1;
		if ((Sum(mid) - BS) * 2 <= G)r = mid, bb = mid + 1;
		else ee = mid - 1;
	}
	r++;
	long long bs = Sum(r) - Sum(b - 1);
	long long es = Sum(e) - Sum(r);
	long long res = bs % Mod * X[r] - (Sum2(r) - Sum2(b - 1));
	res += (Sum2(e) - Sum2(r)) - es % Mod * X[r] % Mod;
	res -= bs%Mod * r%Mod - (Sum3(r) - Sum3(b - 1));
	res -= (Sum3(e) - Sum3(r)) - es%Mod * r%Mod;
	res = (res + Mod * 100) % Mod;
	printf("%lld\n", res);
}
int main() {
	int i;
	scanf("%d%d", &n,&Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &X[i]);
		SS[i] = SS[i - 1] + X[i];
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Add(i, w[i]);
		Add2(i, 1ll * w[i] * X[i] % Mod);
		Add3(i, 1ll * w[i] * i % Mod);
	}
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < 0) {
			a = -a;
			Add(a, b - w[a]);
			Add2(a, 1ll * (b - w[a]+Mod)*X[a] % Mod);
			Add3(a, 1ll * (b - w[a] + Mod)*a%Mod);
			w[a] = b;
			continue;
		}
		Go(a, b);
	}
}