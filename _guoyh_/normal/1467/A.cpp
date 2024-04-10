# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		if (n == 1) printf("9\n");
		else {
			printf("98");
			for (int i = 3; i <= n; i++) printf("%d", (6 + i) % 10);
			putchar('\n');
		}
	}
	return 0;
}