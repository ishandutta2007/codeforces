#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		if(n&1) printf("7");
		else printf("1");
		rep(i, n/2-1) printf("1");
		printf("\n");
	}
	return 0;
}