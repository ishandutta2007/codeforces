#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n;
map<long long, int>Map;
void Do(int a) {
	int x = 1;
	long long res = 0;
	long long c = n / a;
	res = c*(c - 1) / 2 * a;
	res += c;
	Map[res] = 1;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			Do(i);
			Do(n / i);
		}
	}
	for (auto &t : Map)printf("%lld ", t.first);
}