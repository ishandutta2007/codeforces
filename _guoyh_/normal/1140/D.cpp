# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 505;
int n;
ll ans;
int main(){
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) ans += (ll)i * (i - 1);
	printf("%lld\n", ans);
	return 0;
}