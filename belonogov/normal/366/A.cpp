#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 1e6;

int x[MAXN];
int y[MAXN];


int main(){
// 	freopen("in", "r", stdin);
	int n, a, b, c, d, j;
	cin >> n;
	for (int i = 0; i < 4; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		x[i] = min(a, b);
		y[i] = min(c, d);
	}
	j = 0;
	for (int i = 0; i < 4; i++)
		if (x[i] + y[i] < x[j] + y[j])
			j = i;
	if (x[j] + y[j] > n)
		printf("-1\n");
	else
		printf("%d %d %d\n", j + 1, x[j], n - x[j]);
	return 0;
}