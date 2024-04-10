# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int n, m;
int a[NR], b[NR];
int main(){
	scanf("%d%d", &n, &m);
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		s1 = s1 ^ a[i];
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", b + i);
		s2 = s2 ^ b[i];
	}
	if ((s1 ^ s2) != 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			printf("0 ");
		}
		printf("%d\n", a[i]);
	}
	for (int i = 1; i < m; i++) printf("%d ", b[i]);
	printf("%d\n", s1 ^ a[n] ^ b[m]);
	return 0;
}