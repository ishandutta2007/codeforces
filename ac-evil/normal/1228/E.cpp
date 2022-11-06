#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= b; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

namespace io {
    inline int read() {
        int w = 0, f = 1; char c;
        while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
        while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
        return w * f;
    }
}

using io::read;

const int MOD = 1000000007;

int N, K;

int pow(int a, int b) {
	int ans = 1;
	for (register int k = a; b; k = (ll)k*k % MOD, b >>= 1)
		if (b & 1) ans = (ll)ans * k % MOD;
	return ans;
}

#define inv(v) pow(v, MOD-2)

int C[300];

int main() {
	N = read(), K = read();

	C[0] = 1;
	rep(i, 1, N) C[i] = (ll)C[i-1] * (N-i+1) % MOD * inv(i) % MOD;
	
	int tot = 0;

	rep(i, 0, N)
		rep(j, 0, N) {
			int opt = (i+j) & 1 ? -1 : 1, one = i*N+j*N-i*j;
			tot = ((ll)tot + MOD + opt*((ll)C[i]*C[j]%MOD*pow(K-1, one)%MOD*pow(K, N*N-one)%MOD)) % MOD;
		}

	printf("%d", tot);

    return 0;
}