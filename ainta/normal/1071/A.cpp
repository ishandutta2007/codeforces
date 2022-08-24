#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m;
vector<int>A, B;
int main() {
	int i;
	scanf("%lld%lld", &n, &m);
	for (i = 1;; i++) {
		if (1ll* i*(i + 1) / 2 > n + m)break;
	}
	int M = i - 1;
	for (i = M; i >= 1; i--) {
		if (n >= i) {
			A.push_back(i);
			n -= i;
		}
		else {
			B.push_back(i);
			m -= i;
		}
	}
	printf("%d\n", A.size());
	for (auto &t : A)printf("%d ", t);
	printf("\n%d\n", B.size());
	for (auto &t : B)printf("%d ", t);
	
}