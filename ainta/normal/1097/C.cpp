#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, A[501000], B[501000], C;
long long res;
char p[501000];
int main() {
	int i;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", p);
		int s = 0, Mn = 0;
		for (i = 0; p[i]; i++) {
			if (p[i] == '(')s++;
			else s--;
			Mn = min(Mn, s);
		}
		int L = i;
		if (Mn == 0 && s == 0)C++;
		else if (Mn == 0) {
			A[s]++;
		}
		else {
			s = 0, Mn = 0;
			for (i = L - 1; i >= 0; i--) {
				if (p[i] == ')')s++;
				else s--;
				Mn = min(Mn, s);
			}
			if (Mn == 0)B[s]++;
		}
	}
	
	for (i = 1; i <= 500000; i++)res += min(A[i], B[i]);
	res += C / 2;
	printf("%lld\n", res);
}