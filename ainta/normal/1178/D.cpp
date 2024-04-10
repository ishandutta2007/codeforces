#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int Prime[2010];
struct Edge {
	int a, b;
};
vector<Edge>Ans;
void Add(int a, int b) {
	Ans.push_back({ a,b });
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 2; i <= 2000; i++) {
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)Prime[i] = 1;
	}
	for (i = 1; i <= n; i++) {
		Add(i, i%n + 1);
	}
	int pv1 = 1, pv2 = n / 2 + 1;
	for (i = n;; i++) {
		if (Prime[i])break;
		Add(pv1, pv2);
		pv1++, pv2++;
	}
	printf("%d\n", Ans.size());
	for (auto &t : Ans)printf("%d %d\n", t.a, t.b);
}