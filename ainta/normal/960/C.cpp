#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int X, d;
vector<long long>V;
int main() {
	int i;
	long long pv = 1;
	scanf("%d%d", &X, &d);
	while (X) {
		int t = 0, c = 0;
		while (t * 2 + 1 <= X)t = t * 2 + 1, c++;
		X -= t;
		for (i = 0; i < c; i++)V.push_back(pv);
		pv += d + 1;
	}
	printf("%d\n", V.size());
	for (i = 0; i < V.size(); i++)printf("%lld ", V[i]);
}