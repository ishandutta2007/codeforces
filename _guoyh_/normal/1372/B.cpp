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
		int a = 1, b = n - 1;
		for (int i = 2; i * i <= n; i++){
			if (n % i == 0){
				a = n / i;
				b = n - a;
				break;
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}