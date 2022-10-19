#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1000005;
const int MAXL = 5005;

int N, M, P;
int l[MAXN];
int dp[MAXL][2];
int f[MAXL][MAXL];
int choose[MAXL];
vector <int> primes;
int exp[10];
int prod = 1;
int phi;

void load() {
	scanf("%d%d%d", &N, &M, &P);
	for (int i = 1; i <= N; i++)
		scanf("%d", l + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= P)
		x -= P;
	else if (x < 0)
		x += P;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % P;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int inv(int x) {
	return pot(x, phi - 1);
}

void update(int x, int val) {
	for (int i = 0; i < primes.size(); i++)
		for (; !(x % primes[i]); x /= primes[i])
			exp[i] += val;
	
	if (val == -1)
		x = inv(x);
	prod = mul(prod, x);
}

int get() {
	int res = prod;
	for (int i = 0; i < primes.size(); i++)
		res = mul(res, pot(primes[i], exp[i]));
	return res;
}

void factor(int x) {
	phi = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		while (!(x % i))
			x /= i;
		primes.push_back(i);
		phi = phi / i * (i - 1);
	}
	if (x > 1) {
		primes.push_back(x);
		phi = phi / x * (x - 1);
	}
}

int solve() {
	f[0][0] = 1;
	for (int l = 1; l < MAXL; l++)
		for (int k = 1; k <= l; k++)
			f[k][l] = add(mul(k - 1, f[k][l - 1]), mul(k, f[k - 1][l - 1]));
	
	factor(P);
	
	for (int i = 1; i <= M && i < MAXL; i++) {
		update(M - i + 1, 1);
		update(i, -1);
		choose[i] = get();
	}
	
	int sum = 1, c = 0;
	for (int i = 1; i <= N; i++) {
		c ^= 1;
		for (int j = 1; j <= l[i]; j++)
			dp[j][c] = mul(f[j][l[i]], add(sum, j > l[i - 1] ? 0 : -dp[j][c ^ 1]));
		sum = 0;
		for (int j = 1; j <= l[i]; j++)
			sum = add(sum, mul(choose[j], dp[j][c]));
	}
	
	return sum;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}