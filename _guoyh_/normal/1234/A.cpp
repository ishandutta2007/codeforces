# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int q;
int main(){
	scanf("%d", &q);
	while (q--){
		int n, s = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			s += a;
		}
		printf("%d\n", (s + n - 1) / n);
	}
	return 0;
}