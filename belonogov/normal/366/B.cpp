#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 1e6;

int a[MAXN];
int b[MAXN];


int main(){
// 	freopen("in", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)
		for (int t = 0, j = i; t < (n + k - 1) / k; t++, j = (j + k) % n)
			b[i] += a[j];
	int cur = 0;
// 	for (int i = 0; i < k; i++)
// 		cerr << b[i] << endl;
	for (int i = 0; i < k; i++)
		if (b[cur] > b[i])
			cur = i;
	printf("%d\n", cur + 1);
	
	
	return 0;
}