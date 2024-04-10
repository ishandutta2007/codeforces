#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char A[100] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char B[100] = "What are you doing while sending ";
char C[100] = "? Are you busy? Will you send ";
char D[100] = "?";
long long L[110000];
char Do(int a, long long t) {
	if (a == 1) {
		return A[t - 1];
	}
	if (t <= strlen(B))return B[t - 1];
	t -= strlen(B);
	if (t == 1)return '\"';
	t--;
	if (t <= L[a - 1])return Do(a - 1, t);
	t -= L[a - 1];
	if (t == 1)return '\"';
	t--;
	if (t <= strlen(C))return C[t - 1];
	t -= strlen(C);
	if (t == 1)return '\"';
	t--;
	if (t <= L[a - 1])return Do(a - 1, t);
	t -= L[a - 1];
	if (t == 1)return '\"';
	t--;
	return '?';
}
int main() {
	int Q, n, i;
	long long K;
	scanf("%d", &Q);
	L[1] = strlen(A);
	for (i = 2;i<103000; i++) {
		L[i] = (L[i - 1] + 2) * 2 + strlen(B) + strlen(C) + strlen(D);
		if (L[i] > 2e18) {
			L[i] = 2e18;
		}
	}
	while (Q--) {
		scanf("%d%lld", &n, &K);
		n++;
		if (L[n] < K) {
			printf(".");
		}
		else {
			printf("%c",Do(n, K));
		}
	}
}