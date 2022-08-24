#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, w[101000];
map<int, int>Map;
char p[1010000];
long long res;
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", p);
		int t = 0;
		for (j = 0; p[j]; j++) {
			t ^= 1 << (p[j] - 'a');
		}
		Map[t]++;
	}
	for (auto &t : Map) {
		int x = t.first, c = t.second;
		for (j = 0; j < 26; j++) {
			if((x^(1<<j)) > x && Map.count(x ^ (1 << j)))res += 1ll * c * Map[x ^ (1 << j)];
		}
		res += 1ll * c*(c - 1) / 2;
	}
	printf("%lld\n", res);
}