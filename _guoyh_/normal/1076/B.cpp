# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
ll n;
ll work(ll x){
	for (int i = 2; (ll)i * i <= x; i++){
		if (x % i == 0) return i;
	}
	return x;
}
int main(){
	scanf("%lld", &n);
	printf("%lld\n", (n - work(n)) / 2 + 1);
	return 0;
}