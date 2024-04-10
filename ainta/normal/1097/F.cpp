#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
bitset<7001>A[101000], PA[7010], U[7010];
int n, Q, C[7010];
vector<int>TP[7010], pr;
int main() {
	int i, j, ck, x, y, z;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= 7000; i++) {
		for(j=i;j<=7000;j+=i){
			PA[j][i] = 1;
			TP[j].push_back(i);
		}
	}
	C[1] = 1;
	for (i = 2; i <= 7000; i++) {
		if (TP[i].size() == 2) {
			C[i] = 1;
			pr.push_back(i);
			continue;
		}
		for (auto &t : pr) {
			if (i%t == 0) {
				if ((i / t) % t == 0)C[i] = 0;
				else C[i] = C[i/t];
				break;
			}
		}
	}
	for (i = 1; i <= 7000; i++) {
		for (j = 1; j <= 7000; j++) {
			if (i%j == 0) {
				if (C[i / j]) {
					U[j][i] = 1;
				}
			}
		}
	}
	while (Q--) {
		scanf("%d%d%d", &ck, &x, &y);
		if (ck == 1) {
			A[x] = PA[y];
			continue;
		}
		if (ck == 2) {
			scanf("%d", &z);
			A[x] = A[y] ^ A[z];
		}
		if (ck == 3) {
			scanf("%d", &z);
			A[x] = A[y]&A[z];
		}
		if (ck == 4) {
			printf("%d", (U[y] & A[x]).count()&1);
		}
	}
}