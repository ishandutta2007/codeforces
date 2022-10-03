#include <bits/stdc++.h>
using namespace std;

long long n, t, ans, a, tmp;

int main(){
	scanf("%lld", &n);
	while (n--){
		scanf("%lld", &a);
		ans+=(tmp=min(t, a/2));
		t-=tmp;
		ans+=(a-=2*tmp)/3;
		t+=a%3;
	}
	printf("%lld\n", ans);
	return 0;
}