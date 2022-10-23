# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n;
int p[NR];
int a[NR], b[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	int mk = 0;
	for (int i = 1; i <= n; i++){
		if (p[b[i]] <= mk) printf("0 ");
		else {
			printf("%d ", p[b[i]] - mk);
			mk = p[b[i]];
		}
	}
	putchar('\n');
	return 0;
}