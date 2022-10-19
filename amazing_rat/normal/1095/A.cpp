#include <bits/stdc++.h>
using namespace std;

int n ;
char str[1000] ;

int main(void) {
	
	scanf("%d",&n) ;
	scanf("%s",str) ;
	int loc = 0 , t = 1 ;
	while(loc<n) {
		printf("%c",str[loc]) ;
		loc += t ;
		t += 1 ;
	}	
	printf("\n") ;
	
	return 0 ;
}