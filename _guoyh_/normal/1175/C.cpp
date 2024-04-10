# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int NR = 200051;
int t;
int n, k;
int a[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		int mi = 2e9, mn;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = k + 1; i <= n; i++){
			if ((a[i] - a[i - k] + 1) / 2 < mi){
				mi = (a[i] - a[i - k] + 1) / 2;
				mn = (a[i] + a[i - k]) / 2;
			}
		}
		printf("%d\n", mn);
	}
	return 0;
}