#include <stdio.h>
#include <math.h>

int winning(int n, int k);
int expmod(long long int a, long long int b, int m);
const int mod = 1000000007;

int main () {
  int t;
  int n;
  int k;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &k);
    printf("%d\n", winning(n, k));
  }
}

int winning (int n, int k) {
  if (k == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    int a = expmod(2, n-1, mod) - 1;
    long long int b = expmod(2, (long long)(n)*k, mod) - expmod(a, k, mod);
    long long int c = expmod(a+2, mod-2, mod);
    int result = (expmod(a, k, mod) + b*c) % mod;
    if (result < 0) {
      result += mod;
    }
    return result;
  }
  else {
    return expmod(expmod(2, n-1, mod) + 1, k, mod);
  }
}

int expmod(long long int a, long long int b, int m)
{
	int res = 1;
	a = a % m; 

	if (a == 0) return 0;

	while (b > 0)
	{
		if (b & 1)
			res = (res*a) % m;

		b = b>>1;
		a = (a*a) % m;
	}
	return res;
}