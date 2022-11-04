#include <bits/stdc++.h>

using namespace std;

const int M = 1 << 21;

struct Comp
{
	long double a, b;
	Comp(){} Comp(double A, double B) {a = A, b = B;}
	Comp operator + (const Comp& X) const {return Comp(a + X.a, b + X.b);}
	Comp operator - (const Comp& X) const {return Comp(a - X.a, b - X.b);}
	Comp operator * (const Comp& X) const {return Comp(a * X.a - b * X.b, a * X.b + b * X.a);}
};

int R[M], n, m, t = 1, x, sm = 0;

bool B[M];

Comp A[M], C[M];

void DFT()
{
	for(int b = 2, h = 1, k = t / 2; b <= t; b <<= 1, h <<= 1, k >>= 1)
		for(int i = 0; i < t; i += b)
			for(int j = i, Nw = 0; j < i + h; j++, Nw += k) {
				Comp tmp = A[j + h] * C[Nw];
				A[j + h] = A[j] - tmp, A[j] = A[j] + tmp;
			}
}

int main()
{
	scanf("%d%d", &n, &m);
	while(t <= m * 2) t <<= 1;
	C[0] = Comp(1, 0), C[1] = Comp(cos(2 * M_PI / t), sin(2 * M_PI / t));
	for(int i = 1; i < t; i++) R[i] = (R[i >> 1] >> 1) + (t >> 1) * (i & 1);
	for(int T = 1; T <= n; T++) scanf("%d", &x), B[x] = 1, A[R[x]] = Comp(1., 0.);
	for(int i = 2; i < t; i++) C[i] = C[1] * C[i - 1];
	DFT();
	for(int i = 0; i < t; i++) A[i] = A[i] * A[i];
	for(int i = 0; i < t; i++) if(i < R[i]) swap(A[i], A[R[i]]);
	reverse(C + 1, C + t);
	DFT();
	for(int i = 0; i <= m; i++)
		if(fabs(A[i].a) <= t / 2 && B[i]) sm++;
		else if(fabs(A[i].a) >= t / 2 && !B[i]) return puts("NO"), 0;
	printf("YES\n%d\n", sm);
	for(int i = 0; i <= m; i++)
		if(fabs(A[i].a) <= t / 2 && B[i]) printf("%d ", i);
	return putchar('\n'), 0;
}