# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n;
int a[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
		}
		bool flag;
		int b = 1;
		while (b <= n && a[b] == 1) b++;
		if (b == n + 1) flag = (n % 2 == 1);
		else flag = (b % 2 == 1);
		if (flag) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}