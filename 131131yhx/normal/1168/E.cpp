#include <bits/stdc++.h>

using namespace std;

int k, A[1 << 12], B[1 << 12], Sym[1 << 12][2], Ans[1 << 12][2], sum = 0;

void Do(int a, int b, int s) {swap(Ans[a][s], Ans[b][s]), swap(Sym[Ans[a][s]][s], Sym[Ans[b][s]][s]);}

int main() {
	scanf("%d", &k);
	for(int i = 0; i < (1 << k); i++) scanf("%d", &A[i]), Ans[i][0] = (Ans[i][1] = (Sym[i][0] = (Sym[i][1] = i))), sum ^= A[i];
	if(sum) return puts("Fou"), 0;
	for(int i = 1; i < (1 << k); i++) if(A[i]) {
		B[0] ^= A[i], B[i] = A[i];
		int a = 0;
		while(Ans[a][0] ^ Ans[a][1] ^ B[a]) {
			int s = Sym[Ans[a][0] ^ B[a]][1];
			Do(a, s, 1), Do(i, s, 0), a = s;
		}
	}
	puts("Shi");
	for(int T = 0; T < 2; T++, putchar('\n'))
		for(int i = 0; i < (1 << k); i++) printf("%d ", Ans[i][T]);
}