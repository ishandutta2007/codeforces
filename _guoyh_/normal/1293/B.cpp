# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n;
double ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		ans = ans + (double)1 / i;
	}
	printf("%f\n", ans);
	return 0;
}