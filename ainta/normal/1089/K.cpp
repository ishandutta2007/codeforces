#include<cstdio>
#include<algorithm>
#define SZ 1048576
using namespace std;
struct Tree {
	long long R[SZ + SZ], S[SZ + SZ];
	void Add(int a, int b) {
		a += SZ;
		S[a] += b;
		R[a] = S[a];
		while (a != 1) {
			a >>= 1;
			S[a] = S[a * 2] + S[a * 2 + 1];
			R[a] = max(R[a * 2 + 1], S[a * 2 + 1] + R[a * 2]);
		}
	}
	long long Get(int a) {
		int t = SZ + a, b = SZ;
		long long s = 0, r = R[t];
		while (t != 1) {
			if (!(t & 1)) {
				s += S[t];
				t = (t - 1) >> 1;
			}
			else t = t >> 1;
			b = b >> 1;
			if (t < b)break;
			r = max(r, R[t] + s);
		}
		return r;
	}
}T;
int U[310000][2];
int main() {
	//freopen("input.txt", "r", stdin);
	int Q, a, b, i;
	char p[3];
	for (i = 1; i <= 1000000; i++)T.Add(i, -1);
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%s", p);
		if (p[0] == '+') {
			scanf("%d%d", &a, &b);
			U[i][0] = a, U[i][1] = b;
			T.Add(a, b);
		}
		else if (p[0] == '-') {
			scanf("%d", &a);
			T.Add(U[a][0], -U[a][1]);
		}
		else {
			scanf("%d", &a);
			printf("%lld\n", T.Get(a) + 1);
		}
	}
}