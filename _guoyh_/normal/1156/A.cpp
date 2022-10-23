# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int n;
int a[NR];
int main(){
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 2; i <= n; i++){
		if ((a[i] != 1 && a[i - 1] != 1) || (a[i] == 1 && a[i - 1] == 1)){
			printf("Infinite\n");
			return 0;
		}
		else if (max(a[i], a[i - 1]) == 2){
			if (a[i - 2] == 3) ans += 2;
			else ans += 3;
		} else {
			ans += 4;
		}
	}
	printf("Finite\n%d\n", ans);
	return 0;
}