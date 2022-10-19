#include <bits/stdc++.h>
using namespace std;

int n ;
int d[(int)(1e5)+10] ;

int main(void) {

	scanf("%d",&n) ;
	int flag = 0, ans ;
	for(int i=0; i<n; i++) {
		scanf("%d",&d[i]) ;
	}
	sort(d,d+n) ;
	if(n==2) ans = 0 ;
	else {
		ans = min(d[n-2]-d[0],d[n-1]-d[1]) ;
	}
	printf("%d\n",ans) ;
	
	return 0 ;
	
}