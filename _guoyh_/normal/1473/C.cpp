# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n, k;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		for (int i = 1; i < k - (n - k); i++) printf("%d ", i);
		for (int i = 0; i <= n - k; i++) printf("%d ", k - i);
		putchar('\n');
	}
	return 0;
}//