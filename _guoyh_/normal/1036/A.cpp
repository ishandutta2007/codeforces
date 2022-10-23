# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
ll n, k;
int main(){
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", (k + n - 1) / n);
	return 0;
}