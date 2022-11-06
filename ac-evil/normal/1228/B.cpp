#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)

inline int read() {
	int x;
	scanf("%d", &x);
	return x;
}

const int maxn = 1000 + 5;
const int MOD = 1000000007;

int N, M;
int r[maxn], c[maxn];

int ans = 0;

int pow(int a, int b) {
	int ans = 1;
	for (register int k = a; b; k = (ll)k*k%MOD, b >>= 1)
		if (b & 1) ans = (ll)ans*k%MOD;
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	rep(i, 1, N) r[i] = read();
	rep(i, 1, M) c[i] = read();
	rep(i, 1, N)
		rep(j, 1, M) {
			if (j > r[i]+1 && i > c[j]+1) ans++;
			if (j == r[i]+1 && i <= c[j] || i == c[j]+1 && j <= r[i]) {
				printf("0");
				return 0;
			}
		}

	printf("%d", pow(2, ans));
	return 0;
}