#include <bits/stdc++.h>

using namespace std ;

int main(void) {
	int w, h, k;
    scanf("%d%d%d",&w,&h,&k) ;
    long long ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += 2 * (w - (4 * (i - 1)) ) + 2 * (h - 4 * (i - 1)) - 4;
    }
    printf("%lld\n",ans) ;
	return 0 ;
}