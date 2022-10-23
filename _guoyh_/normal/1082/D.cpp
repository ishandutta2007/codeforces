# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 505;
int n, nm1, nm2, bsz;
int b[NR];
int a[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		if (a[i] == 1){
			b[++bsz] = i;
			nm1++;
		} else nm2 += a[i] - 2;
	}
	if (nm2 < nm1 - 2){
		printf("NO\n");
		return 0;
	}
	printf("YES %d\n", n - nm1 + min(2, nm1) - 1);
	printf("%d\n", n - 1);
	int l = (bsz >= 1) ? b[bsz--] : -1;
	for (int i = 1; i <= n; i++){
		if (a[i] == 1) continue;
		if (l != -1) printf("%d %d\n", l, i);
		for (int j = 1; j <= a[i] - 2 && bsz > 1; j++){
			printf("%d %d\n", i, b[bsz--]);
		}
		l = i;
	}
	if (bsz >= 1) printf("%d %d\n", l, b[bsz--]);
	return 0;
}