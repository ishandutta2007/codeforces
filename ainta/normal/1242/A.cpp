#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n;
vector<long long>V;
int main() {
	scanf("%lld", &n);
	long long i;
	for (i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			V.push_back(i);
			if (i*i != n)V.push_back(n / i);
		}
	}
	if (V.empty()) {
		printf("%lld\n", n);
		return 0;
	}
	sort(V.begin(), V.end());
	for (auto &t : V) {
		if (t%V[0]) {
			printf("1\n");
			return 0;
		}
	}
	printf("%lld\n", V[0]);
}