#include <cstdio>
using namespace std;

typedef long long ll;

const int MAX = 105;

ll f[MAX];

int main() {
	ll N;
	scanf("%lld", &N);
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < MAX; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 0; i < MAX; i++)
		if (f[i] > N) {
			printf("%d\n", i - 1);
			break;
		}
	return 0;
}